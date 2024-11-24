#include "funvec.h"
#include <vector>
#include "algvec.h"

using namespace std;

#ifndef __equazione_differenziale__
#define __equazione_differenziale__

class eqdiffbase {
    public:
    virtual vector<double> step(double t, vector<double> state, double step, funvecbase& f) const=0;
};

class euler: public eqdiffbase {
    public:
    euler();
    ~euler();
    vector<double> step(double t, vector<double> state, double step, funvecbase& f) const override;
};

class rk4: public eqdiffbase {
public:
    rk4();
    ~rk4();
    vector<double> step(double t, vector<double> state, double step, funvecbase& f) const override;
};

#endif