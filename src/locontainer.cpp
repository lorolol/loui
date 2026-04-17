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

void LoContainer::HandleSignal(LoSignal &sig) {
  if (sig.button != MouseButtons::None && this->on_click != nullptr) {
    (*this->on_click)(sig.mouse_pos, sig.button, nullptr);
  }
  if (this->on_hover != nullptr) {
    (*this->on_hover)(sig.mouse_pos, nullptr);
  }
  if (sig.scroll != 0 && this->on_hover != nullptr) {
    (*this->on_scroll)(sig.mouse_pos, sig.scroll, nullptr);
  }

  for (auto &i : this->children) {
    if (i->IsInside(sig.mouse_pos)) {
      i->HandleSignal(sig);
    }
  }
}
