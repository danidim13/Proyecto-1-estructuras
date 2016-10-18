#include <iostream>
#include <LinearSolver1.h>
#include <ctime>
#include <fstream>


using namespace std;

int main()
{
    // Comparar tiempos de ejecucion para diferente step size

    int n_pruebas = 100; // numero de pruebas

    double *x_finales = new double[n_pruebas]; // Eje x de la grafica
    double *exe_times = new double[n_pruebas]; // Eje y de la grafica

    LinearSolver1 l1;

    l1.setInitialValues(0,0);
    l1.setStepSize(0.1);


    std::ofstream outFile;       // Abrir archivo donde se van a escribir los resultados de la prueba
    outFile.open("prueba_iteraciones.txt");


    for(int i = 0; i<n_pruebas; i++){

        double x_final = 10*i;              // Hacer el area de integracion mas grande
        l1.setIntegrationArea(x_final);

        clock_t begin = clock(); // Medir el tiempo de solucion del algoritmo
        l1.solve();
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

        exe_times[i] = elapsed_secs; // Asignar los valores correspondientes
        x_finales[i] = x_final;

        // Finalmente, escribir los resultados en el archivo

        outFile << exe_times[i] << "\t" << x_finales[i] << endl;

    }

    return 0;
}
