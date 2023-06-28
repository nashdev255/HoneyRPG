/**
 * @author nashdev255
 * @brief HoneyRPG
 * 
*/

#include "./MainIncludes.hpp"

int main() {
    Fighter* lumine = new Fighter("Lumine", ElementalAttribute(ElementalAttributeList::Dendro), 1000, 100, 100, 50);
    Monster* slime = new Monster("Slime", ElementalAttribute(ElementalAttributeList::Hydro), 500, 50, 50, 30);
    BattleField* battleField = new BattleField(lumine, slime);
    GeneralMethod::printTextFile("test.txt");
    delete lumine;
    delete slime;
    delete battleField;
    return 0;
}