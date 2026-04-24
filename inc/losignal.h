#pragma once

#include "definitions.h"
#include "raymath.h"

struct LoSignal {
  Vector2 mouse_pos;
  MouseButtons button;
  float scroll;
};

enum class State {
  M1_Pressed,
  M2_Pressed,
  M3_Pressed,
  M4_Pressed,
  M5_Pressed,
  Hover,
  Len,
  None
};

enum class Event {
  M1_Clicked,
  M2_Clicked,
  M3_Clicked,
  M4_Clicked,
  M5_Clicked,
  M1_Released,
  M2_Released,
  M3_Released,
  M4_Released,
  M5_Released,
  Len,
  None
};