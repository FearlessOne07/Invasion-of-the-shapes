#pragma once
#include <cmath>
#include <memory>

#include "raylib.h"

class Utils {
public:
  typedef struct Button {
    Vector2 size{};
    Color color{};
    Vector2 pos{};
    Rectangle rect{};

    // Text
    const char *text{};
    int fontSize;
    int textWidth;
    std::shared_ptr<Font> font;

    void SetText(const char *text) {
      this->text = text;
      textWidth = MeasureTextEx(*font, this->text, fontSize, 1).x;
    }

    void Draw() const {
      DrawRectangleRoundedLines(rect, 0.2f, 4, color);
      DrawTextEx(*font, text,
                 {(pos.x + (size.x / 2) - (textWidth / 2.f)),
                  (pos.y + ((size.y / 2) - (fontSize / 2.f)))},
                 fontSize, 1, color);
    }
  } Button;

  // Functions
  static float Approach(float current, float goal, float step) {
    if (std::fabs(goal - current) < step) {
      return goal;
    } else if (goal > current) {
      return current + step;
    } else {
      return current - step;
    }
  }
};
