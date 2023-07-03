#pragma once
#include <vector>
#include <string>

class StoryTextInterface {
    private:
        std::vector<std::string> storyText;

    private:
        void loadAllStoryText();

    public:
        virtual void printStoryText(std::string fileName);
};
