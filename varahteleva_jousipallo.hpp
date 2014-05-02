#ifndef VARAHTELEVA_JOUSIPALLO_HPP
#define VARAHTELEVA_JOUSIPALLO_HPP
#include "jousipallo.hpp"

class VarahtelevaJousipallo:public Jousipallo{
public:
    VarahtelevaJousipallo(double amplitudi, double kulmataajuus);
    void paivitaSij(double dt);
    void reset();
private:
    double t,A,w;
};

#endif
