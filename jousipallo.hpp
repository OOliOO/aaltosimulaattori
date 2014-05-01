#ifndef JOUSIPALLO_HPP
#define JOUSIPALLO_HPP
#include <cmath>
///////////////////////////////////////////////
//näitä asetellaan sitten pikseleiden kohtiin//
//pikselit tullaan värittämään sitten sillä////
//perusteella miten suuri poikkeama oikeasta///
//paikasta on//////////////////////////////////
///////////////////////////////////////////////

class Jousipallo{
public:
    Jousipallo();
    virtual ~Jousipallo(){}
    void paivitaA(Jousipallo* b, double d0);    //paivittää kiihtyvyyden
    void vaimenna();
    void nollaaA();                             //nollaa kiihtyvyyden (tarttee framejen välissä)
    void paivitaV(double t);                    //paivittää nopeuden
    virtual void paivitaSij(double t);          //paivittää sijainnin
    double getPoikkeama();                      //hakee poikkeaman
    void poikkeuta(double pakote);              //poikkeuttaa palloa
protected:
    double z;                                   //poikkeama
    double a,v;                                 //kiihtyvyys ja nopeus

    static constexpr double k=100;              //jousivakio
    static constexpr double b=0.05;             //vaimennusvakio
};

#endif
