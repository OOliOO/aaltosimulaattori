#ifndef MOUSE_HANDLER_HPP
#define MOUSE_HANDLER_HPP
//////////////////////////////////////////
//kattoo kaiken mitä hiiri tekee//////////
//nappien painot, alueiden maalauxet jne//
//vois myös tehtä 1000 eri classia jotka//
//perii jonkun helvetin yleisen(!!)///////
//ja saatana sitten ois ihan vitun clean//
//code////////////////////////////////////
//////////////////////////////////////////

//////////////////////////////////////////
//no tästä tulikin sitten ilmeisesti//////
//event handleri :Dd//////////////////////
//////////////////////////////////////////

#include "simulaatio.hpp"
#include <SDL2/SDL.h>

class MouseHandler{
public:
    MouseHandler(Simulaatio& simulaatio);
    void update();
    bool running();
private:
    Simulaatio& simulaatio;
    bool was_down;
    int x0,y0;
    Uint32 which;
    bool is_running;
    int mode;
    int edit_mode;
    double w_A=10, p_A=20, w_w=3;
    void edit_parameters(int a);
};

#endif
