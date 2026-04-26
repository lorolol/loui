#include "lowidget.h"

LoWidget::LoWidget(float pad[static_cast<int>(Pad::Len)], std::string name,
float min_width, float max_width, float min_height, float max_height) 
: LoBase(pad, name) {
  this->SetMinWidth(min_width);
  this->SetMaxWidth(max_width);
  this->SetMinHeight(min_height);
  this->SetMaxHeigth(max_height);
}

LoWidget::LoWidget(std::string name, float min_width, float max_width, float min_height, float max_height) 
: LoBase(name) {
  this->SetMinWidth(min_width);
  this->SetMaxWidth(max_width);
  this->SetMinHeight(min_height);
  this->SetMaxHeigth(max_height);
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
