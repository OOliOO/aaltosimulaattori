#include "simulaatio.hpp"
#include <SDL2/SDL.h>

Simulaatio::Simulaatio(){
    t_viimeks=SDL_GetTicks();
    paused=0;
}

void Simulaatio::lisaaPallero(int x, int y){
    int key=y*MAX_WIDTH+x;
    if(!palleroiset.count(key))
        palleroiset[key]=new Jousipallo();
}

void Simulaatio::lisaaPalleroita(int x0, int y0, int x1, int y1){
    for(int i=y0; i<=y1; i++)
        for(int e=x0; e<=x1; e++)
            lisaaPallero(i,e);
}

void Simulaatio::poistaPallero(int x, int y){
    int key=y*MAX_WIDTH+x;
    if(palleroiset.count(key)){
        delete palleroiset[key];
        palleroiset.erase(key);
        poistetut.push(key);
    }
}

void Simulaatio::poistaPalleroita(int x0, int y0, int x1, int y1){
    for(int i=y0; i<=y1; i++)
        for(int e=x0; e<=x1; e++)
            poistaPallero(i,e);
}

void Simulaatio::nollaaAalto(int x, int y){
    int key=y*MAX_WIDTH+x;
    if(palleroiset.count(key)){
        delete palleroiset[key];
        palleroiset[key]=new Jousipallo();
    }
}

void Simulaatio::nollaaAallot(int x0, int y0, int x1, int y1){
    for(int i=y0; i<=y1; i++)
        for(int e=x0; e<=x1; e++)
            nollaaAalto(i,e);
}

void Simulaatio::pause(){
    paused=!paused;
}

void Simulaatio::update(){
    Uint32 t_diff=SDL_GetTicks()-t_viimeks;
    t_viimeks=SDL_GetTicks();

    if(paused)
        return;

    double t=t_diff*1.0/1000;
    updateA();
    updateV(t);
    updateSij(t);
    zeroA();
}

void Simulaatio::updateA(){
    for(auto a:palleroiset){
        int key=a.first;
        int x=key%MAX_WIDTH;
        int y=key/MAX_WIDTH;
        try_updating(palleroiset[key],x+1,y,1);
        try_updating(palleroiset[key],x-1,y,1);
        try_updating(palleroiset[key],x,y+1,1);
        try_updating(palleroiset[key],x,y-1,1);
        try_updating(palleroiset[key],x+1,y+1,1.4142);
        try_updating(palleroiset[key],x-1,y+1,1.4142);
        try_updating(palleroiset[key],x+1,y-1,1.4142);
        try_updating(palleroiset[key],x-1,y-1,1.4142);
        palleroiset[key]->vaimenna();
    }
}

void Simulaatio::zeroA(){
    for(auto a:palleroiset){
        int key=a.first;
        palleroiset[key]->nollaaA();
    }
}

void Simulaatio::updateV(double t){
    for(auto a:palleroiset){
        int key=a.first;
        palleroiset[key]->paivitaV(t);
    }
}

void Simulaatio::updateSij(double t){
    for(auto a:palleroiset){
        int key=a.first;
        palleroiset[key]->paivitaSij(t);
    }
}

const std::unordered_map<int, Jousipallo*>& Simulaatio::getPalleroiset(){
    return palleroiset;
}

std::stack<int>& Simulaatio::getPoistetut(){
    return poistetut;
}

void Simulaatio::try_updating(Jousipallo* a, int x, int y, double pakote){
    if(x<0||y<0)
        return;
    int key=y*MAX_WIDTH+x;
    if(palleroiset.count(key)){
        a->paivitaA(palleroiset[key],pakote);
    }
}

void Simulaatio::poikkeuta(double pakote, int y0, int x0, int y1, int x1){
    //jooh, vähän bloatti, mutta worst case asymptioottisesti optimi
    //joten ei välii :Dd

    Rect alue(x0, y0, x1, y1);

    for(auto a:palleroiset){
        int key=a.first;
        int x=key%MAX_WIDTH;
        int y=key/MAX_WIDTH;
        if(alue.onkoSisalla(x,y))
            palleroiset[key]->poikkeuta(pakote);
    }
}

void Simulaatio::heiluta(double A, double w, int y0, int x0, int y1, int x1){
    Rect alue(x0, y0, x1, y1);

    for(auto a:palleroiset){
        int key=a.first;
        int x=key%MAX_WIDTH;
        int y=key/MAX_WIDTH;
        if(alue.onkoSisalla(x,y)){
            delete palleroiset[key];
            palleroiset[key]=new VarahtelevaJousipallo(A,w);
        }
    }
}


