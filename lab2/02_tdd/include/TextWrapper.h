//
// Created by student on 14.10.2019.
//

#pragma once
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class TextWrapper {
public:
    int columns();
    string wrap(string str);
};
