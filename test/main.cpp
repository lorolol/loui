#include "lowindow.h"
#include "lolist.h"
#include <unistd.h>

int main() {
  std::string title = "hello";
  std::string dude = "what the fuck";
  LoList thang((float[4]){10.0, 10.0, 10.0, 10.0}, dude, 3);
  LoList thang2((float[4]){1.0, 1.0, 1.0, 1.0}, dude, 4);
  thang.AppendChild(&thang2);
  LoWindow thing(800, 600, (float[4]){10.0, 10.0, 10.0, 10.0}, title, GRAY);
  thing.AppendChild(&thang);
  for (;;) {
    sleep(1);
  }
}