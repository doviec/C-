#include <iostream>
#include <string>
#include <complex>
#include <cmath>
using namespace std;

namespace solver
{

class RealVariable
{

public:
    double pow;
    double beforeX;
    double freeNumber;

    RealVariable() : pow(0.0), beforeX(1.0), freeNumber(0.0){};
    RealVariable(int pow, double beforex, double freenumber) : pow(pow), beforeX(beforex), freeNumber(freenumber){};

    ////////////////////////////////   operators RealVarible ////////////////////////////////

    //operator + //

    friend RealVariable &operator+(solver::RealVariable &x, RealVariable &y);
    friend RealVariable &operator+(solver::RealVariable &x, double y);
    friend RealVariable &operator+(double y, solver::RealVariable &x);

    //operator - //

    friend RealVariable &operator-(RealVariable &x, RealVariable &y);
    friend RealVariable &operator-(RealVariable &x, double y);
    friend RealVariable &operator-(double y, RealVariable &x);

    //operator * //

    friend solver::RealVariable &operator*(RealVariable &x, RealVariable &y);
    friend RealVariable &operator*(RealVariable &x, double y);
    friend RealVariable &operator*(double y, RealVariable &x);

    //operator / //

    friend RealVariable &operator/(RealVariable &x, RealVariable &y);
    friend RealVariable &operator/(RealVariable &x, double y);
    friend RealVariable &operator/(double y, RealVariable &x);

    //operator ^ //

    friend RealVariable &operator^(RealVariable &x, RealVariable &y);
    friend RealVariable &operator^(RealVariable &x, double y);
    friend RealVariable &operator^(double y, RealVariable &x);

    //operator == //

    friend RealVariable &operator==(RealVariable &x, RealVariable &y);
    friend RealVariable &operator==(RealVariable &x, double y);
    friend RealVariable &operator==(double y, RealVariable &x);
};

//double solver::solve(solver::RealVariable x);
double solve(RealVariable &x);

//////////////////////////////////////// ComplexVariable ////////////////////////////////////////

class ComplexVariable
{

public:
    std::complex<double> pow, beforeX, freeNumber;
    ComplexVariable() : pow(std::complex<double>(0, 0)), beforeX(std::complex<double>(1, 0)), freeNumber(std::complex<double>(0, 0)){};
    ComplexVariable(std::complex<double> pow, std::complex<double> beforeX, std::complex<double> freeNumber) : pow(pow), beforeX(beforeX), freeNumber(freeNumber){};

    ////////////////////////////////operators ComplexVariable////////////////////////////////

    //operator + //

    friend ComplexVariable &operator+(ComplexVariable &x, ComplexVariable &y);
    friend ComplexVariable &operator+(ComplexVariable &x, std::complex<double> y);
    friend ComplexVariable &operator+(double y, ComplexVariable &x);
    friend ComplexVariable &operator+(ComplexVariable &x, double y);
    friend ComplexVariable &operator+(std::complex<double> y, ComplexVariable &x);

    //operator - //
    friend ComplexVariable &operator-(ComplexVariable &x, ComplexVariable &y);
    friend ComplexVariable &operator-(ComplexVariable &x, std::complex<double> y);
    friend ComplexVariable &operator-(double y, ComplexVariable &x);
    friend ComplexVariable &operator-(ComplexVariable &x, double y);
    friend ComplexVariable &operator-(std::complex<double> y, ComplexVariable &x);

    //operator * //

    friend ComplexVariable &operator*(ComplexVariable &x, ComplexVariable &y);
    friend ComplexVariable &operator*(ComplexVariable &x, std::complex<double> y);
    friend ComplexVariable &operator*(double y, ComplexVariable &x);
    friend ComplexVariable &operator*(ComplexVariable &x, double y);
    friend ComplexVariable &operator*(std::complex<double> y, ComplexVariable &x);

    //operator / //
    friend ComplexVariable &operator/(ComplexVariable &x, ComplexVariable &y); //************
    friend ComplexVariable &operator/(ComplexVariable &x, std::complex<double> y);
    friend ComplexVariable &operator/(double y, ComplexVariable &x);
    friend ComplexVariable &operator/(ComplexVariable &x, double y);
    friend ComplexVariable &operator/(std::complex<double> y, ComplexVariable &x);

    //operator ^ //
    friend ComplexVariable &operator^(ComplexVariable &x, double y);

    //operator == //

    friend ComplexVariable &operator==(ComplexVariable &x, ComplexVariable &y);
    friend ComplexVariable &operator==(ComplexVariable &x, std::complex<double> y);
    friend ComplexVariable &operator==(double y, ComplexVariable &x);
    friend ComplexVariable &operator==(ComplexVariable &x, double y);
    friend ComplexVariable &operator==(std::complex<double> y, ComplexVariable &x);
};

//double solver::solve(solver::ComplexVariable x);
std::complex<double> solve(ComplexVariable &x);

} // namespace solver
