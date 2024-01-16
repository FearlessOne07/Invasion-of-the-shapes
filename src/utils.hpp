#pragma once
#include "raylib.h"

typedef enum Event : unsigned int
{
    TO_TITLE = 0,
    TO_GAME,
    TO_EXIT,
    TO_PAUSE
} Event;

typedef struct Button
{
    Vector2 size{};
    Color color{};
    Vector2 pos{};
    Rectangle rect{};

    // Text
    const char *text{};
    int fontSize;
    int textWidth;

    void SetText(const char *text)
    {
        this->text = text;
        textWidth = MeasureText(this->text, fontSize);
    }

    void Draw() const
    {
        DrawRectangleRoundedLines(rect, .2, 1, 4, color);
        DrawText(text, (pos.x + (size.x / 2) - (textWidth / 2)), (pos.y + ((size.y / 2) - (fontSize / 2))), fontSize, color);
    }
} Button;