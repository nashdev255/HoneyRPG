#include "Monster.hpp"

void Monster :: initAttackMethod() {
    int power = this->atk;
    this->attackMethod[0].setParams("normalAttack", ElementalAttributeList::None, power);
    this->attackMethod[1].setParams("chargeAttack", ElementalAttributeList::None, power*1.5);
    this->attackMethod[2].setParams("elementalAttack", this->elementalAttribute.getElement(), power*0.8);
    this->attackMethod[3].setParams("elementalStorm", this->elementalAttribute.getElement(), power*2);
}

void Monster :: randomAttack(Fighter& fighter) {
    int randomSeed = GeneralMethod::generateRandomSeed(0, 3);
    selectedAttackMethod = this->attackMethod[randomSeed];
    std::cout << randomSeed << std::endl;
    
    std::cout << this->name << "'s " << selectedAttackMethod.getName() << "!!!" << std::endl;
    selectedAttackMethod.action(*this, fighter);
}

void Monster :: damagedMessage(int const damagePoint) {
    std::cout << "dealt " << damagePoint << " damage to " << this->name << std::endl;
}

void Monster :: deadMessage() {
    std::cout << this->name << " fainted!!!" << std::endl;
}
