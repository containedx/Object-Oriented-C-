//
// Created by student on 25.11.2019.
//

#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_LISTGNOMEWIDGET_H
#define INC_07_ABSTRACT_FACTORY_PATTERN_LISTGNOMEWIDGET_H

#include "Widget.h"
#include <iostream>

class ListGnomeWidget: public Widget {
private:
    int gnomeVersion;
public:
    ListGnomeWidget( int gnomeVersion)
    {
        this->gnomeVersion = gnomeVersion;
    }
    void draw()
    {
        std::cout << "ListGnomeWIdget " << this->gnomeVersion << std::endl;
    }
};


#endif //INC_07_ABSTRACT_FACTORY_PATTERN_LISTGNOMEWIDGET_H
