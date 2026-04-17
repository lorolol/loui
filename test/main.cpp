#include "lowindow.h"
#include <unistd.h>

int main() {
  std::string title = "hello";
  LoWindow thing(800, 600, (float[4]){10.0, 10.0, 10.0, 10.0}, title, GRAY);

  for (;;) {
    sleep(1);
  }
}