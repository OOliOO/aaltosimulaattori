#include "varahteleva_jousipallo.hpp"
#include <iostream>
VarahtelevaJousipallo::VarahtelevaJousipallo(double amplitudi, double kulmataajuus){
    A=amplitudi;
    w=kulmataajuus;
    reset();
}

void VarahtelevaJousipallo::paivitaSij(double dt){
    t+=dt;
    z=A*sin(w*t);
}

void VarahtelevaJousipallo::reset(){
    t=0;
}
