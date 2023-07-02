#include "BattleField.hpp"

void BattleField :: showBattleFieldStatus() {
    std::cout << "<BattleFieldStatus>" << std::endl;
    std::cout << "FGIHTER : " << fighter->getName() << std::endl;
    std::cout << "MONSTER : " << monster->getName() << std::endl;
    std::cout << std::endl;
}

void BattleField :: initBattleField() {
    initTurn();
    cycleTurn();
}

void BattleField :: cycleTurn() {
    fighter->showStatus();
    monster->showStatus();
    startTurn();
    switchTurn();

    if(canEndBattle()) {
        endBattle();
        return;
    }
    
    cycleTurn();
}

void BattleField :: initTurn() {
    int fighterSpd = fighter->getSpd();
    int monsterSpd = monster->getSpd();

    if(fighterSpd == monsterSpd) {
        // 両者が同じ速さだった場合にランダムにターンを決定する
        isFighterTurn = GeneralMethod::generateRandomSeed(0, 1);

    } else if(monsterSpd < fighterSpd) {
        isFighterTurn = true;
    } else if(fighterSpd < monsterSpd) {
        isFighterTurn = false;
    }

}

void BattleField :: startTurn() {
    if(isFighterTurn) {
        fighter->attack(*monster);
    } else {
        monster->randomAttack(*fighter);
    }
}

void BattleField :: switchTurn() {
    isFighterTurn = !(isFighterTurn);
}

void BattleField :: endBattle() {
    if(isVictory()) {
        win();
    } else {
        lose();
    }
}

bool BattleField :: canEndBattle() {
    if(fighter->isAlive() == false || monster->isAlive() == false) return true;
    std::cout << "debug" << std::endl;
    return false;
}

bool BattleField :: isVictory() {
    if(fighter->isAlive() && monster->isAlive() == false) {
        return true;
    }
    return false;
}

void BattleField :: win() {
    std::cout << "you win!!!" << std::endl;
    // provide exp for fighter
    fighter->earnExpFromEnemy(monster->getDropExpAmount());
    fighter->updateLevel();
}

void BattleField :: lose() {
    std::cout << "you lose..." << std::endl;
}
