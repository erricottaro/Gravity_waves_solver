#include <vector>
#include "algvec.h"
#include <algorithm>

using namespace std;

#ifndef __funzionevett__
#define __funzionevett__

class funvecbase {
    public:
    //restituzione del valore della derivata prima 
    virtual vector<double> value(double time, const vector<double>& state) const=0;
};

//gravity waves in a fluid
class gravity_waves: public funvecbase {
    public:
    //constructors
    gravity_waves();
    gravity_waves(double alpha, double phi); //phi is the only adimensional parameter of the problem
    //destructor
    ~gravity_waves();
    //read alpha, phi and phase velocity
    double get_alpha() const;
    double get_phi() const;
    double get_v_phase() const;
    double get_period() const;
    vector<double> value(double time, const vector<double>& state) const override;
    private:
    double m_alpha;
    double m_phi;
    double m_v_phase;
    double m_period;
};

class harmonic_oscillator: public funvecbase {
    public:
    //constructors
    harmonic_oscillator();
    harmonic_oscillator(double omega_0, double omega_forcing, double damping=0);
    ~harmonic_oscillator();
    //read proper frequency
    double get_omega() const;
    vector<double> value(double time, const vector<double>& state) const override; //questo metodo non puo' essere const
    private:
    double m_omega_forcing;
    double m_damping;
    double m_omega_0;
};

#endif