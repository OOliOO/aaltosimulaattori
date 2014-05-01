#include "varahteleva_jousipallo.hpp"
#include <iostream>
VarahtelevaJousipallo::VarahtelevaJousipallo(double amplitudi, double kulmataajuus){
    A=amplitudi;
    w=kulmataajuus;
    t=0;
}

void VarahtelevaJousipallo::paivitaSij(double dt){
    t+=dt;
    z=A*sin(w*t);
}
