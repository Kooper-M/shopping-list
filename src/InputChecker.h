#pragma once
#include <string>

class InputChecker {
    public:
        static double getDoubleInput(const std::string& prompt); 
        static int getIntInput(const std::string& prompt);
        static std::string getStringInput(const std::string& prompt);
};

