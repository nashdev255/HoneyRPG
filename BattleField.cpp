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
    if(this->fighter->isAlive() == false || this->monster->isAlive() == false) {
        this->endBattleMessage();
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
    this->endBattleMessage();
    if(this->fighter->isAlive() == false ) this->gameOver();
    this->win();
}

void BattleField :: endBattleMessage() {
    if(this->fighter->isAlive() == false) {
        std::cout << "you lose..." << std::endl;
        return;
    }
    if(this->monster->isAlive() == false) {
        std::cout << "you win!!!" << std::endl;
        return;
    }
}
