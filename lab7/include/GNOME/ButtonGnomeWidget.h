//
// Created by student on 25.11.2019.
//

#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_BUTTONGNOMEWIDGET_H
#define INC_07_ABSTRACT_FACTORY_PATTERN_BUTTONGNOMEWIDGET_H

#include "Widget.h"
#include <iostream>

class ButtonGnomeWidget: public Widget {
private:
    int gnomeVersion;
public:
    ButtonGnomeWidget( int gnomeVersion)
    {
        this->gnomeVersion = gnomeVersion;
    }
    void draw()
    {
        std::cout << "ButtonGnomeWIdget " << this->gnomeVersion << std::endl;
    }
};


#endif //INC_07_ABSTRACT_FACTORY_PATTERN_BUTTONGNOMEWIDGET_H
