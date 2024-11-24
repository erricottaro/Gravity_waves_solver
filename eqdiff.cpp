#include "eqdiff.h"
#include "algvec.h"

using namespace std;

//metodo di eulero
euler::euler() {};
euler::~euler() {};
//metodo per la risoluzione dell'eq diff
vector<double> euler::step(double t, vector<double> state, double step, funvecbase& f) const {
    return state+(f.value(t, state)*step);
};
//metodo di Runge Kutta di ordine 4
rk4::rk4() {};
rk4::~rk4() {};

vector<double> rk4::step(double t, vector<double> state, double step, funvecbase& f) const {
    vector<double> k1=f.value(t, state);
    vector<double> k2=f.value(t+step/(2.), state+k1*(step/(2.)));
    vector<double> k3=f.value(t+step/(2.), state+k2*(step/(2.)));
    vector<double> k4=f.value(t+step, state+k3*step);
    return state+(k1+2*k2+2*k3+k4)*(step/(6.));
};
