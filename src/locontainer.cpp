#include "locontainer.h"

LoContainer::LoContainer() {

}
LoContainer::LoContainer(LoBase *objs) {

}

LoBase &LoContainer::GetChildAt(int index) {

}
void LoContainer::InsertChildAt(LoBase &obj, int index) {

}

void LoContainer::AppendChild(LoBase &obj) {

}

void LoContainer::Draw() {
  for (auto &i : this->children) {
    i.Draw();
  }
}

void LoContainer::OnClick(Vector2 mouse, MouseButtons b) {

}

void LoContainer::OnScroll(Vector2 mouse, float scroll) {

}

void LoContainer::OnHover(Vector2 mouse) {

}
