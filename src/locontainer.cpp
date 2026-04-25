#include "locontainer.h"

LoContainer::LoContainer(float x, float y, float w, float h, float pad[static_cast<int>(Pad::Len)], std::string &name, std::vector<LoBase *> objs) : 
LoBase(x, y, w, h, pad, name) {
  size_t j {};
  if (objs.size() != 0) {
    for (auto &i : objs) {
      i->SetParent(this);
      Child ch {i, j++};
      this->children.push_back(ch);
    }
  }
}

LoContainer::LoContainer(float pad[static_cast<int>(Pad::Len)], std::string &name, std::vector<LoBase *> objs) :
LoBase(pad, name) {
  if (objs.size() != 0) {
    size_t j {};
    for (auto &i : objs) {
      i->SetParent(this);
      Child ch {i, j++};
      this->children.push_back(ch);
    }
  }
}

LoContainer::LoContainer(std::string &name, std::vector<LoBase *> objs) :
LoBase(name) {
  if (objs.size() != 0) {
    size_t j {};
    for (auto &i : objs) {
      i->SetParent(this);
      Child ch {i, j++};
      this->children.push_back(ch);
    }
  }
}

LoBase *LoContainer::GetChildAt(int index) {
  for (auto &i : this->children) {
    if (i.i == index) return i.obj;
  }
  return nullptr;
}

void LoContainer::InsertChildAt(LoBase *obj, int index) {
  obj->SetParent(this);
  Child c {obj, index};
  for (auto &i : this->children) {
    if (i.i > index) i.i++;
  }
  this->children.push_back(c);
}

void LoContainer::AppendChild(LoBase *obj) {
  obj->SetParent(this);
  size_t max_index {};
  for (auto &i : this->children) {
    if (i.i > max_index) max_index = i.i;
  }

  Child c {obj, max_index};
  this->children.push_back(c);
}

void LoContainer::AppendChildren(std::vector<LoBase *> objs) {
  size_t j {};
  for (auto &i : objs) {
    i->SetParent(this);
    Child ch {i, j++};
    this->children.push_back(ch);
  }
}

void LoContainer::Draw() {
  for (auto &i : this->children) {
    i.obj->Draw();
  }
}

void LoContainer::HandleSignal(LoSignal &sig) {
  LoBase::HandleSignal(sig);

  for (auto &i : this->children) {
    i.obj->HandleSignal(sig);
  }
}
