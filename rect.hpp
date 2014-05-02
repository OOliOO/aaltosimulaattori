#ifndef RECT_HPP
#define RECT_HPP

//////////////////////////////
//I'll rek u m8, cum here m8//
//////////////////////////////

class Rect{
public:
    Rect(int x0, int y0, int x1, int y1);   //x0<=x1 && y0<=y1 plz
    bool onkoSisalla(int x, int y);
private:
    int x0,x1,y0,y1;
};

#endif
