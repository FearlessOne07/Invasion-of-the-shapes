#pragma once
#include "raylib.h"

typedef enum Event : unsigned int
{
	TO_TITLE = 0,
	TO_GAME,
	TO_GAME_NEW,
	TO_EXIT,
	TO_PAUSE,
	TO_GAME_OVER
} Event;

typedef struct Button
{
	Vector2 size{};
	Color color{};
	Vector2 pos{};
	Rectangle rect{};

	// Text
	const char* text{};
	int fontSize;
	int textWidth;
	Font font;

	void SetText(const char* text)
	{
		this->text = text;
		textWidth = MeasureTextEx(font, this->text, fontSize, 1).x;
	}

	void Draw() const
	{
		DrawRectangleRoundedLines(rect, 0.2f, 1, 4, color);
		DrawTextEx(font, text, { (pos.x + (size.x / 2) - (textWidth / 2)), (pos.y + ((size.y / 2) - (fontSize / 2))) }, fontSize, 1, color);
	}
} Button;

