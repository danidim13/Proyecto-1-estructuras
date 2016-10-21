#include <iostream>
#include <LinearSolver1.h>
#include <ctime>
#include <fstream>


using namespace std;

int main()
{
    // Comparar tiempos de ejecucion para diferente step size

    int n_pruebas = 500; // numero de pruebas

    double *h_steps = new double[n_pruebas]; // Eje x de la grafica
    double *exe_times = new double[n_pruebas]; // Eje y de la grafica
    double *exe_sizes = new double[n_pruebas];

    LinearSolver1 l1;
    double *x_ptr, *y_ptr;
    int n_datos = 0;

    l1.setInitialValues(0,0);

    // Abrir archivo donde se van a escribir los resultados de la prueba
    std::ofstream outFile;       
    outFile.open("prueba_steps1.txt");
    outFile.precision(10);

    for(int i = 0; i<n_pruebas; i++){

	// Aumentar el stepsize
        double h_s = 0.1/((double)i+1); 
        l1.setStepSize(h_s);
        l1.setIntegrationArea(50);

	// Medir el tiempo de solucion del algoritmo
        clock_t begin = clock(); 
        l1.solve();
        clock_t end = clock();
        double elapsed_secs = ((double)(end - begin)) / CLOCKS_PER_SEC;

	l1.getDataValues(x_ptr, y_ptr, n_datos);

        exe_times[i] = elapsed_secs; // Asignar los valores correspondientes
        h_steps[i] = h_s;
	exe_sizes[i] = n_datos;

        // Finalmente, escribir los resultados en el archivo

        outFile << exe_times[i] << "\t" << h_steps[i] << "\t" << exe_sizes[i] << endl;

    }

    return 0;
}
