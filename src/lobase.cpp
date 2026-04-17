#include "lobase.h"

LoBase::LoBase(float x, float y, float w, float h, float pad[static_cast<int>(Pad::Len)], std::string &name) {
  this->x = x; this->y = y; this->w = w; this->h = h; this->name = name;
  std::copy(&pad[0], &pad[static_cast<int>(Pad::Len)], this->pad);
  this->parent = nullptr;

  this->on_click = nullptr;
  this->on_hover = nullptr;
  this->on_scroll = nullptr;
}

LoBase::LoBase(LoBase *parent, float pad[static_cast<int>(Pad::Len)], std::string &name) {
  this->parent = parent; this->name = name;
  std::copy(&pad[0], &pad[static_cast<int>(Pad::Len)], this->pad);

  this->on_click = nullptr;
  this->on_hover = nullptr;
  this->on_scroll = nullptr;
}

LoBase::LoBase(LoBase *parent, std::string &name) {
  this->parent = parent;
  this->name = name;
  std::fill(&this->pad[0], &this->pad[static_cast<int>(Pad::Len)], 0.0);

  this->on_click = nullptr;
  this->on_hover = nullptr;
  this->on_scroll = nullptr;
}


std::string &LoBase::GetName() {
  return this->name;
}

float LoBase::GetPosX() {
  return this->x;
}

float LoBase::GetPosY() {
  return this->y;
}

float LoBase::GetWidth() {
  return this->w;
}

float LoBase::GetHeight() {
  return this->h;
}

float LoBase::GetPadding(Pad side) {
  return this->pad[static_cast<int>(side)];
}

Align::Horizontal LoBase::GetAlignmentHorizontal() {
  return this->align_h;
}

Align::Vertical LoBase::GetAlignmentVertical() {
  return this->align_v;
}

void LoBase::SetPosX(float x) {
  this->x = x;
}

void LoBase::SetPosY(float y) {
  this->y = y;
}

void LoBase::SetWidth(float width) {
  this->w = width;
}

void LoBase::SetHeight(float height) {
  this->h = height;
}

bool LoBase::IsInside(Vector2 point) {
  bool vert {point.y >= this->y + this->pad[static_cast<int>(Pad::Top)] && 
            point.y <= this->y  + this->h - this->pad[static_cast<int>(Pad::Bottom)]};
  bool horiz {point.x >= this->x + this->pad[static_cast<int>(Pad::Left)] &&
            point.x <= this->x + this->w - this->pad[static_cast<int>(Pad::Right)]};
  return vert && horiz;
}


void LoBase::SetName(std::string &name) {
  this->name = name;
}

void LoBase::SetPadding(Pad side, float pad) {
  this->pad[static_cast<int>(side)] = pad;
}

void LoBase::SetAlignmentHorizontal(Align::Horizontal alignment) {
  this->align_h = alignment;
}

void LoBase::SetAlignmentVertical(Align::Vertical alignment) {
  this->align_v = alignment;
}

void LoBase::HandleSignal(LoSignal &sig) {
  switch (sig.type) {
    case LoSignal::Type::Clicked:
      this->OnClick(sig.mouse_pos, sig.button);
      break;
    case LoSignal::Type::Hover:
      this->OnHover(sig.mouse_pos);
      break;
    case LoSignal::Type::Scroll:
      this->OnScroll(sig.mouse_pos, sig.scroll);
      break;
  }
}

void LoBase::SetOnClick(std::function<void (Vector2 m_pos, MouseButtons b, void *arg)> &fn) {
  this->on_click = new std::function<void (Vector2 m_pos, MouseButtons b, void *arg)>(fn);
}

void LoBase::SetOnScroll(std::function<void (Vector2 m_pos, float s, void *arg)> &fn) {
  this->on_scroll = new std::function<void (Vector2 m_pos, float s, void *arg)>(fn);

}

void LoBase::SetOnHover(std::function<void (Vector2 m_pos, void *arg)> &fn) {
  this->on_hover = new std::function<void (Vector2 m_pos, void *arg)>(fn);
}
