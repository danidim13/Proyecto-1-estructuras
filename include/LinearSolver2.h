#ifndef LINEARSOLVER2_H
#define LINEARSOLVER2_H

#include <EulerSolver.h>


class LinearSolver2 : public EulerSolver
{
    public:
        LinearSolver2();
        virtual ~LinearSolver2();
        double DiffEquation(double x, double y){
                return y+(x*x);
        }

};

#endif // LINEARSOLVER2_H
