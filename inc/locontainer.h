#pragma once
#include <vector>

#include "lobase.h"

class LoContainer : LoBase {
  private:
    std::vector<LoBase> children;

  public:
    LoContainer();
    LoContainer(LoBase *objs);
    virtual ~LoContainer() = default;

    LoBase &GetChildAt(int index);
    void InsertChildAt(LoBase &obj, int index);
    void AppendChild(LoBase &obj);

    void Draw();
    void OnClick(Vector2 mouse, MouseButtons b);
    void OnScroll(Vector2 mouse, float scroll);
    void OnHover(Vector2 mouse);
};