#ifndef LINEARSOLVER1_H
#define LINEARSOLVER1_H

#include <EulerSolver.h>


class LinearSolver1 : public EulerSolver
{
    public:
        LinearSolver1();
        virtual ~LinearSolver1();
        double DiffEquation(double x, double y);
};

#endif // LINEARSOLVER1_H
