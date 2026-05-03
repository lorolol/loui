#include <algorithm>

#include "raylib.h"

#include "lotextbox.h"
#include "lohelpers.h"

LoTextBox::LoTextBox(float pad[static_cast<int>(Pad::Len)], std::string name,
float min_width, float max_width, float min_height, float max_height) 
: LoWidget(pad, name, min_width, max_width, min_height, max_height) {
  this->UpdatePush([this]() {
    this->font = GetFontDefault();
  });
  this->font_size = 15;
}

LoTextBox::LoTextBox(std::string name, float min_width, float max_width, float min_height, float max_height)
: LoWidget(name, min_width, max_width, min_height, max_height) {
  this->UpdatePush([this]() {
    this->font = GetFontDefault();
  });
  this->font_size = 15;
}

LoTextBox::LoTextBox(std::string name, int font_size) : LoWidget(name) {
  this->UpdatePush([this]() {
    this->font = GetFontDefault();
  });
  this->font_size = font_size;
}

void LoTextBox::SetText(std::string t) {
  this->text = t;
}

std::string &LoTextBox::GetText() {
  return this->text;
}

void LoTextBox::SetFont(std::string name, std::string weight) {
  this->UpdatePush([this, name, weight](){
    std::string path = loui::ShellExec("fc-list | grep -i \""+ name +"\"" + "| grep \"" + weight + "\" | head -n 1 | awk -F ':' '{print $1}'");
    Font f = LoadFontEx(path.c_str(), this->font_size, NULL, 0);
    if (IsFontValid(f)) {
      UnloadFont(this->font);
      this->font = f;
    }
  });
}

Font &LoTextBox::GetFont() {
  return this->font;
}

void LoTextBox::FitText() {
  Vector2 t_size {MeasureTextEx(this->font, this->text.c_str(), this->font_size, 1)};
  if (t_size.y > this->GetHeight()) {
    int lines {};
    for (auto &i : this->text) {
      if (i == '\n') lines++;
    }
    this->font_size = this->GetHeight() / lines;
  }

  t_size = MeasureTextEx(this->font, this->text.c_str(), this->font_size, 1);
  
  if (t_size.x > this->GetWidth()) {
    int i {};
    while (t_size.x > this->GetWidth() && i < 5) {
      std::size_t past_space {loui::GetClosestSpace(this->text, this->font, this->font_size, this->GetWidth())};
      if (past_space == std::string::npos) break;
      this->text[past_space] = '\n';
      t_size = MeasureTextEx(this->font, this->text.c_str(), this->font_size, 1);
      i++;
    }


  }
}


void LoTextBox::DrawHover() {
  DrawRectangleLines(this->GetPosX(), this->GetPosY(), this->GetWidth(), this->GetHeight(), BLACK);
  DrawTextEx(this->font, this->text.c_str(), this->text_pos, this->font_size, 1, BLUE);
}

void LoTextBox::DrawClicked() {
  DrawRectangleLines(this->GetPosX(), this->GetPosY(), this->GetWidth(), this->GetHeight(), BLACK);
  DrawTextEx(this->font, this->text.c_str(), this->text_pos, this->font_size, 1, RED);
}

void LoTextBox::DrawRegular() {
  DrawRectangleLines(this->GetPosX(), this->GetPosY(), this->GetWidth(), this->GetHeight(), BLACK);
  DrawTextEx(this->font, this->text.c_str(), this->text_pos, this->font_size, 1, BLACK);
}

void LoTextBox::UpdateThis(LoSignal &sig) {
  Vector2 t_size = MeasureTextEx(this->font, this->text.c_str(), this->font_size, 1);
  this->FitText();

  switch (this->GetAlignmentHorizontal()) {
    case Align::Horizontal::Left: 
      this->text_pos.x = this->GetPosX();
    break;
    
    case Align::Horizontal::Right:
      this->text_pos.x = this->GetPosX() + this->GetWidth() - t_size.x;
    break;
    
    case Align::Horizontal::Center: 
      this->text_pos.x = this->GetPosX() + (this->GetWidth() / 2.0) - (t_size.x / 2.0);
    break;
  }

  switch (this->GetAlignmentVertical()) {
    case Align::Vertical::Top:
      this->text_pos.y = this->GetPosY();
    break;

    case Align::Vertical::Bottom:
      this->text_pos.y = this->GetPosY() + this->GetHeight() -  t_size.y;
    break;

    case Align::Vertical::Center:
      this->text_pos.y = this->GetPosY() + (this->GetHeight() / 2.0) - (t_size.y / 2.0);
    break;
  }
}
