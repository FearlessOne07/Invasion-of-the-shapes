#pragma once
#include "obsever.hpp"
#include <vector>
#include "utils.hpp"
#include "raylib.h"
class Scene
{
protected:
    std::vector<Observer *> _observers{};

protected:
    virtual void GetInput() = 0;
    virtual void Notify(const Event &event)
    {
        for (Observer *observer : _observers)
        {
            observer->OnNofity(event);
        }
    }

public:
    virtual ~Scene(){};
    virtual void Update(float &dt) = 0;
    virtual void Render() = 0;
    void AddObserver(Observer *observer) { _observers.push_back(observer); }
};