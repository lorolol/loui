#include "locontainer.h"

LoContainer::LoContainer(float x, float y, float w, float h, float pad[static_cast<int>(Pad::Len)], std::string &name, std::vector<LoBase *> objs) : 
LoBase(x, y, w, h, pad, name) {
  if (objs.size() != 0) {
    for (auto &i : objs) {
      i->SetParent(this);
    }
    this->children.insert(this->children.end(), objs.begin(), objs.end());
  }
}

LoContainer::LoContainer(float pad[static_cast<int>(Pad::Len)], std::string &name, std::vector<LoBase *> objs) :
LoBase(pad, name) {
  if (objs.size() != 0) {
    for (auto &i : objs) {
      i->SetParent(this);
    }
    this->children.insert(this->children.end(), objs.begin(), objs.end());
  }
}

LoContainer::LoContainer(std::string &name, std::vector<LoBase *> objs) :
LoBase(name) {
  if (objs.size() != 0) {
    for (auto &i : objs) {
      i->SetParent(this);
    }
    this->children.insert(this->children.end(), objs.begin(), objs.end());
  }
}

LoBase *LoContainer::GetChildAt(int index) {
  if (index >= this->children.size()) return nullptr;
  return this->children[index];
}

void LoContainer::InsertChildAt(LoBase *obj, int index) {
  if (index >= this->children.size()) return;
  obj->SetParent(this);
  this->children.insert(this->children.begin() + index, 1, obj);
}

void LoContainer::AppendChild(LoBase *obj) {
  obj->SetParent(this);
  this->children.push_back(obj);
}

void LoContainer::AppendChildren(std::vector<LoBase *> objs) {
  for (auto &i : objs) {
    i->SetParent(this);
  }
  this->children.insert(this->children.end(), objs.begin(), objs.end());
}

void LoContainer::Draw() {
  for (auto &i : this->children) {
    i->Draw();
  }
}

void LoContainer::OnClick(Vector2 mouse, MouseButtons b) {
  if (this->on_click != nullptr) {
    (*this->on_click)(mouse, b, nullptr);
  }
}

void LoContainer::OnScroll(Vector2 mouse, float scroll) {
  if (this->on_scroll != nullptr) {
    (*this->on_scroll)(mouse, scroll, nullptr);
  }
}

void LoContainer::OnHover(Vector2 mouse) {
  if (this->on_hover != nullptr) {
    (*this->on_hover)(mouse, nullptr);
  }
}

void LoContainer::HandleSignal(LoSignal &sig) {
  this->UpdateStateEvent(sig);

  if (this->state != MouseState::None) {
    switch(this->event) {
      case MouseEvent::M1_Released:
        this->OnClick(sig.mouse_pos, MouseButtons::M1);
        break;
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

  for (auto &i : this->children) {
    i->HandleSignal(sig);
  }
}
