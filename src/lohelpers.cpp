#include "lohelpers.h"
#include <vector>

std::string loui::ShellExec(std::string cmd) {
  FILE *p = popen(cmd.c_str(), "r");

  std::string res;
  char buff[128];
  while (fgets(buff, 128, p) != 0) {
    res += buff;
  }
  if (!res.empty()) res.pop_back();
  
  return res;
}

std::size_t loui::GetClosestSpace(std::string &text, Font &font, int font_size, float pos) {
  float closest_err {1000000000000.0};
  std::size_t err_i {};
  std::size_t last_space {};
  std::size_t last_new_line {};
  std::vector<std::size_t> new_lines {0};

  while (1) {
    last_new_line = text.find('\n', last_new_line);
    if (last_new_line == std::string::npos) break;
    new_lines.push_back(last_new_line);
  }

  
  for (std::size_t i {}; i < new_lines.size(); i++) {
    last_space = text.find(' ', new_lines[i]);
    last_new_line = new_lines[i];
    while (1) {
      if (last_space == std::string::npos ) break;
      if (i + 1 != new_lines.size()) {
        if (last_space > new_lines[i + 1]) break;
      }
      std::string t_str {text.substr(new_lines[i], new_lines[i] + last_space)};
      Vector2 t_size {MeasureTextEx(font, t_str.c_str(), font_size, 1)};
      float curr_err {pos - t_size.x};
      if (curr_err < closest_err) {
        closest_err = curr_err;
        err_i = last_space;
      }
      
      last_space = text.find(' ', last_space + 1);
    }

  }
  return err_i;
}
