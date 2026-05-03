#pragma once

#include <string>

#include "raylib.h"

namespace loui {
  std::string ShellExec(std::string cmd);
  std::size_t GetClosestSpace(std::string &text, Font &font, int font_size, float pos);
}
