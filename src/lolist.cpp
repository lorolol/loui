#include "lolist.h"

LoList::LoList(float padding[static_cast<int>(Pad::Len)], std::string &name, int max_items, std::vector<LoBase *> objs) :
LoContainer(padding, name, objs) {
  this->max_i = max_items;
  this->children.reserve(max_items);
  // this->children.assign(max_items, nullptr);

}

LoList::LoList(std::string &name, int max_items, std::vector<LoBase *> objs) :
LoContainer(name, objs) {
  this->max_i = max_items;
  this->children.reserve(max_items);
  // this->children.assign(max_items, nullptr);
}

void LoList::SetMaxItems(int max_items) {
  this->max_i = max_items;
  this->children.reserve(max_items);
  // this->children.assign(max_items, nullptr);

}

int LoList::GetMaxItems() {
  return this->max_i;
}

void LoList::Update(LoSignal &sig) {
  float item_h {(this->GetHeight() - (this->GetPadding(Pad::Top) + this->GetPadding(Pad::Bottom)))/this->max_i};
  for (int i = 0; i < this->max_i; i++) {
    DrawRectangleLines(this->GetPosX() + this->GetPadding(Pad::Left),
                      this->GetPosY() + this->GetPadding(Pad::Top) + (i * item_h),
                      this->GetWidth() - (this->GetPadding(Pad::Left) + this->GetPadding(Pad::Right)),
                      (this->GetHeight() - (this->GetPadding(Pad::Top) + this->GetPadding(Pad::Bottom))) / max_i, 
                      BLUE);
  }
  for (auto &i : this->children) {
    i.obj->SetPosX(this->GetPosX() + this->GetPadding(Pad::Left));
    i.obj->SetPosY(this->GetPosY() + this->GetPadding(Pad::Top) + (i.i * item_h));
    
    i.obj->SetWidth(this->GetWidth() - (this->GetPadding(Pad::Left) + this->GetPadding(Pad::Right)));
    i.obj->SetHeight((this->GetHeight() - (this->GetPadding(Pad::Top) + this->GetPadding(Pad::Bottom))) / max_i);
    i.obj->Update(sig);
    
  }
}