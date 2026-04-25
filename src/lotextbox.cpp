#include "raylib.h"

#include "lotextbox.h"

LoTextBox::LoTextBox(float pad[static_cast<int>(Pad::Len)], std::string name,
float min_width, float max_width, float min_height, float max_height) 
: LoWidget(pad, name, min_width, max_width, min_height, max_height) {
  this->font_size = 15;
}

LoTextBox::LoTextBox(std::string name, float min_width, float max_width, float min_height, float max_height)
: LoWidget(name, min_width, max_width, min_height, max_height) {
  this->font_size = 15;
}

LoTextBox::LoTextBox(std::string name, int font_size) : LoWidget(name) {
  this->font_size = font_size;
}

void LoTextBox::SetText(std::string t) {
  this->text = t;
}

std::string &LoTextBox::GetText() {
  return this->text;
}

void LoTextBox::DrawHover() {
  DrawText(this->text.c_str(), this->GetPosX(), this->GetPosY(), this->font_size, BLUE);
}

void LoTextBox::DrawClicked() {
  DrawText(this->text.c_str(), this->GetPosX(), this->GetPosY(), this->font_size, RED);

}

void LoTextBox::DrawRegular() {
  DrawText(this->text.c_str(), this->GetPosX(), this->GetPosY(), this->font_size, BLACK);

}

void LoTextBox::Update(LoSignal &sig) {}

