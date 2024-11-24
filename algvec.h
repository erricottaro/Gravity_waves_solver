#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

//operatore somma
vector<double> operator +(const vector<double>&, const vector<double>&);
//operatore differenza
vector<double> operator -(const vector<double>&, const vector<double>&);
//operatore +=
vector<double>& operator +=(vector<double>&, const vector<double>&);
//operatore prodotto scalare
double operator *(vector<double>&, vector<double>&);
//operatori prodotto per scalare
vector<double> operator *(double, const vector<double>&);
vector<double> operator *(const vector<double>&, double);