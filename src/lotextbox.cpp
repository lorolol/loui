#include <algorithm>

#include "raylib.h"

#include "lotextbox.h"
#include "lohelpers.h"

LoTextBox::LoTextBox(float pad[static_cast<int>(Pad::Len)], std::string name,
float min_width, float max_width, float min_height, float max_height) 
: LoWidget(pad, name, min_width, max_width, min_height, max_height) {
  this->font = GetFontDefault();
  this->font_size = 15;
}

LoTextBox::LoTextBox(std::string name, float min_width, float max_width, float min_height, float max_height)
: LoWidget(name, min_width, max_width, min_height, max_height) {
  this->font = GetFontDefault();
  this->font_size = 15;
}

LoTextBox::LoTextBox(std::string name, int font_size) : LoWidget(name) {
  this->font = GetFontDefault();
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
    std::string path = ShellExec("fc-list | grep -i \""+ name +"\"" + "| grep \"" + weight + "\" | head -n 1 | awk -F ':' '{print $1}'");
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

void LoTextBox::DrawHover() {
  DrawRectangleLines(this->GetPosX(), this->GetPosY(), this->GetWidth(), this->GetHeight(), BLUE);
  DrawTextEx(this->font, this->text.c_str(), (Vector2){this->GetPosX(), this->GetPosY()}, this->font_size, 1, BLUE);
}

void LoTextBox::DrawClicked() {
  DrawRectangleLines(this->GetPosX(), this->GetPosY(), this->GetWidth(), this->GetHeight(), BLUE);
  DrawTextEx(this->font, this->text.c_str(), (Vector2){this->GetPosX(), this->GetPosY()}, this->font_size, 1, RED);
}

void LoTextBox::DrawRegular() {
  DrawRectangleLines(this->GetPosX(), this->GetPosY(), this->GetWidth(), this->GetHeight(), BLUE);
  DrawTextEx(this->font, this->text.c_str(), (Vector2){this->GetPosX(), this->GetPosY()}, this->font_size, 1, BLACK);
}

