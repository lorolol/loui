#include "lolist.h"

LoList::LoList(float padding[static_cast<int>(Pad::Len)], std::string &name, int max_items, std::vector<LoBase *> objs) :
LoContainer(padding, name, objs) {
  this->max_i = max_items;
}

LoList::LoList(std::string &name, int max_items, std::vector<LoBase *> objs) :
LoContainer(name, objs) {
  this->max_i = max_items;
}

void LoList::SetMaxItems(int max_items) {
  this->max_i = max_items;
}

int LoList::GetMaxItems() {
  return this->max_i;
}

void LoList::Update(LoSignal &sig) {
  for (int i = 0; i < this->max_i; i++) {
    DrawRectangleLines(this->GetPosX() + this->GetPadding(Pad::Left),
                      this->GetPosY() + this->GetPadding(Pad::Top) + (i * (this->GetHeight() - (this->GetPadding(Pad::Top) + this->GetPadding(Pad::Bottom)))/this->max_i),
                      this->GetWidth() - (this->GetPadding(Pad::Left) + this->GetPadding(Pad::Right)),
                      (this->GetHeight() - (this->GetPadding(Pad::Top) + this->GetPadding(Pad::Bottom))) / max_i, 
                      BLUE);
  }
  for (auto &i : this->children) {
    i->SetPosX(this->GetPosX() + this->GetPadding(Pad::Left));
    i->SetPosY(this->GetPosY() + this->GetPadding(Pad::Top));
    
    i->SetWidth(this->GetWidth() - (this->GetPadding(Pad::Left) + this->GetPadding(Pad::Right)));
    i->SetHeight((this->GetHeight() - (this->GetPadding(Pad::Top) + this->GetPadding(Pad::Bottom))) / max_i);
    i->Update(sig);
  }
}