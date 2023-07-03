#include "StoryTextInterface.hpp"

#include <iostream>
#include <fstream>
#include <string>

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
