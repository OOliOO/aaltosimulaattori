#include "jousipallo.hpp"

Jousipallo::Jousipallo(){
    reset();
}

void Jousipallo::paivitaA(Jousipallo *b, double d_taso){
    a+=k*(b->z-z)/d_taso;
}

void Jousipallo::vaimenna(){
    if(std::abs(b*v)>std::abs(a))
        a=0;
    else
        a-=b*v;
}

void Jousipallo::nollaaA(){
    a=0;
}

void Jousipallo::paivitaV(double t){
    v+=t*a;
}

void Jousipallo::paivitaSij(double t){
    z+=t*v;
}

double Jousipallo::getPoikkeama(){
    return z;
}

void Jousipallo::poikkeuta(double pakote){
    z=pakote;
}

void Jousipallo::reset(){
    a=v=z=0;
}
