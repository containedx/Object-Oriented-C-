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

    //erase spaces:
    for(int i=0; i<str.length(); i++)
        if(str.at(i)== ' ')
            str.erase(i,1);

    // insert new line
    for(int i=chars; i<str.length(); i+=chars+1)
    {
        str.insert(i, "\n");
    }

   return str;
}

string TextWrapper::realtextwrapper( string str, int len)
{

}

