//
// Created by student on 14.10.2019.
//
#include "TextWrapper.h"
#include <iostream>

int TextWrapper::columns()
{
    return 10;
}

std::string  TextWrapper::wrap(std::string str)
{
   //std::string t = str.at(0) + "\n" ;
   std::string t = "a\nb";
   std::cout << str.at(0) << "\n" << str.at(1) << "\n";
   std:: cout << t;
   return t;
}