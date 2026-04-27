#include "lowindow.h"

void LoWindow::RlInitWindow() {
  unsigned int flags = FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT | FLAG_WINDOW_RESIZABLE;
  SetConfigFlags(flags);
  this->main = new std::thread([this](){this->WindowLoop();});
}

void LoWindow::WindowLoop() {
  InitWindow(this->GetWidth(), this->GetHeight(), this->GetName().c_str());
  for (;;) {
    Vector2 m_pos = GetMousePosition();
    float scroll = GetMouseWheelMove();
    bool m_btn[3] {IsMouseButtonDown(MOUSE_BUTTON_LEFT), 
      IsMouseButtonDown(MOUSE_BUTTON_RIGHT), 
      IsMouseButtonDown(MOUSE_BUTTON_MIDDLE)};
    
    LoSignal sig {};
    sig.mouse_pos = m_pos;
    if (m_btn[static_cast<int>(MouseButtons::M1)]) {
      sig.mouse_state = MouseState::M1_Pressed;
    } else if (m_btn[static_cast<int>(MouseButtons::M2)]) {
      sig.mouse_state = MouseState::M2_Pressed;
    } else if (m_btn[static_cast<int>(MouseButtons::M3)]) {
      sig.mouse_state = MouseState::M3_Pressed;
    } else sig.mouse_state = MouseState::Hover;
    
    this->Update(sig);
    BeginDrawing();
      ClearBackground(this->bg);
      this->Draw();

    EndDrawing();
  }
}

LoWindow::LoWindow(float w, float h, float pad[static_cast<int>(Pad::Len)], std::string &name, Color bg, std::vector<LoBase *> objs) : 
LoContainer(0, 0, w, h, pad, name, objs) {
  this->bg = bg;
  this->RlInitWindow();
}

LoWindow::LoWindow(float w, float h, std::string &name, Color bg, std::vector<LoBase *> objs) :
LoContainer(0, 0, w, h, (float[4]){0.0, 0.0, 0.0, 0.0}, name, objs) {
  this->bg = bg;
  this->RlInitWindow();
}


void LoWindow::UpdateThis(LoSignal &sig) {
  this->SetHeight(GetScreenHeight());
  this->SetWidth(GetScreenWidth());
  this->HandleSignal(sig);
  DrawRectangleLines(this->GetPosX() + this->GetPadding(Pad::Left),
                    this->GetPosY() + this->GetPadding(Pad::Top),
                    this->GetWidth() - (this->GetPadding(Pad::Left) + this->GetPadding(Pad::Right)),
                    this->GetHeight() - (this->GetPadding(Pad::Top) + this->GetPadding(Pad::Bottom)), RED);
  for (auto &i : this->children) {
    i.obj->SetPosX(this->GetPosX() + this->GetPadding(Pad::Left));
    i.obj->SetPosY(this->GetPosY() + this->GetPadding(Pad::Top));
    
    i.obj->SetWidth(this->GetWidth() - (this->GetPadding(Pad::Left) + this->GetPadding(Pad::Right)));
    i.obj->SetHeight(this->GetHeight() - (this->GetPadding(Pad::Top) + this->GetPadding(Pad::Bottom)));
    i.obj->Update(sig);
  }
}