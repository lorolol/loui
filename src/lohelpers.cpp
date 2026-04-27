#include "lohelpers.h"

std::string ShellExec(std::string cmd) {
  FILE *p = popen(cmd.c_str(), "r");

  std::string res;
  char buff[128];
  while (fgets(buff, 128, p) != 0) {
    res += buff;
  }
  if (!res.empty()) res.pop_back();
  
  return res;
}
