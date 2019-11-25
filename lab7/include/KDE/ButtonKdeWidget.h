//
// Created by student on 25.11.2019.
//

#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_BUTTONKDEWIDGET_H
#define INC_07_ABSTRACT_FACTORY_PATTERN_BUTTONKDEWIDGET_H

#include "Widget.h"
#include <iostream>

class ButtonKdeWidget : public Widget {
private:
    int kdeVersion;
public:
    ButtonKdeWidget( int kdeVersion)
    {
        this->kdeVersion = kdeVersion;
    }
    void draw()
    {
        std::cout << "ButtonKdeWIdget " << this->kdeVersion << std::endl;
    }
};


#endif //INC_07_ABSTRACT_FACTORY_PATTERN_BUTTONKDEWIDGET_H
