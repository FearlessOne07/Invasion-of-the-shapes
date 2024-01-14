#include "title_scene.hpp"

void TitleScene::Update()
{
    GetInput();
}

void TitleScene::GetInput()
{
    if(IsKeyPressed(KEY_P))
    {
        Notify(Event::TO_GAME);
    }
}


void TitleScene::Render()
{
    DrawText("TitleScreen!", 100, 100, 64, RED);
}
