#include "GameInterface.hpp"

void GameInterface :: initGame() {
    StoryTextInterface* storyTextInterface = new StoryTextInterface();
    Fighter* lumine = new Fighter("Lumine", ElementalAttribute(ElementalAttributeList::Dendro), 1000, 100, 100, 50);
    Monster* slime = new Monster("Slime", ElementalAttribute(ElementalAttributeList::Hydro), 500, 50, 50, 30, 300);
    storyTextInterface->printStoryText("battle_start_default");
    BattleField* battleField = new BattleField(lumine, slime);
    storyTextInterface->printStoryText("battle_end_default");
    delete lumine;
    delete slime;
    delete battleField;
}
