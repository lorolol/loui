#pragma once

#include "lowidget.h"

class LoTextBox : public LoWidget{
  private:
    Font font;
    std::string text;
    int font_size;

    Vector2 text_pos;
    void FitText();
  public:
    LoTextBox(float pad[static_cast<int>(Pad::Len)], std::string name,
    float min_width = 0.0, float max_width = 0.0, float min_height = 0.0, float max_height = 0.0);
    LoTextBox(std::string name, float min_width = 0.0, float max_width = 0.0, float min_height = 0.0, float max_height = 0.0);
    LoTextBox(std::string name, int font_size);

    void SetText(std::string t);
    std::string &GetText();

    void SetFont(std::string name, std::string weight = "");
    Font &GetFont();

    void DrawHover();
    void DrawClicked();
    void DrawRegular();

    void UpdateThis(LoSignal &sig);
};