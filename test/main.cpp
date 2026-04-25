#include "lowindow.h"
#include "lolist.h"
#include "lotextbox.h"
#include <unistd.h>

void OnClick(Vector2 mouse, MouseButtons b, void *a) {
  printf("goated1\n");
}

void OnClick2(Vector2 mouse, MouseButtons b, void *a) {
  printf("goated2\n");
}

int main() {
  std::string title = "hello";
  std::string dude = "what the fuck";
  LoList thang((float[4]){10.0, 10.0, 10.0, 10.0}, dude, 3);
  thang.SetOnClick(OnClick);

  LoTextBox text("gameing", 80);
  LoTextBox text2("gaming", 80);
  text.SetText("THIS IS CRAZY");
  text2.SetText("CRAZY BALLS");
  int thanger1 {};
  int thanger2 {};
  text.SetOnClick([&thanger1, &text](Vector2 m_pos, MouseButtons b, void * arg) {
    if (b == MouseButtons::M1) thanger1++;
    else thanger1--;
    text.SetText(std::to_string(thanger1));
  });
  text2.SetOnClick([&thanger2, &text2](Vector2 m_pos, MouseButtons b, void * arg) {
    if (b == MouseButtons::M1) thanger2++;
    else thanger2--;
    text2.SetText(std::to_string(thanger2));
  });

  thang.AppendChild(&text);
  thang.InsertChildAt(&text2, 2);
  LoWindow thing(800, 600, (float[4]){10.0, 10.0, 10.0, 10.0}, title, GRAY);
  thing.AppendChild(&thang);
  for (;;) {
    sleep(1);
  }
}