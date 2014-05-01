#include "mouse_handler.hpp"

MouseHandler::MouseHandler(Simulaatio& simulaatio):simulaatio(simulaatio){
    was_down=0;
    is_running=1;
    mode=0;
    edit_mode=0;
}

bool MouseHandler::running(){
    return is_running;
}

void MouseHandler::update(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type==SDL_QUIT)
            is_running=0;
        if(event.type==SDL_MOUSEBUTTONDOWN){
            if(was_down)    //hommat on kesken, älä sinä häiritse saatana
                continue;

            if(event.button.button==SDL_BUTTON_LEFT)
                which=SDL_BUTTON_LEFT;
            if(event.button.button==SDL_BUTTON_RIGHT)
                which=SDL_BUTTON_RIGHT;
            was_down=1;
            x0=event.button.x;
            y0=event.button.y;
        }

        if(event.type==SDL_MOUSEBUTTONUP){
            if(!was_down)   //emt mix
                continue;
            if(event.button.button==which){
                if(event.button.button==SDL_BUTTON_LEFT){
                    int x=event.button.x;
                    int y=event.button.y;
                    if(mode==0)
                        simulaatio.lisaaPalleroita(
                            std::min(y,y0),
                            std::min(x,x0),
                            std::max(y,y0),
                            std::max(x,x0));
                    if(mode==1)
                        simulaatio.heiluta(w_A,w_w,
                            std::min(y,y0),
                            std::min(x,x0),
                            std::max(y,y0),
                            std::max(x,x0));
                    if(mode==2)
                        simulaatio.poikkeuta(p_A,
                            std::min(y,y0),
                            std::min(x,x0),
                            std::max(y,y0),
                            std::max(x,x0));
                    if(mode==3)
                        simulaatio.nollaaAallot(
                            std::min(y,y0),
                            std::min(x,x0),
                            std::max(y,y0),
                            std::max(x,x0));
                }
                if(event.button.button==SDL_BUTTON_RIGHT){
                    int x=event.button.x;
                    int y=event.button.y;
                    simulaatio.poistaPalleroita(
                        std::min(y,y0),
                        std::min(x,x0),
                        std::max(y,y0),
                        std::max(x,x0));
                }
                was_down=0;
            }
        }
        if(event.type==SDL_KEYDOWN){
            if(event.key.keysym.sym==SDLK_b)
                mode=0;
            if(event.key.keysym.sym==SDLK_w)
                mode=1;
            if(event.key.keysym.sym==SDLK_p)
                mode=2;
            if(event.key.keysym.sym==SDLK_c)
                mode=3;
            if(event.key.keysym.sym==SDLK_1)
                edit_parameters(1);
            if(event.key.keysym.sym==SDLK_2)
                edit_parameters(2);
            if(event.key.keysym.sym==SDLK_3)
                edit_parameters(3);
            if(event.key.keysym.sym==SDLK_4)
                edit_parameters(4);
            if(event.key.keysym.sym==SDLK_5)
                edit_parameters(5);
            if(event.key.keysym.sym==SDLK_6)
                edit_parameters(6);
            if(event.key.keysym.sym==SDLK_7)
                edit_parameters(7);
            if(event.key.keysym.sym==SDLK_8)
                edit_parameters(8);
            if(event.key.keysym.sym==SDLK_9)
                edit_parameters(9);
            if(event.key.keysym.sym==SDLK_0)
                edit_parameters(10);
            if(event.key.keysym.sym==SDLK_f)
                edit_mode=0;
            if(event.key.keysym.sym==SDLK_i)
                edit_mode=1;
            if(event.key.keysym.sym==SDLK_a)
                edit_mode=2;
            if(event.key.keysym.sym==SDLK_SPACE)
                simulaatio.pause();
        }
    }
}

void MouseHandler::edit_parameters(int a){
    if(edit_mode==0)
        w_w=a;
    if(edit_mode==1)
        p_A=a*4;
    if(edit_mode==2)
        w_A=a*2;
}
