#include "lowidget.h"

LoWidget::LoWidget(float pad[static_cast<int>(Pad::Len)], std::string name,
float min_width, float max_width, float min_height, float max_height) 
: LoBase(pad, name) {
  this->min_w = min_width;
  this->max_w = max_width;
  this->min_h = min_height;
  this->max_h = max_height;
}

LoWidget::LoWidget(std::string name, float min_width, float max_width, float min_height, float max_height) 
: LoBase(name) {
  this->min_w = min_width;
  this->max_w = max_width;
  this->min_h = min_height;
  this->max_h = max_height;
}
LoWidget::LoWidget(float pad[static_cast<int>(Pad::Len)], std::string name) 
: LoBase(pad, name) {

}

void LoWidget::SetMinWidth(float width) {
  this->min_w = width;
}

void LoWidget::SetMaxWidth(float width) {
  this->max_w = width;
}

void LoWidget::SetMinHeight(float height) {
  this->min_h = height;
}

void LoWidget::SetMaxHeigth(float height) {
  this->max_h = height;
}

void LoWidget::Draw() {
  switch (this->state) {
    case MouseState::Hover:
      this->DrawHover();
      break;
    case MouseState::None:
      this->DrawRegular();
      break;
    case MouseState::M1_Pressed ... MouseState::M5_Pressed:
      this->DrawClicked();
      break;

    default:
      break;
  }
}
