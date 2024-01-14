#pragma once
#include "raylib.h"

typedef enum Event
{
    TO_TITLE = 0,
    TO_GAME,
    TO_EXIT
} Event;

typedef struct Button
{
    Vector2 size{};
    Color color{};
    Vector2 pos{};
    Rectangle rect{};
    const char *text{};
    int fontSize = 48;

    void SetText(const char *text)
    {
        this->text = text;
    }

    void DrawBtnText() const
    {
        DrawText(text, (pos.x + (size.x / 2 - 50)), (pos.y + (size.y / 2 - 48 / 2)), 48, color);
    }
} Button;