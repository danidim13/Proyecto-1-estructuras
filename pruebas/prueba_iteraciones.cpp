#include <iostream>
#include <LinearSolver1.h>
#include <ctime>
#include <fstream>


using namespace std;

int main()
{
    // Comparar tiempos de ejecucion para diferente area de integracion

    int n_pruebas = 500; // numero de pruebas

    double *x_finales = new double[n_pruebas]; // Eje x de la grafica
    double *exe_times = new double[n_pruebas]; // Eje y de la grafica
    double *exe_sizes = new double[n_pruebas]; 

    LinearSolver1 l1;

    l1.setInitialValues(0,0);
    l1.setStepSize(0.1);

    // Abrir archivo donde se van a escribir los resultados de la prueba
    std::ofstream outFile;       
    outFile.open("prueba_iteraciones1.txt");
    outFile.precision(10);

    double *x_ptr, *y_ptr;
    int n_datos = 0;

    for(int i = 0; i<n_pruebas; i++){
	    //
	// Hacer el area de integracion mas grande
        double x_final = 10 + ((double)i*2);              
	//cout << "Iteracion: " << i << endl;
	//cout << "Valor final: " << x_final << endl;

        l1.setIntegrationArea(x_final);


	// Medir el tiempo de solucion del algoritmo
        clock_t begin = clock(); 
        l1.solve();
        clock_t end = clock();
        double elapsed_secs = ((double)(end - begin)) / CLOCKS_PER_SEC;

	l1.getDataValues(x_ptr, y_ptr, n_datos);


	// Asignar los valores correspondientes
        exe_times[i] = elapsed_secs; 
        x_finales[i] = x_final;
	exe_sizes[i] = n_datos;

        // Finalmente, escribir los resultados en el archivo

        outFile << exe_times[i] << "\t" << x_finales[i] << "\t" << exe_sizes[i] << endl;

    }

    return 0;
}
