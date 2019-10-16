//
// Created by student on 14.10.2019.
//
#include "TextWrapper.h"


int TextWrapper::columns() //test function
{
    return 10;
}

string  TextWrapper::wrap(string str) // space -> new line
{
    replace( str.begin(), str.end(), ' ', '\n');
    return str;
}

string TextWrapper::wrapInColumns(string str, int chars)//chars == number of chars in column
{
    int n = str.rfind( ' ', chars+1);
    if(n) {
        str.at(n) = '\n';
    }

   return str;
}

