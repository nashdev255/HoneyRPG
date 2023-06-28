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
        AttackMethod(std::string name, ElementalAttributeList element, int power);
        virtual ~AttackMethod() {};

        void setParams(std::string name, ElementalAttributeList element, int power);
        void action(Character& attacker, Character& target);

        // getter, setter
        std::string getName();
        void setName(std::string name);
        ElementalAttributeList getElement();
        void setElement(ElementalAttributeList element);
        int getPower();
        void setPower(int power);

};

inline AttackMethod :: AttackMethod(std::string const name, ElementalAttributeList const element, int const power) {
    this->name = name;
    this->element = element;
    this->power = power;
}

inline std::string AttackMethod :: getName() {
    return this->name;
}

inline void AttackMethod :: setName(std::string const name) {
    this->name = name;
}

inline ElementalAttributeList AttackMethod :: getElement() {
    return this->element;
}

inline void AttackMethod :: setElement(ElementalAttributeList const element) {
    this->element = element;
}

inline int AttackMethod :: getPower() {
    return this->power;
}

inline void AttackMethod :: setPower(int const power) {
    this->power = power;
}
