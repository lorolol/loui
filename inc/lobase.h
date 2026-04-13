#pragma once
#include <functional>
#include <string>

#include "definitions.h"
#include "losignal.h"
#include "raymath.h"

class LoBase {
  private:
    std::string name;

    float x;
    float y;

    float w;
    float h;
    
    float pad[static_cast<int>(Pad::Len)];

    Align::Horizontal align_h;
    Align::Vertical align_v;

    std::function<void (Vector2 m_pos, MouseButtons b, void *arg)> *on_click;
    std::function<void (Vector2 m_pos, float s, void *arg)> *on_scroll;
    std::function<void (Vector2 m_pos, void *arg)> *on_hover;

  public:
    LoBase(float x, float y, float w, float h, float pad[static_cast<int>(Pad::Len)], std::string &name);
    virtual ~LoBase() = default;

    std::string &GetName();

    float GetPosX();
    float GetPosY();

    float GetWidth();
    float GetHeight();
    
    float GetPadding(Pad side);
    
    Align::Horizontal GetAlignmentHorizontal();
    Align::Vertical GetAlignmentVertical();
  protected:
    void SetPosX(float x);
    void SetPosY(float y);

    void SetWidth(float width);
    void SetHeight(float height);
  public:
    void SetName(std::string &name);


    void SetPadding(Pad side, float pad);
  
    void SetAlignmentHorizontal(Align::Horizontal alignment);
    void SetAlignmentVertical(Align::Vertical alignment);

    void HandleSignal(LoSignal sig);

    void SetOnClick(std::function<void (Vector2 m_pos, MouseButtons b, void *arg)> &fn);
    void SetOnScroll(std::function<void (Vector2 m_pos, float s, void *arg)> &fn);
    void SetOnHover(std::function<void (Vector2 m_pos, void *arg)> &fn);

    virtual void Draw() = 0;
    virtual void OnClick(Vector2 mouse, MouseButtons b) = 0;
    virtual void OnScroll(Vector2 mouse, float scroll) = 0;
    virtual void OnHover(Vector2 mouse) = 0;
};