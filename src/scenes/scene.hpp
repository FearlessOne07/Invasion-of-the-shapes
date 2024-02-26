#pragma once
#include "../utils/obsever.hpp"
#include <vector>
#include "../utils/utils.hpp"
#include "raylib.h"
#include <memory>

class AssetManager;
class Scene
{
protected:
    std::vector<Observer *> _observers{};
    Color _clearColor{};

    std::shared_ptr<AssetManager>_assets;
 

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
    Scene(std::shared_ptr<AssetManager> assets)  :
        _assets(assets)
    {
    }
    virtual ~Scene(){};
    virtual void Update(float &dt) = 0;
    virtual void Render() = 0;
    virtual void Reset(){};
    void AddObserver(Observer *observer) { _observers.emplace_back(observer); }
};