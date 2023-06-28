#pragma once
#include "./Character.hpp"

void Character :: showStatus() {
    std::cout << "<Status>" << std::endl;
    std::cout << "NAME : " << this->name << std::endl;
    std::cout << "LEVEL : " << this->level << std::endl;
    std::cout << "ELEMENT : " << this->elementalAttribute.getElementAsString(this->elementalAttribute.getElement()) << std::endl;
    std::cout << "HP : " << this->hp << '/' << this->maxhp << std::endl;
    std::cout << "ATK : " << this->atk << std::endl;
    std::cout << "DEF : " << this->def << std::endl;
    std::cout << "SPD : " << this->spd << std::endl;
    std::cout << std::endl;
}

void Character :: damaged(Character attacker) {
    const int baseDamageAmount = attacker.getSelectedAttackMethod().getPower();
    const double damageMagnification = calcDamageMagnification(attacker);
    const int totalDamageAmount = baseDamageAmount * damageMagnification;

    this->hp -= totalDamageAmount;
    this->damagedMessage(totalDamageAmount);

    if(0 < this->hp) return;
    this->dead();
}

double Character :: calcDamageMagnification(Character attacker) {
    const ElementalReaction elementalReaction = this->elementalAttribute.ElementalReact(attacker.getSelectedAttackMethod().getElement());
    if(elementalReaction == NoneReact) { std::cout << "debug" << std::endl; return 1.0; } 
    if(elementalReaction == Saturate) return 0.5;
    return 1.8;
}

void Character :: dead() {
    this->hp = 0;
    this->deadMessage();
}

void Character :: updateReqExp() {
    this->reqExp = calcReqExpAmount();
}

int Character :: calcReqExpAmount() {
    const int totalReqExpAmount = this->level*100;
    return totalReqExpAmount;
}
