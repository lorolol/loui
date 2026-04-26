#pragma once

#include <raylib.h>

#include "lobase.h"
#include "locontainer.h"

class LoList : public LoContainer {
  private:
    int max_i;
    float e_pad;

  public:
    LoList(float padding[static_cast<int>(Pad::Len)], std::string &name, int max_items, std::vector<LoBase *> objs = {});
    LoList(std::string &name, int max_items, std::vector<LoBase *> objs = {});
    void SetMaxItems(int max_items);
    int GetMaxItems();

    void SetElementPadding(float padding);
    float GetElementPadding();

    void Update(LoSignal &sig);
};