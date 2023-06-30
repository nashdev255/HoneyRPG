#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "./ElementalAttribute.hpp"
#include "./AttackMethod.hpp"
#include "./InvalidValueException.hpp"

class Character {
    protected:
        std::string name;
        ElementalAttribute elementalAttribute;

        int hp, maxhp, atk, def, spd;

        int level;
        int maxLevel = 100;
        int exp, reqExp;

        std::vector<AttackMethod> attackMethod;
        AttackMethod selectedAttackMethod;
    
    private:
        double calcDamageMagnification(Character attacker);
        int calcReqExpAmount();
        std::string coloredHp();

    public:
        Character() {};
        Character(std::string name, ElementalAttribute element, int maxhp, int atk, int def, int spd);
        virtual ~Character() {};

        void showStatus();

        virtual void damaged(Character attacker);
        virtual void damagedMessage(int const damagePoint) {};
        void dead();
        virtual void deadMessage() {};

        // level-related
        void earnExpFromEnemy(int dropExpAmount);
        virtual void updateReqExp();
        void updateExp();
        void updateLevel();
        void levelUp();

        // getter, setter
        std::string getName();
        void setName(std::string name);
        ElementalAttribute getElementalAttribute();
        void setElementalAttribute(ElementalAttribute element);

        int getHp();
        void setHp(int hp);
        int getAtk();
        void setAtk(int atk);
        int getDef();
        void setDef(int def);
        int getSpd();
        void setSpd(int spd);
        bool isAlive();

        int getLevel();
        void setLevel(int level);
        int getExp();
        void setExp(int exp);
        int getReqExp();
        void setReqExp(int reqExp);

        std::vector<AttackMethod> getAttackMethod();
        void setAttackMethod(std::vector<AttackMethod> attackMethod);
        AttackMethod getSelectedAttackMethod();
        void setSelectedAttackMethod(AttackMethod selectedAttackMethod);

};

inline Character :: Character(std::string const name, ElementalAttribute const elementalAttribute, int const maxhp, int const atk, int const def, int const spd) {
    // Exceptions handling
    if(maxhp < 0) throw InvalidValueException();
    if(atk < 0) throw InvalidValueException();
    if(def < 0) throw InvalidValueException();
    if(spd < 0) throw InvalidValueException();

    // initialize field
    this->name = name;
    this->elementalAttribute = elementalAttribute;

    this->maxhp = maxhp;
    this->hp = this->maxhp;
    this->atk = atk;
    this->def = def;
    this->spd = spd;

    this->level = 1;
    this->exp = 0;
    this->updateReqExp();

    attackMethod.resize(4);
}

inline std::string Character :: getName() {
    return this->name;
}

inline void Character :: setName(std::string name) {
    this->name = name;
}

inline ElementalAttribute Character :: getElementalAttribute() {
    return this->elementalAttribute;
}

inline void Character :: setElementalAttribute(ElementalAttribute elementalAttribute) {
    this->elementalAttribute = elementalAttribute;
}

inline int Character :: getHp() {
    return this->hp;
}

inline void Character :: setHp(int const hp) {
    this->hp = hp;
}

inline int Character :: getAtk() {
    return this->atk;
}

inline void Character :: setAtk(int const atk) {
    this->atk = atk;
}

inline int Character :: getDef() {
    return this->def;
}

inline void Character :: setDef(int const def) {
    this->def = def;
}

inline int Character :: getSpd() {
    return this->spd;
}

inline void Character :: setSpd(int const spd) {
    this->spd = spd;
}

inline int Character :: getLevel() {
    return this->level;
}

inline void Character :: setLevel(int const level) {
    this->level = level;
}

inline int Character :: getExp() {
    return this->exp;
}

inline void Character :: setExp(int const exp) {
    this->exp = exp;
}

inline int Character :: getReqExp() {
    return this->reqExp;
}

inline void Character :: setReqExp(int const reqExp) {
    this->reqExp = reqExp;
}

inline AttackMethod Character :: getSelectedAttackMethod() {
    return this->selectedAttackMethod;
}

inline void Character :: setSelectedAttackMethod(AttackMethod selectedAttackMethod) {
    this->selectedAttackMethod = selectedAttackMethod;
}

inline bool Character :: isAlive() {
    return this->hp != 0;
}
