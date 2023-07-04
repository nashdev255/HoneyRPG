#pragma once
#include <map>
#include <vector>
#include <string>

class StoryTextInterface {
    private:
        std::vector<std::string> fileNames;
        std::vector<std::string> lineTexts;
        std::map<std::string, std::string> npcText;

    private:
        void loadAllStoryText();

    public:
        StoryTextInterface();
        virtual void printStoryText(std::string fileName);
};
