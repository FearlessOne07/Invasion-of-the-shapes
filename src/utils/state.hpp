#pragma once
class State
{
public:
    virtual void Update() = 0;
    virtual void Enter() = 0;
};