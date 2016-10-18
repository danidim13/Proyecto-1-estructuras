#include "LinearSolver4.h"

LinearSolver4::LinearSolver4()
{
    //ctor
}

LinearSolver4::~LinearSolver4()
{
    //dtor
}
double LinearSolver4::DiffEquation(double x, double y)
{
	return (y*y) - (x*x);
}
