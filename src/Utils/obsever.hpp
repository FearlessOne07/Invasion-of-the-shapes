#pragma once
#include "utils.hpp"

class Observer
{
public:
    virtual ~Observer(){};
    virtual void OnNofity(const Event &event) = 0;
};