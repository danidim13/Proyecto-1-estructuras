#include <iostream>
#include <LinearSolver1.h>
#include <LinearSolver2.h>
#include <LinearSolver3.h>
#include <LinearSolver4.h>
#include <ctime>
#include <fstream>



using namespace std;

int main()
{

    std::ofstream outFile;       // Abrir archivo donde se van a escribir los resultados de la prueba
    outFile.open("prueba_eds.txt");

    LinearSolver1 l1;
    LinearSolver2 l2;
    LinearSolver3 l3;
    LinearSolver3 l4;


    l1.setInitialValues(0,0);
    l1.setIntegrationArea(1000);

    l2.setInitialValues(0,0);
    l2.setIntegrationArea(1000);

    l3.setInitialValues(0,0);
    l3.setIntegrationArea(1000);

    l4.setInitialValues(0,0);
    l4.setIntegrationArea(1000);

        clock_t begin = clock();
        l1.solve();
        clock_t end = clock();

        double elapsed_secs_l1 = double(end - begin) / CLOCKS_PER_SEC;

        clock_t begin2 = clock();
        l2.solve();
        clock_t end2 = clock();

        double elapsed_secs_l2 = double(end2 - begin2) / CLOCKS_PER_SEC;

        clock_t begin3 = clock();
        l3.solve();
        clock_t end3 = clock();

        double elapsed_secs_l3 = double(end3 - begin3) / CLOCKS_PER_SEC;

        clock_t begin4 = clock();
        l4.solve();
        clock_t end4 = clock();

        double elapsed_secs_l4 = double(end4 - begin4) / CLOCKS_PER_SEC;

        outFile << elapsed_secs_l1 << "\n" << elapsed_secs_l2 << "\n" << elapsed_secs_l3 << "\n" << elapsed_secs_l4 << endl;


    return 0;
}
