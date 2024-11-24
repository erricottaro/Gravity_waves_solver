#include "algvec.h"

//operatori testati
vector<double> operator+(const vector<double>& s1, const vector<double>& s2) {
    if (static_cast<int>(s1.size())!=static_cast<int>(s2.size())) throw "vectors of different sizes cannot be summed"; //inserire costrutto try catch nel main
    vector<double> sum;
    for (int i = 0; i < static_cast<int>(s1.size()); i++) { //static_cast<int>????
        double appo=s1[i]+s2[i];
        sum.push_back(appo);
    }
    return sum;
}
vector<double> operator-(const vector<double>& s1, const vector<double>& s2) {
    if (static_cast<int>(s1.size())!=static_cast<int>(s2.size())) throw "vectors of different sizes cannot be summed"; //inserire costrutto try catch nel main
    vector<double> diff;
    for (int i = 0; i < static_cast<int>(s1.size()); i++) { //static_cast<int>????
        double appo=s1[i]-s2[i];
        diff.push_back(appo);
    }
    return diff;
}
vector<double>& operator+=(vector<double>& lhs, const vector<double>& rhs) {
    if (static_cast<int>(lhs.size())!=static_cast<int>(rhs.size())) throw "vectors of different sizes cannot be summed"; //inserire costrutto try catch nel main
    for (int i = 0; i < static_cast<int>(lhs.size()); i++) {
        lhs[i]+=rhs[i];
    }
    return lhs;
}
double operator*(vector<double>& p1, vector<double>& p2) {
    if (static_cast<int>(p1.size())!=static_cast<int>(p2.size())) throw "vectors of different sizes cannot be dot producted"; //inserire costrutto try catch nel main
    double product=0;
    for (int i = 0; i < static_cast<int>(p1.size()); i++) { //static_cast<int>????
        product+=p1[i]*p2[i];
    }
    return product;
}
vector<double> operator *(double scalar, const vector<double>& p) {
    vector<double> product;
    for (int i = 0; i < p.size(); i++) { //static_cast<int>????
        double appo=scalar*p[i];
        product.push_back(appo);
    }
    return product;
}
vector<double> operator *(const vector<double>& p, double scalar) {
    vector<double> product;
    for (int i = 0; i < static_cast<int>(p.size()); i++) { //static_cast<int>????
        double appo=scalar*p[i];
        product.push_back(appo);
    }
    return product;
}