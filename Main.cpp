/**
 * @author nashdev255
 * @brief HoneyRPG
 * @version 0.1.0
 * 
*/

#include "./MainIncludes.hpp"

int main() {
    Fighter* fighter = new Fighter("Lumine", Anemo, 1000, 100, 100, 50);
    Monster* monster = new Monster("Slime", Hydro, 500, 50, 50, 20, 10);
    BattleField* battleField = new BattleField(fighter, monster);
    return 0;
}
