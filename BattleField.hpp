#pragma once
#include "./GeneralMethod.hpp"
#include "./Fighter.hpp"
#include "./Monster.hpp"

class BattleField {
    private:
        Fighter* fighter;
        Monster* monster;

        bool isFighterTurn;

    private:
        void initBattleField();

        // turn-manager
        void initTurn();
        void cycleTurn();
        void startTurn();
        void switchTurn();

        void showBattleFieldStatus();

        void endBattle();

        bool canEndBattle();
        bool isVictory();

        void win();
        void lose();

    public:
        BattleField() {};
        BattleField(Fighter* fighter, Monster* monster);
        virtual ~BattleField() {};

        // getter, setter
        bool getTurn();
        void setTurn(bool turn);
        Fighter* getFighter();
        void setFighter(Fighter* const fighter);
        Monster* getMonster();
        void setMonster(Monster* const monster);

};

inline BattleField :: BattleField(Fighter* const fighter, Monster* const monster) {
    this->fighter = fighter;
    this->monster = monster;
    this->initBattleField();
}

inline bool BattleField :: getTurn() {
    return this->isFighterTurn;
}

inline void BattleField :: setTurn(bool isFighterTurn) {
    this->isFighterTurn = isFighterTurn;
}

inline Fighter* BattleField :: getFighter() {
    return this->fighter;
}

inline void BattleField :: setFighter(Fighter* const fighter) {
    this->fighter = fighter;
}

inline Monster* BattleField :: getMonster() {
    return this->monster;
}

inline void BattleField :: setMonster(Monster* const monster) {
    this->monster = monster;
}
