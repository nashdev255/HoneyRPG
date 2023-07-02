#include "./AttackMethod.hpp"

inline AttackMethod :: AttackMethod(std::string const name, ElementalAttributeList const element, int const power) : name(name), element(element), power(power) {}

void AttackMethod :: setParams(std::string const name, ElementalAttributeList const element, int const power) {
    this->name = name;
    this->element = element;
    this->power = power;
}

void AttackMethod :: action(Character& attacker, Character& target) {
    target.damagedBy(attacker);
}
