#include <iostream>
#include <LinearSolver1.h>
#include <LinearSolver2.h>
#include <LinearSolver3.h>
#include <LinearSolver4.h>


using namespace std;

int main()
{
    LinearSolver1 l1;
    LinearSolver2 l2;
    LinearSolver3 l3;
    LinearSolver3 l4;


    l1.setInitialValues(0,1);
    l1.setIntegrationArea(10);
    l1.solve();

    l2.setInitialValues(0,1);
    l2.setIntegrationArea(10);
    l2.solve();

    l3.setInitialValues(0,1);
    l3.setIntegrationArea(10);
    l3.solve();

    l4.setInitialValues(0,1);
    l4.setIntegrationArea(10);
    l4.solve();



    cout << "Hello world!" << endl;
    return 0;
}
