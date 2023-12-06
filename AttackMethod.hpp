#pragma once
#include <string>
#include "./ElementalAttribute.hpp"
#include "./Character.hpp"

class Character;

class AttackMethod {
    private:
        std::string name;
        ElementalAttributeList element;
        int power;

    public:
        AttackMethod() {};
        AttackMethod(std::string& name, ElementalAttributeList element, int power);
        virtual ~AttackMethod() {};

        void setParams(std::string& name, ElementalAttributeList element, int power);
        void action(Character& attacker, Character& target);

        // getter, setter
        std::string getName() { return name; }
        ElementalAttributeList getElement() { return element; }
        int getPower() { return power; }

};
