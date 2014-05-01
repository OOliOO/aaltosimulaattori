#ifndef GUI_HPP
#define GUI_HPP
#include "my_window.hpp"
#include "simulaatio.hpp"
#include "mouse_handler.hpp"
#include <algorithm>

class GUI{
public:
    GUI(int x, int y);
    void start();
private:
    MyWindow ikkuna;
    Simulaatio simulaatio;
    const std::unordered_map<int, Jousipallo*>& pallerot;
    std::stack<int>& poistetut;
    MouseHandler mouse_handler;
    void piirra_pallerot();

    static constexpr double normitus=10;
};

#endif
