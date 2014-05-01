#ifndef SIMULAATIO_HPP
#define SIMULAATIO_HPP
#include <unordered_map>
#include <stack>
#include "jousipallo.hpp"
#include "varahteleva_jousipallo.hpp"
#include "my_window.hpp"
#include "rect.hpp"
///////////////////////////////////////////
//tää on sitte se jossa kaikki ikään kuin//
//tapahtuu (vai tapahtuuko sittenkään..?)//
///////////////////////////////////////////

#define MAX_WIDTH 10000

class Simulaatio{
public:
    Simulaatio();
    void lisaaPallero(int x, int y);
    void lisaaPalleroita(int y0, int x0, int y1, int x1);
    void poistaPallero(int x, int y);
    void poistaPalleroita(int y0, int x0, int y1, int x1);
    void nollaaAalto(int x, int y);
    void nollaaAallot(int y0, int x0, int y1, int x1);
    const std::unordered_map<int, Jousipallo*>& getPalleroiset();
    std::stack<int>& getPoistetut();
    void update();
    void poikkeuta(double pakote, int y0, int x0, int y1, int x1);
    void heiluta(double A, double w, int y0, int x0, int y1, int x1);
    void pause();
private:
    Uint32 t_viimeks;
    std::unordered_map<int, Jousipallo*> palleroiset;
    //koordinaatit tunnettu clean code tyyliin yhteen inttiin ettei tartte määritellä hashia itte
    std::stack<int> poistetut;
    bool paused;

    void updateA();                     //updatee palleroisten kiihtyvyyden
    void zeroA();                       //nollaa palleroisten kiihtyvyyden
    void updateV(double t);             //updatee palleroisten nopeuden
    void updateSij(double t);           //updatee palleroisten sijainnin
    void try_updating(Jousipallo* a, int x, int y, double pakote);
};

#endif
