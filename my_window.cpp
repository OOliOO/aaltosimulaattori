#include "my_window.hpp"
#define UDF SDL_WINDOWPOS_UNDEFINED

MyWindow::MyWindow(std::string title, Uint32 width, Uint32 height){
    w=width;
    h=height;
    window=SDL_CreateWindow(title.c_str(), UDF, UDF, width, height, 0);
    renderer=SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC|SDL_RENDERER_TARGETTEXTURE);
    pixelit=new Uint32[w*h];
    for(Uint32 i=0; i<w*h; i++)
        pixelit[i]=COLOUR_0;

    screen=SDL_CreateTexture(renderer,SDL_PIXELFORMAT_ARGB8888,SDL_TEXTUREACCESS_STREAMING, w, h);
}

void MyWindow::update(){
    SDL_UpdateTexture(screen, NULL, pixelit, w*sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, screen, NULL, NULL);
}


void MyWindow::display(){
    SDL_RenderPresent(renderer);
    SDL_UpdateWindowSurface(window);
}

void MyWindow::drawPixel(Uint32 x, Uint32 y, Uint32 colour){
    if(x>=w||y>=h)
        return;
    pixelit[y*w+x]=colour;
}

void MyWindow::clearPixel(Uint32 x, Uint32 y){
    if(x>=w||y>=h)
        return;
    pixelit[y*w+x]=COLOUR_0;
}

void MyWindow::drawRect(const SDL_Rect* rect){
    if(rect==0)
        return;
    SDL_SetRenderDrawColor(renderer,125,255,125,255);
    SDL_RenderDrawRect(renderer,rect);
}
