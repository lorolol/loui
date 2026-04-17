#pragma once

enum class MouseButtons {
  Left,
  Right,
  Middle,
  M4,
  M5,
  Len,
  None
};

enum class Pad : int {
  Top,
  Bottom,
  Left,
  Right,
  Len
};

class Align  {
  public:
    enum class Vertical {
      Top,
      Bottom,
      Center,
      Len
    };

    enum class Horizontal {
      Left,
      Right,
      Center,
      Len
    };
};

