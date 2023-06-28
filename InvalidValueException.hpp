#pragma once
#include <string>
#include <exception>

class InvalidValueException : public std::exception {
public:
    const char* what() const throw() {
        return "Invalid value.";
    }
};
