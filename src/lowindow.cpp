#include "lowindow.h"

void LoWindow::RlInitWindow() {
  // unsigned int flags = FLAG_VSYNC_HINT | FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT | FLAG_WINDOW_RESIZABLE;
  // SetConfigFlags(flags);
  this->main = new std::thread([this](){this->WindowLoop();});
}

void LoWindow::WindowLoop() {
  InitWindow(this->GetWidth(), this->GetHeight(), this->GetName().c_str());
  for (;;) {
    this->Update();
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


void LoWindow::Update() {
  printf("pos x %f\n", this->GetPosX());
  DrawRectangleLines(this->GetPosX() + this->GetPadding(Pad::Left),
                    this->GetPosY() + this->GetPadding(Pad::Top),
                    this->GetWidth() - (this->GetPadding(Pad::Left) + this->GetPadding(Pad::Right)),
                    this->GetHeight() - (this->GetPadding(Pad::Top) + this->GetPadding(Pad::Bottom)), RED);
  for (auto &i : this->children) {
    i->SetPosX(this->GetPosX() + this->GetPadding(Pad::Left));
    i->SetPosY(this->GetPosY() + this->GetPadding(Pad::Top));

    i->SetWidth(this->GetWidth() - (this->GetPadding(Pad::Left) + this->GetPadding(Pad::Right)));
    i->SetHeight(this->GetHeight() - (this->GetPadding(Pad::Top) + this->GetPadding(Pad::Bottom)));
  }
}