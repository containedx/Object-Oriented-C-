//
// Created by student on 14.10.2019.
//
#include "TextWrapper.h"


int TextWrapper::columns()
{
    return 10;
}

std::string  TextWrapper::wrap(std::string str)
{
    std::replace( str.begin(), str.end(), ' ', '\n');
   return str;
}