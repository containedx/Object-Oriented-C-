//
// Created by student on 25.11.2019.
//

#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_DEMO_H
#define INC_07_ABSTRACT_FACTORY_PATTERN_DEMO_H

#include <KDE/KdeWidgetFactory.h>
#include <GNOME/GnomeWidgetFactory.h>
#include "WidgetFactory.h"

class Demo {
private:
    std::shared_ptr<WidgetFactory> factory;
public:
    Demo(std::shared_ptr<WidgetFactory> factory)
    {
         this->factory = factory;
    }
    void run(std::string type) //tworzy obiekt i wypisze jakiego jest typu
    {
        this->factory->create(type)->draw();
    }
};


#endif //INC_07_ABSTRACT_FACTORY_PATTERN_DEMO_H
