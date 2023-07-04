#include "StoryTextInterface.hpp"

#include <iostream>
#include <filesystem>
#include <fstream>

StoryTextInterface :: StoryTextInterface() {
    std::string folderPath = "./Lines/";

    for(const auto& entry : std::filesystem::directory_iterator(folderPath)) {
        if(entry.is_regular_file() && entry.path().extension() == ".txt") {
            std::string fileName = entry.path().filename().stem().string();
            fileNames.push_back(fileName);
            std::ifstream file(entry.path());
            if(file.is_open()) {
                std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
                lineTexts.push_back(content);
                file.close();
            }
        }
    }

    for(int i=0;i<fileNames.size();i++) {
        npcText.insert(std::make_pair(fileNames[i], lineTexts[i]));
    }
}

void StoryTextInterface :: printStoryText(std::string fileName) {
    std::string lineText = npcText.at(fileName);
    std::cout << lineText << std::endl;
}
