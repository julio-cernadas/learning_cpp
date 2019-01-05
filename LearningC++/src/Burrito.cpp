#include "Burrito.h"
#include <iostream>     //Preproccesor Directive
#include <string>

//Class Name::Member Function, Created by Constructor
Burrito::Burrito(){};   // Scope Resolution Operator

void Burrito::setIngr(std::string x)
{
    ingr = x;
};

std::string Burrito::getName()
{
    return ingr;
};
