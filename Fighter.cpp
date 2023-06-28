#include "Fighter.hpp"

void Fighter :: initAttackMethod() {
    int power = this->atk;
    this->attackMethod[0].setParams("punchAttack", ElementalAttributeList::None, power);
    this->attackMethod[1].setParams("kickAttack", ElementalAttributeList::None, power*1.5);
    this->attackMethod[2].setParams("elementalAttack", this->elementalAttribute.getElement(), power*0.8);
    this->attackMethod[3].setParams("elementalStorm", this->elementalAttribute.getElement(), power*2);
}

void Fighter :: selectAttack(Monster& monster) {
    std::cout << "Select How to " << this->name << " attack." << std::endl;
    std::cout << "<methods>" << std::endl;
    // display ways how fighter can attack
    for(int i=0;i<this->attackMethod.size();i++) {
        std::cout << i+1 << " : " << this->attackMethod[i].getName() << std::endl;
    }
    
    std::cout << "> ";
    int method = this->attackMethod.size()+1;
    while(this->attackMethod.size() < method) {
        std::cin >> method;
        if(this->attackMethod.size() < method) {
            std::cout << "Select How to " << this->name << " attack." << std::endl;
            std::cout << "> ";
        }
    }
    method--;

    this->selectedAttackMethod = this->attackMethod[method];

    std::cout << this->name << "'s " << this->selectedAttackMethod.getName() << "!!!" << std::endl;
    selectedAttackMethod.action(*this, monster);
}

void Fighter :: damagedMessage(int const damagePoint) {
    std::cout << this->name << " took " << damagePoint << " points of damage." << std::endl;
}

void Fighter :: deadMessage() {
    std::cout << this->name << " has ran out of energy..." << std::endl;
}
