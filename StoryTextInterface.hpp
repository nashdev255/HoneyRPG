#pragma once
#include <map>
#include <vector>
#include <string>

class StoryTextInterface {
    private:
        std::vector<std::string> fileName;
        std::vector<std::string> lineText;
        std::map<std::string, std::string> npcText;

    private:
        void loadAllStoryText();

    public:
        virtual void printStoryText(std::string fileName);
};
