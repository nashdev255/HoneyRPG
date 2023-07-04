#include "StoryTextInterface.hpp"

#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

StoryTextInterface :: StoryTextInterface() {
    std::string folderPath = "./Lines/";

    for(const auto& entry : fs::directory_iterator(folderPath)) {
        if(entry.is_regular_file() && entry.path().extension() == ".txt") {
            std::ifstream file(entry.path());
            if(file.is_open()) {
                std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
                lineText.push_back(content);
                file.close();
            }
        }
    }
}

/**
 * すべてのテキストファイルを読み込む
*/
void StoryTextInterface :: loadAllStoryText() {
    
}

void StoryTextInterface :: printStoryText(std::string fileName) {
    std::fstream myFile;
    myFile.open(fileName, std::ios::in);
    if(myFile.is_open()) {
        std::string line;
        while(getline(myFile, line)) {
            std::cout << line << std::endl;
        }
        myFile.close();
    }
}
