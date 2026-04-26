#pragma once

#include "lobase.h"

class LoWidget : public LoBase {
  private:

  public:
    LoWidget(float pad[static_cast<int>(Pad::Len)], std::string name,
    float min_width = 0.0, float max_width = 0.0, float min_height = 0.0, float max_height = 0.0);
    LoWidget(std::string name, float min_width = 0.0, float max_width = 0.0, float min_height = 0.0, float max_height = 0.0);

    virtual void DrawHover() = 0;
    virtual void DrawClicked() = 0;
    virtual void DrawRegular() = 0;
    
    void Draw();
};