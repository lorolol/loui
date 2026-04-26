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

    float min_w;
    float max_w;
    float min_h;
    float max_h;
    
    float pad[static_cast<int>(Pad::Len)];

    Align::Horizontal align_h;
    Align::Vertical align_v;
    
  protected:
    std::function<void (Vector2 m_pos, MouseButtons b, void *arg)> *on_click;
    std::function<void (Vector2 m_pos, float s, void *arg)> *on_scroll;
    std::function<void (Vector2 m_pos, void *arg)> *on_hover;
    
    MouseState state;
    MouseEvent event;
    
    LoBase(float x, float y, float w, float h, float pad[static_cast<int>(Pad::Len)], std::string &name);
  public:
    LoBase(float pad[static_cast<int>(Pad::Len)], std::string &name);
    LoBase(std::string &name);
    virtual ~LoBase() = default;
    
    void SetParent(LoBase *parent);
    LoBase *GetParent();
    
    Align::Horizontal GetAlignmentHorizontal();
    Align::Vertical GetAlignmentVertical();
    
    float GetPosX();
    float GetPosY();
    void SetPosX(float x);
    void SetPosY(float y);
    
    float GetWidth();
    float GetHeight();
    void SetWidth(float width);
    void SetHeight(float height);
    void SetMinWidth(float width);
    void SetMaxWidth(float width);
    void SetMinHeight(float height);
    void SetMaxHeigth(float height);
    
    float GetMinWidth();
    float GetMaxWidth();
    float GetMinHeight();
    float GetMaxHeight();
    
    bool IsInside(Vector2 point);
    
    std::string &GetName();
    void SetName(std::string &name);
    
    float GetPadding(Pad side);
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