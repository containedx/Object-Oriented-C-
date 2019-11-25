//
// Created by student on 25.11.2019.
//

#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_GNOMEWIDGETFACTORY_H
#define INC_07_ABSTRACT_FACTORY_PATTERN_GNOMEWIDGETFACTORY_H


#include "Widget.h"
#include "WidgetFactory.h"
#include "CheckBoxGnomeWidget.h"
#include "ListGnomeWidget.h"
#include "ButtonGnomeWidget.h"

class GnomeWidgetFactory: public WidgetFactory {
private:
    int gnomeVersion;
public:
    GnomeWidgetFactory(int gnomeVersion)
    {
        this->gnomeVersion = gnomeVersion;
    }
    std::shared_ptr<Widget> create(std::string type)
    {
        if( type == "CheckBox")
        {
            return std::make_shared<CheckBoxGnomeWidget>( this->gnomeVersion);
        }


        if( type == "List")
        {
            return std::make_shared<ListGnomeWidget>(this->gnomeVersion);
        }

        if( type == "Button")
        {
            return std::make_shared<ButtonGnomeWidget>(this->gnomeVersion);
        }
    }
};


#endif //INC_07_ABSTRACT_FACTORY_PATTERN_GNOMEWIDGETFACTORY_H
