#ifndef LINEARSOLVER4_H
#define LINEARSOLVER4_H

#include <EulerSolver.h>


class LinearSolver4 : public EulerSolver
{
    public:
        LinearSolver4();
        virtual ~LinearSolver4();
        double DiffEquation(double x, double y){
                return (y*y) - (x*x);
            }

    protected:

    private:
};

#endif // LINEARSOLVER4_H
