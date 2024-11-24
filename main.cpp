#include <iostream>
#include <iomanip>
#include <fstream>
#include "eqdiff.h"
#include <string>

using namespace std;

int main() {
    //////////////////////////////////
    /////// READING PARAMETERS ///////
    //////////////////////////////////
    double time_step; 
    int n_periods;
    double alpha; //adimensional amplitude (as fraction of phi)
    double phi; //adimensional parameter which determines the dynamics 
    //initial position of fluid particle
    double x_0; 
    double z_0;
    ifstream input_params("input.dat");
    if (!input_params) { cout << "Input file not opened correctly" << endl; }
    string property;
    while (!input_params.eof())
    {
        input_params >> property;
        if (property== "TIMESTEP") { input_params >> time_step; }
        else if (property == "NPERIODS") {input_params >> n_periods; }
        else if (property == "ALPHA") {input_params >> alpha;}
        else if (property == "PHI") {input_params >> phi; }
        else if (property == "X0") {input_params >> x_0; }
        else if (property == "Z0") {input_params >> z_0; }
        else if (property == "ENDINPUT") { 
            cout << "Input reading complete" << endl; 
            break;
            }
    }
    
    input_params.close();

    ///////////////////////////////////////////////////////////
    /////// DEF OF DIFF EQUATION AND SOLVER METHOD ////////////
    ///////////////////////////////////////////////////////////
    gravity_waves function(alpha, phi);
    double period = function.get_period();
    int nsteps = int(n_periods*period/time_step+0.5);
    /*
    cout << "phi: " << function.get_phi() << endl
         << "v_phase: " << function.get_v_phase() << endl; */
    rk4 solver;
    //initial time and position
    double time=0.;
    vector<double> position{x_0, z_0};
    cout << "x0: " << x_0 << endl    
         << "z0: " << z_0 << endl;
    
    //////////////////////////////////////////////////////////
    /////////////// SETTING UP OUTPUT FILE ///////////////////
    //////////////////////////////////////////////////////////
    ofstream trajectory("output.dat");
    //input parameters
    trajectory << "TIMESTEP:    " << time_step << endl
               << "NPERIODS:    " << n_periods << endl
               << "ALPHA:       " << alpha << endl
               << "PHI:         " << phi << endl
               << "X0:          " << x_0 << endl
               << "Z0:          " << z_0 << endl;
    //title line
    trajectory << setw(20) << "TIME:" 
               << setw(20) << "X"
               << setw(20) << "Z" << endl;
    //initial position
    trajectory << setw(20) << time
               << setw(20) << position[0]
               << setw(20) << position[1] << endl;
    
    //////////////////////////////////////////////////////////
    ///////////// EVALUATION OF TRAJECTORY ///////////////////
    //////////////////////////////////////////////////////////
    //evaluate the number of steps needed to see the requested number of periods
    for (int i = 0; i < nsteps; i++) {
        time+=time_step;
        try { position=solver.step(time, position, time_step, function); }
        catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
        trajectory << setw(20) << time 
                   << setw(20) << position[0]
                   << setw(20) << position[1] << endl;
    }
    
    trajectory.close();

    return 0;
};