//
// Created by student on 25.11.2019.
//

#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_CHECKBOXGNOMEWIDGET_H
#define INC_07_ABSTRACT_FACTORY_PATTERN_CHECKBOXGNOMEWIDGET_H

#include "Widget.h"
#include <iostream>

class CheckBoxGnomeWidget: public Widget {
private:
    int gnomeVersion;
public:
    CheckBoxGnomeWidget( int gnomeVersion)
    {
        this->gnomeVersion = gnomeVersion;
    }
    void draw()
    {
        std::cout << "CheckBoxGnomeWIdget " << this->gnomeVersion << std::endl;
    }
};


#endif //INC_07_ABSTRACT_FACTORY_PATTERN_CHECKBOXGNOMEWIDGET_H
