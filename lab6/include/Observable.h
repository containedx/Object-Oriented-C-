//
// Created by student on 18.11.2019.
//

#ifndef INC_06_OBSERVER_PATTERN_OBSERVABLE_H
#define INC_06_OBSERVER_PATTERN_OBSERVABLE_H

#include <set>
#include "Observer.h"

class Observable {

private:
    std::set<Observer*> observers;

public:
    void registerObserver(Observer* x)
    {
        this->observers.insert(x);
    }

    void unregisterObserver(Observer* x)
    {
        this->observers.erase(x);
    }

protected:
    void notifyObserver(float value)
    {
        for(Observer* observer:observers)
            observer->notify(value);
    }

};


#endif //INC_06_OBSERVER_PATTERN_OBSERVABLE_H
