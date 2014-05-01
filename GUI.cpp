#include "GUI.hpp"

GUI::GUI(int x, int y):
    ikkuna("Epilepsia-applet",x,y),
    pallerot(simulaatio.getPalleroiset()),
    poistetut(simulaatio.getPoistetut()),
    mouse_handler(simulaatio){}

void GUI::start(){
    while(mouse_handler.running()){
        simulaatio.update();
        piirra_pallerot();
        mouse_handler.update();
        ikkuna.update();
    }
}

void GUI::piirra_pallerot(){
    while(poistetut.size()){
        int a=poistetut.top();
        poistetut.pop();
        int x=a%MAX_WIDTH;
        int y=a/MAX_WIDTH;
        ikkuna.clearPixel(x,y);
    }
    for(auto a:pallerot){
        double diff=a.second->getPoikkeama();
        diff/=normitus;
        diff=std::min(1.,diff);
        diff=std::max(-1.,diff);

        Uint32 x=a.first%MAX_WIDTH;
        Uint32 y=a.first/MAX_WIDTH;

        Uint32 colour;
        if(diff>=0)
            colour=(255<<24)+((Uint32(255*diff))<<16);
        else
            colour=(255<<24)+(Uint32(-255*diff));
        ikkuna.drawPixel(x,y,colour);
    }
}
