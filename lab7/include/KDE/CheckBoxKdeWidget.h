//
// Created by student on 25.11.2019.
//

#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_CHECKBOXKDEWIDGET_H
#define INC_07_ABSTRACT_FACTORY_PATTERN_CHECKBOXKDEWIDGET_H

#include "Widget.h"
#include <iostream>

class CheckBoxKdeWidget : public Widget {
private:
    int kdeVersion;
public:
    CheckBoxKdeWidget( int kdeVersion)
    {
        this->kdeVersion = kdeVersion;
    }
    void draw()
    {
        std::cout << "CheckBoxKdeWIdget " << this->kdeVersion << std::endl;
    }
};


#endif //INC_07_ABSTRACT_FACTORY_PATTERN_CHECKBOXKDEWIDGET_H
