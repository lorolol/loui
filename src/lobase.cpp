#include "lobase.h"

LoBase::LoBase(float x, float y, float w, float h, float pad[static_cast<int>(Pad::Len)], std::string &name) {
  this->x = x; this->y = y; this->w = w; this->h = h; this->name = name;
  std::copy(&pad[0], &pad[static_cast<int>(Pad::Len)], this->pad);
  this->parent = nullptr;

  this->on_click = nullptr;
  this->on_hover = nullptr;
  this->on_scroll = nullptr;
  this->state = MouseState::None;
  this->event = MouseEvent::None;
}

LoBase::LoBase(float pad[static_cast<int>(Pad::Len)], std::string &name) {
  this->name = name;
  std::copy(&pad[0], &pad[static_cast<int>(Pad::Len)], this->pad);

  this->on_click = nullptr;
  this->on_hover = nullptr;
  this->on_scroll = nullptr;
  this->state = MouseState::None;
  this->event = MouseEvent::None;
}

LoBase::LoBase(std::string &name) {
  this->name = name;
  std::fill(&this->pad[0], &this->pad[static_cast<int>(Pad::Len)], 0.0);

  this->on_click = nullptr;
  this->on_hover = nullptr;
  this->on_scroll = nullptr;
  this->state = MouseState::None;
  this->event = MouseEvent::None;
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

void LoBase::SetParent(LoBase *parent) {
  this->parent = parent;
}

LoBase *LoBase::GetParent() {
  return this->parent;
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

void LoBase::SetMinWidth(float width) {
  this->min_w = width;
}

void LoBase::SetMaxWidth(float width) {
  this->max_w = width;
}

void LoBase::SetMinHeight(float height) {
  this->min_h = height;
}

void LoBase::SetMaxHeigth(float height) {
  this->max_h = height;
}

float LoBase::GetMinWidth() {
  return this->min_w;
}

float LoBase::GetMaxWidth() {
  return this->max_w;
}

float LoBase::GetMinHeight() {
  return this->min_h;
}

float LoBase::GetMaxHeight() {
  return this->max_h;
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

void LoBase::SetOnClick(std::function<void (Vector2 m_pos, MouseButtons b, void *arg)> fn) {
  this->on_click = new std::function<void (Vector2 m_pos, MouseButtons b, void *arg)>(fn);
}

void LoBase::SetOnScroll(std::function<void (Vector2 m_pos, float s, void *arg)> fn) {
  this->on_scroll = new std::function<void (Vector2 m_pos, float s, void *arg)>(fn);

}

void LoBase::SetOnHover(std::function<void (Vector2 m_pos, void *arg)> fn) {
  this->on_hover = new std::function<void (Vector2 m_pos, void *arg)>(fn);
}

void LoBase::OnClick(Vector2 mouse, MouseButtons b) {
  if (this->on_click != nullptr) {
    (*this->on_click)(mouse, b, nullptr);
  }
}

void LoBase::OnScroll(Vector2 mouse, float scroll) {
  if (this->on_scroll != nullptr) {
    (*this->on_scroll)(mouse, scroll, nullptr);
  }
}

void LoBase::OnHover(Vector2 mouse) {
  if (this->on_hover != nullptr) {
    (*this->on_hover)(mouse, nullptr);
  }
}

void LoBase::UpdateStateEvent(LoSignal &sig) {
  if (!this->IsInside(sig.mouse_pos)) {
    this->state = MouseState::None;
    this->event = MouseEvent::None;
    return;
  }

  if (sig.mouse_state != this->state) {
    MouseState curr_state = this->state;
    this->state = sig.mouse_state;

    if (this->state == MouseState::Hover) {
      switch(curr_state) {
        case MouseState::M1_Pressed:
          this->event = MouseEvent::M1_Released;
          break;
        case MouseState::M2_Pressed:
          this->event = MouseEvent::M2_Released;
          break;
        case MouseState::M3_Pressed:
          this->event = MouseEvent::M3_Released;
          break;
        case MouseState::M4_Pressed:
          this->event = MouseEvent::M4_Released;
          break;
        case MouseState::M5_Pressed:
          this->event = MouseEvent::M5_Released;
          break;
        default:
          break;
      }
    } else {
      switch(this->state) {
        case MouseState::M1_Pressed:
          this->event = MouseEvent::M1_Clicked;
          break;
        case MouseState::M2_Pressed:
          this->event = MouseEvent::M2_Clicked;
          break;
        case MouseState::M3_Pressed:
          this->event = MouseEvent::M3_Clicked;
          break;
        case MouseState::M4_Pressed:
          this->event = MouseEvent::M4_Clicked;
          break;
        case MouseState::M5_Pressed:
          this->event = MouseEvent::M5_Clicked;
          break;
        default:
          break;
      }
    }
  } else {
    this->event = MouseEvent::None;
  }
}

void LoBase::HandleSignal(LoSignal &sig) {
    this->UpdateStateEvent(sig);

  if (this->state != MouseState::None) {
    switch(this->event) {
      case MouseEvent::M1_Released:
        this->OnClick(sig.mouse_pos, MouseButtons::M1);
        break;
      case MouseEvent::M2_Released:
        this->OnClick(sig.mouse_pos, MouseButtons::M2);
      default:
        break;
    }
  
    if (sig.scroll != 0.0) {
      this->OnScroll(sig.mouse_pos, sig.scroll);
    }
  
    if (this->state == MouseState::Hover) {
      this->OnHover(sig.mouse_pos);
    }
  }
}
