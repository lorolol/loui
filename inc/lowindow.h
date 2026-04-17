#pragma once
#include <thread>
#include <raylib.h>

#include "lobase.h"
#include "locontainer.h"

class LoWindow : public LoContainer {
  private:
    Color bg;
    std::thread *main;

    void RlInitWindow();
    void WindowLoop();
    public:
    LoWindow(float w, float h, float pad[static_cast<int>(Pad::Len)], std::string &name, Color bg, std::vector<LoBase *> objs = {});
    LoWindow(float w, float h, std::string &name, Color bg, std::vector<LoBase *> objs = {});
    
    void Update(LoSignal &sig);
};