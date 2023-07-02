#pragma once
#include "./Character.hpp"
#include "./InvalidValueException.hpp"

Character :: Character(std::string const name, ElementalAttribute const elementalAttribute, int const maxhp, int const atk, int const def, int const spd) : name(name), elementalAttribute(elementalAttribute), maxhp(maxhp), atk(atk), def(def), spd(spd) {
    // Exceptions handling
    if(maxhp < 0) throw InvalidValueException();
    if(atk < 0) throw InvalidValueException();
    if(def < 0) throw InvalidValueException();
    if(spd < 0) throw InvalidValueException();

    this->hp = this->maxhp;
    this->level = 1;

    attackMethod.resize(4);
}

void Character :: showStatus() {
    std::string elementName = elementalAttribute.getElementAsString(this->elementalAttribute.getElement());
    std::string coloredHp = colorHp();
    std::cout << "<Status>" << std::endl;
    std::cout << "NAME : " << name << std::endl;
    std::cout << "LEVEL : " << level << std::endl;
    std::cout << "ELEMENT : " << elementName << std::endl;
    std::cout << "HP : " << coloredHp << '/' << maxhp << std::endl;
    std::cout << "ATK : " << atk << std::endl;
    std::cout << "DEF : " << def << std::endl;
    std::cout << "SPD : " << spd << std::endl;
    std::cout << std::endl;
}

void Character :: damagedBy(Character attacker) {
    const int baseDamageAmount = attacker.getSelectedAttackMethod().getPower();
    const double damageMagnification = calcDamageMagnification(attacker);
    const int totalDamageAmount = baseDamageAmount * damageMagnification;

    hp = hp - totalDamageAmount;
    this->damagedMessage(totalDamageAmount);

    if(0 < this->hp) return;
    this->dead();
}

double Character :: calcDamageMagnification(Character attacker) {
    const double reactDamageMagnification     = 1.8;
    const double noneReactDamageMagnification = 1.0;
    const double saturateDamageMagnification  = 0.5;

    const ElementalAttributeList attackerAttackElement = attacker.getSelectedAttackMethod().getElement();
    const ElementalReaction elementalReaction = this->elementalAttribute.ElementalReact(attackerAttackElement);
    
    if(elementalReaction == NoneReact) return noneReactDamageMagnification; 
    if(elementalReaction == Saturate) return saturateDamageMagnification;
    return reactDamageMagnification;
}

std::string Character :: colorHp() {
    const double redRatio = 0.2;
    const double yellowRatio = 0.5;
    // default green

    const double restHpRatio = double(this->hp) / double(this->maxhp);

    std::string coloredHp = "\x1b[38;2;127;255;0m" + std::to_string(this->hp) + "\x1b[m";

    if(restHpRatio < redRatio) {
        coloredHp = "\x1b[38;2;255;69;0m" + std::to_string(this->hp) + "\x1b[m";
    } else if(restHpRatio < yellowRatio) {
        coloredHp = "\x1b[38;2;255;255;205m"  + std::to_string(this->hp) + "\x1b[m";
    }

    return coloredHp;
}

void Character :: dead() {
    this->hp = 0;
    this->deadMessage();
}
