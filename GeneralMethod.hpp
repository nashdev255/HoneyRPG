#pragma once
#include <iostream>
#include <fstream>
#include <random>
#include <string>

enum Color {
    Cream,
    Red,
    Blue,
    White,
    Purple,
    Green,
    Sky,
    Brown
};

namespace GeneralMethod {
    int generateRandomSeed(int min, int max);
    void printTextFile(std::string fileName);
    std::string colorString(Color c, std::string str);
}

int GeneralMethod :: generateRandomSeed(int min, int max) {
    std::random_device rand;
    std::mt19937 gen(rand());
    std::uniform_int_distribution<int> distribute(min, max);

    int randomSeed = distribute(gen);

    return randomSeed;
}

void GeneralMethod :: printTextFile(std::string fileName) {
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

std::string GeneralMethod :: colorString(Color c, std::string str) {
    std::string coloredString;
    std::string tail = " \x1b[m";
    str += tail;
    switch(c) {
        case Cream:
            coloredString = "\x1b[38;2;255;255;205m " + str;
            break;
        case Red:
            coloredString = "\x1b[38;2;255;69;0m " + str;
            break;
        case Blue:
            coloredString = "\x1b[38;2;0;191;255m " + str;
            break;
        case White:
            coloredString = "\x1b[38;2;220;220;255m " + str;
            break;
        case Purple:
            coloredString = "\x1b[38;2;116;83;171m " + str;
            break;
        case Green:
            coloredString = "\x1b[38;2;127;255;0m " + str;
            break;
        case Sky:
            coloredString = "\x1b[38;2;180;206;255m " + str;
            break;
        case Brown:
            coloredString = "\x1b[38;2;240;230;140m " + str;
            break;
    }
    return coloredString;
}
