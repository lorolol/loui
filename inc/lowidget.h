#pragma once

#include "lobase.h"

class LoWidget : public LoBase {
  private:
    float min_w;
    float max_w;
    float min_h;
    float max_h;

  public:
    LoWidget(float pad[static_cast<int>(Pad::Len)], std::string name,
    float min_width, float max_width, float min_height, float max_height);
    LoWidget(std::string name, float min_width, float max_width, float min_height, float max_height);
    LoWidget(float pad[static_cast<int>(Pad::Len)], std::string name);

    void SetMinWidth(float width);
    void SetMaxWidth(float width);
    void SetMinHeight(float height);
    void SetMaxHeigth(float height);

    virtual void DrawHover() = 0;
    virtual void DrawClicked() = 0;
    virtual void DrawRegular() = 0;
    
    void Draw();
};