#pragma once
#include <vector>

#include "lobase.h"

class LoContainer : public LoBase {
  protected:
    std::vector<LoBase *> children;
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
    virtual void OnClick(Vector2 mouse, MouseButtons b);
    virtual void OnScroll(Vector2 mouse, float scroll);
    virtual void OnHover(Vector2 mouse);

    void HandleSignal(LoSignal &sig);
};