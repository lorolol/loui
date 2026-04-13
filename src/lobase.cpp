#include "lobase.h"

LoBase::LoBase(float x, float y, float w, float h, float pad[static_cast<int>(Pad::Len)], std::string &name) {
  this->x = x; this->y = y; this->w = w; this->h = h; this->name = name;
  std::copy(pad[0], pad[static_cast<int>(Pad::Len) - 1], this->pad);
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

void LoBase::HandleSignal(LoSignal sig) {

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
