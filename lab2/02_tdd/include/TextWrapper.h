//
// Created by student on 14.10.2019.
//

#pragma once
#include <string>
using namespace std;

class TextWrapper {
public:
    int columns();
    std::string wrap(std::string str);
};
