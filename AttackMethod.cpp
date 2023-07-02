#include "./AttackMethod.hpp"

void AttackMethod :: setParams(std::string const name, ElementalAttributeList const element, int const power) {
    this->name = name;
    this->element = element;
    this->power = power;
}

void AttackMethod :: action(Character& attacker, Character& target) {
    target.damagedBy(attacker);
}
