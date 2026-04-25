#pragma once
#include <functional>
#include <string>

#include "raymath.h"
#include "definitions.h"
#include "losignal.h"

class LoBase {
  private:
    LoBase *parent;

    std::string name;

    float x;
    float y;

    float w;
    float h;
    
    float pad[static_cast<int>(Pad::Len)];

    Align::Horizontal align_h;
    Align::Vertical align_v;
    
  public:
    LoBase(float pad[static_cast<int>(Pad::Len)], std::string &name);
    LoBase(std::string &name);
    virtual ~LoBase() = default;
    
    std::string &GetName();
    
    float GetPosX();
    float GetPosY();
    
    float GetWidth();
    float GetHeight();
    
    float GetPadding(Pad side);

    void SetParent(LoBase *parent);
    LoBase *GetParent();
    
    Align::Horizontal GetAlignmentHorizontal();
    Align::Vertical GetAlignmentVertical();

  protected:
    std::function<void (Vector2 m_pos, MouseButtons b, void *arg)> *on_click;
    std::function<void (Vector2 m_pos, float s, void *arg)> *on_scroll;
    std::function<void (Vector2 m_pos, void *arg)> *on_hover;
    
    MouseState state;
    MouseEvent event;
    
    LoBase(float x, float y, float w, float h, float pad[static_cast<int>(Pad::Len)], std::string &name);

  public:
    void SetPosX(float x);
    void SetPosY(float y);

    void SetWidth(float width);
    void SetHeight(float height);
    bool IsInside(Vector2 point);
    void SetName(std::string &name);


    void SetPadding(Pad side, float pad);
  
    void SetAlignmentHorizontal(Align::Horizontal alignment);
    void SetAlignmentVertical(Align::Vertical alignment);

    void SetOnClick(std::function<void (Vector2 m_pos, MouseButtons b, void *arg)> fn);
    void SetOnScroll(std::function<void (Vector2 m_pos, float s, void *arg)> fn);
    void SetOnHover(std::function<void (Vector2 m_pos, void *arg)> fn);
  
    void UpdateStateEvent(LoSignal &sig);

    virtual void OnClick(Vector2 mouse, MouseButtons b);
    virtual void OnScroll(Vector2 mouse, float scroll);
    virtual void OnHover(Vector2 mouse);

    virtual void Update(LoSignal &sig) = 0;
    virtual void Draw() = 0;
    virtual void HandleSignal(LoSignal &sig);
};