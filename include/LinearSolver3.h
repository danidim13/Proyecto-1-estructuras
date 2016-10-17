#ifndef LINEARSOLVER3_H
#define LINEARSOLVER3_H

#include <EulerSolver.h>


class LinearSolver3 : public EulerSolver
{
    public:
        LinearSolver3();
        virtual ~LinearSolver3();
        double DiffEquation(double x, double y){
                return x - y;
            }

    protected:

    private:
};

#endif // LINEARSOLVER3_H
