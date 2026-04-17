#pragma once

#include "definitions.h"
#include "raymath.h"

struct LoSignal {
  enum class Type {
    Clicked,
    Hover,
    Scroll,
    Len,
  } type;
  
  Vector2 mouse_pos;
  MouseButtons button;
  float scroll;
};