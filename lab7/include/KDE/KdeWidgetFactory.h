//
// Created by student on 25.11.2019.
//

#ifndef INC_07_ABSTRACT_FACTORY_PATTERN_KDEWIDGETFACTORY_H
#define INC_07_ABSTRACT_FACTORY_PATTERN_KDEWIDGETFACTORY_H

#include "Widget.h"
#include "WidgetFactory.h"
#include "CheckBoxKdeWidget.h"
#include "ListKdeWidget.h"
#include "ButtonKdeWidget.h"

class KdeWidgetFactory:public WidgetFactory {
private:
    int kdeVersion;
public:
    KdeWidgetFactory(int kdeVersion)
    {
        this->kdeVersion = kdeVersion;
    }
    std::shared_ptr<Widget> create(std::string type)
    {
        if( type == "CheckBox")
        {
            return std::make_shared<CheckBoxKdeWidget>( this->kdeVersion);
        }


        if( type == "List")
        {
            return std::make_shared<ListKdeWidget>(this->kdeVersion);
        }

        if( type == "Button")
        {
            return std::make_shared<ButtonKdeWidget>(this->kdeVersion);
        }
    }
};


#endif //INC_07_ABSTRACT_FACTORY_PATTERN_KDEWIDGETFACTORY_H
