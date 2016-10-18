#include "LinearSolver2.h"

LinearSolver2::LinearSolver2()
{
    //ctor
}

LinearSolver2::~LinearSolver2()
{
    //dtor
}

double LinearSolver2::DiffEquation(double x, double y)
{
	return y+(x*x);
}

