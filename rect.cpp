#include "rect.hpp"

Rect::Rect(int x0, int y0, int x1, int y1){
    this->x0=x0;
    this->y0=y0;
    this->x1=x1;
    this->y1=y1;
}

bool Rect::onkoSisalla(int x, int y){
    return x0<=x&&x<=x1&&y0<=y&&y<=y1;
}
