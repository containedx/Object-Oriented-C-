//
// Created by student on 25.11.2019.
//

#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_LISTKDEWIDGET_H
#define INC_07_ABSTRACT_FACTORY_PATTERN_LISTKDEWIDGET_H

#include "Widget.h"
#include <iostream>

class ListKdeWidget: public Widget {
private:
    int kdeVersion;
public:
    ListKdeWidget( int kdeVersion)
    {
        this->kdeVersion = kdeVersion;
    }
    void draw()
    {
        std::cout << "ListKdeWIdget " << this->kdeVersion << std::endl;
    }
};


#endif //INC_07_ABSTRACT_FACTORY_PATTERN_LISTKDEWIDGET_H
