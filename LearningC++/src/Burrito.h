#pragma once
#include <string>

class Burrito
{
    public: 
        Burrito();                  // Constructor
        std::string ingr;
        void setIngr(std::string x);     
        std::string getName();
};