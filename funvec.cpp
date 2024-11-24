#include "funvec.h"
#include <cmath>

using namespace std;

//gravity waves
gravity_waves::gravity_waves() {m_phi=0;};
gravity_waves::gravity_waves(double alpha, double phi) {
    m_alpha=alpha; 
    m_phi=phi; 
    m_v_phase=sqrt(tanh(m_phi)/m_phi);
    m_period=(2.0*M_PI)/sqrt(m_phi*tanh(m_phi));
    };
gravity_waves::~gravity_waves() {};
//read phi and phase velocity
double gravity_waves::get_alpha() const {return m_alpha;}
double gravity_waves::get_phi() const {return m_phi;};
double gravity_waves::get_v_phase() const {return m_v_phase;};
double gravity_waves::get_period() const {return m_period;};
//compute derivative
vector<double> gravity_waves::value(double time, const vector<double>& state) const {
    if (state.size()!=2) throw "problem makes sense in 2 dimensions only";
    vector<double> derivative;
    double wave_phase = m_phi*(state[0]-m_v_phase*time);
    double modulation_argument = m_phi*(state[1]+1);
    //horizontal velocity
    double v_x = -m_alpha*m_phi * sin(wave_phase)*cosh(modulation_argument);
    //vertical velocity
    double v_z = m_alpha*m_phi * cos(wave_phase)*sinh(modulation_argument);
    derivative.push_back(v_x);
    derivative.push_back(v_z);
    return derivative;
};

harmonic_oscillator::harmonic_oscillator() {m_omega_0=0; }; //the oscillator does not do the oscillating oscillation
harmonic_oscillator::harmonic_oscillator(double omega_0, double omega_forcing, double damping) {m_omega_0=omega_0; m_omega_forcing=omega_forcing; m_damping=damping; };
harmonic_oscillator::~harmonic_oscillator() {};
//read frequency
double harmonic_oscillator::get_omega() const {return m_omega_0;};
vector<double> harmonic_oscillator::value(double time, const vector<double>& state) const {
    if (state.size()%2!=0) throw "dimension of state space must be double of the degrees of freedom";
    vector<double> derivative;
    for (int i = static_cast<int>(state.size()/2); i < static_cast<int>(state.size()); i++) { derivative.push_back(state[i]);}  //la prima meta' della derivata sono le velocita'
    for (int i = 0; i < static_cast<int>(state.size()/2); i++) derivative.push_back(-pow(m_omega_0, 2)*state[i]-m_damping*state[i+static_cast<int>(state.size()/2)]+sin(m_omega_forcing*time)); //la seconda meta' contiene il senso fisico dell'equazione
    return derivative;
};


