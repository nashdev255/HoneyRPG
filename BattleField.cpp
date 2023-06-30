#include "BattleField.hpp"

void BattleField :: showBattleFieldStatus() {
    std::cout << "<BattleFieldStatus>" << std::endl;
    std::cout << "FGIHTER : " << this->fighter->getName() << std::endl;
    std::cout << "MONSTER : " << this->monster->getName() << std::endl;
    std::cout << std::endl;
}

void BattleField :: initBattleField() {
    this->initTurn();
    this->cycleTurn();
}

void BattleField :: cycleTurn() {
    this->fighter->showStatus();
    this->monster->showStatus();
    this->startTurn();
    this->switchTurn();

    if(this->canEndBattle()) {
        this->endBattle();
        return;
    }
    
    this->cycleTurn();
}

void BattleField :: initTurn() {
    int fighterSpd = this->fighter->getSpd();
    int monsterSpd = this->monster->getSpd();

    if(fighterSpd == monsterSpd) {
        // set turn randomly if both spds are the same
        this->isFighterTurn = GeneralMethod::generateRandomSeed(0, 1);

    } else if(monsterSpd < fighterSpd) {
        this->isFighterTurn = true;
    } else if(fighterSpd < monsterSpd) {
        this->isFighterTurn = false;
    }

}

void BattleField :: startTurn() {
    if(this->isFighterTurn) {
        this->fighter->selectAttack(*(this->monster));
    } else {
        this->monster->randomAttack(*(this->fighter));
    }
}

void BattleField :: switchTurn() {
    this->isFighterTurn = !(this->isFighterTurn);
}

void BattleField :: endBattle() {
    if(this->isVictory()) {
        this->win();
    } else {
        this->lose();
    }
}

bool BattleField :: canEndBattle() {
    if(this->fighter->isAlive() == false || this->monster->isAlive() == false) return true;
    std::cout << "debug" << std::endl;
    return false;
}

bool BattleField :: isVictory() {
    if(this->fighter->isAlive() && this->monster->isAlive() == false) {
        return true;
    }
    return false;
}

void BattleField :: win() {
    std::cout << "you win!!!" << std::endl;
    // provide exp for fighter
    this->fighter->updateReqExp();
}

void BattleField :: lose() {
    std::cout << "you lose..." << std::endl;
}
