#pragma once
#include <vector>

#include "lobase.h"

class LoContainer : public LoBase {
  protected:
    struct Child {
      LoBase* obj;
      size_t i;
    };
    std::vector<Child> children;
    // only for top level containers like Window
    LoContainer(float x, float y, float w, float h, float pad[static_cast<int>(Pad::Len)], std::string &name, std::vector<LoBase *> objs = {});
  public:
    LoContainer(float pad[static_cast<int>(Pad::Len)], std::string &name, std::vector<LoBase *> objs = {});
    LoContainer(std::string &name, std::vector<LoBase *> objs = {});

    virtual ~LoContainer() = default;

    LoBase *GetChildAt(int index);
    void InsertChildAt(LoBase *obj, int index);
    void AppendChild(LoBase *obj);
    void AppendChildren(std::vector<LoBase *> objs);

    void Draw();

    void HandleSignalThis(LoSignal &sig);
};