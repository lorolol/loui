#include "lolist.h"

LoList::LoList(float padding[static_cast<int>(Pad::Len)], std::string &name, int max_items, std::vector<LoBase *> objs) :
LoContainer(padding, name, objs) {
  this->max_i = max_items;
  this->children.reserve(max_items);
}

LoList::LoList(std::string &name, int max_items, std::vector<LoBase *> objs) :
LoContainer(name, objs) {
  this->max_i = max_items;
  this->children.reserve(max_items);
}

void LoList::SetMaxItems(int max_items) {
  this->max_i = max_items;
  this->children.reserve(max_items);
}

int LoList::GetMaxItems() {
  return this->max_i;
}

void LoList::SetElementPadding(float padding) {
  this->e_pad = padding;
}

float LoList::GetElementPadding() {
  return this->e_pad;
}

void LoList::Update(LoSignal &sig) {
  float total_space {this->GetHeight() - (this->GetPadding(Pad::Top) + this->GetPadding(Pad::Bottom))};
  float space_left {total_space};

  auto j = this->children.size() - 1;
  for (auto &i : this->children) {
    float item_h {space_left/this->children.size()};
    if (i.obj->GetMinHeight() > item_h) {
      item_h = i.obj->GetMinHeight();
    } else if (i.obj->GetMaxHeight() < item_h && i.obj->GetMaxHeight() != 0) {
      item_h = i.obj->GetMaxHeight();
    }
    if (item_h > space_left) item_h = space_left;
    if (j == 0) item_h = space_left;
    i.obj->SetPosX(this->GetPosX() + this->GetPadding(Pad::Left));
    i.obj->SetPosY(this->GetPosY() + this->GetPadding(Pad::Top) + (total_space - space_left));
    
    i.obj->SetWidth(this->GetWidth() - (this->GetPadding(Pad::Left) + this->GetPadding(Pad::Right)));
    i.obj->SetHeight(item_h);
    i.obj->Update(sig);

    space_left -= item_h + this->e_pad;
    j--;
  }
}