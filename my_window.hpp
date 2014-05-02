#ifndef MY_WINDOW_HPP
#define MY_WINDOW_HPP

#include <iostream>
#include <SDL2/SDL.h>

///////////////////////////////////////////////////////////
//Classi joka wrappaa SDL windowin sellaseen muotoon että//
//pikselimanipulaatio on helppoa ja että normimuotojen/////
//Piirtäminen onnistuu suuremmitta ongelmitta./////////////
//Ei ehkä yleiskäyttöisin classi mutta ajanee asiansa//////
///////////////////////////////////////////////////////////

class MyWindow{
public:
    MyWindow(std::string title, Uint32 width, Uint32 height);

    void update();
    void drawPixel(Uint32 x, Uint32 y, Uint32 color);
    void clearPixel(Uint32 x, Uint32 y);
    void drawRect(const SDL_Rect* rect);
    void display();
private:
    Uint32 w,h;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* screen;
    Uint32* pixelit;

    static constexpr Uint32 COLOUR_0=(255<<16)+(255<<8)+255;
};

#endif
