#include "locontainer.h"

LoContainer::LoContainer(float x, float y, float w, float h, float pad[static_cast<int>(Pad::Len)], std::string &name, std::vector<LoBase *> objs) : 
LoBase(x, y, w, h, pad, name) {
  if (objs.size() != 0) {
    this->children.insert(this->children.end(), objs.begin(), objs.end());
  }
}

LoContainer::LoContainer(LoContainer *parent, float pad[static_cast<int>(Pad::Len)], std::string &name, std::vector<LoBase *> objs) :
LoBase(parent, pad, name) {
  if (objs.size() != 0) {
    this->children.insert(this->children.end(), objs.begin(), objs.end());
  }
}

LoContainer::LoContainer(LoContainer *parent, std::string &name, std::vector<LoBase *> objs) :
LoBase(parent, name) {
  if (objs.size() != 0) {
    this->children.insert(this->children.end(), objs.begin(), objs.end());
  }
}


LoBase *LoContainer::GetChildAt(int index) {
  if (index >= this->children.size()) return nullptr;
  return this->children[index];
}

void LoContainer::InsertChildAt(LoBase *obj, int index) {
  if (index >= this->children.size()) return;
  this->children.insert(this->children.begin() + index, 1, obj);
}

void LoContainer::AppendChild(LoBase *obj) {
  this->children.push_back(obj);
}

void LoContainer::AppendChildren(std::vector<LoBase *> objs) {
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
  for (auto &i : this->children) {
    if (i->IsInside(mouse)) {
      i->OnClick(mouse, b);
    }
  }
}

void LoContainer::OnScroll(Vector2 mouse, float scroll) {
  if (this->on_scroll != nullptr) {
    (*this->on_scroll)(mouse, scroll, nullptr);
  }
  for (auto &i : this->children) {
    if (i->IsInside(mouse)) {
      i->OnScroll(mouse, scroll);
    }
  }
}

void LoContainer::OnHover(Vector2 mouse) {
  if (this->on_hover != nullptr) {
    (*this->on_hover)(mouse, nullptr);
  }
  for (auto &i : this->children) {
    if (i->IsInside(mouse)) {
      i->OnHover(mouse);
    }
  }
}
