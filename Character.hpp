#pragma once
#include <string>
#include <vector>
#include "./ElementalAttribute.hpp"
#include "./AttackMethod.hpp"

class Character {
    protected:
        std::string name;
        ElementalAttribute elementalAttribute;

        int hp, maxhp, atk, def, spd;

        int level;
        int maxLevel = 100;

        std::vector<AttackMethod> attackMethod;
        AttackMethod selectedAttackMethod;
    
    private:
        double calcDamageMagnification(Character& attacker);
        std::string colorHp();

    public:
        Character() {};
        Character(std::string name, ElementalAttribute element, int maxhp, int atk, int def, int spd);
        virtual ~Character() {};

        void showStatus();

        virtual void damagedBy(Character& attacker);
        virtual void damagedMessage(int const damagePoint) {};
        void dead();
        virtual void deadMessage() {};

        // getter, setter
        std::string getName() { return name; }
        ElementalAttribute getElementalAttribute() { return elementalAttribute; }
        int getHp() { return hp; }
        int getAtk() { return atk; }
        int getDef() { return def; }
        int getSpd() { return spd; }
        int getLevel() { return level; }

        bool isAlive() { return hp != 0; }

        std::vector<AttackMethod> getAttackMethod();
        AttackMethod getSelectedAttackMethod();

};
