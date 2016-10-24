#include <iostream>
#include <LinearSolver1.h>
#include <LinearSolver2.h>
#include <LinearSolver3.h>
#include <LinearSolver4.h>
#include <EulerSolver.h>
#include <ctime>
#include <fstream>
#include <cstdlib>


using namespace std;

/**
 * Prueba1.
 * Recibe por linea de comandos:
 * <num_pruebas> <prueba>
 * donde prueba es un numero entre 1 y 4.
 */
int main(int argc, char *argv[])
{
    // Comparar tiempos de ejecucion para diferente step size

    int n_pruebas = atoi(argv[1]); // numero de pruebas
    char tipo_prueba = argv[2][0]; // LinearSolver a usar
    
    int promedio = 30;

    double *h_steps = new double[n_pruebas]; // Eje x de la grafica
    double exe_times[n_pruebas][promedio]; // Eje y de la grafica
    double *exe_sizes = new double[n_pruebas];
    double *exe_times_prom = new double[n_pruebas];

    EulerSolver *l1;
    
    // Abrir archivo donde se van a escribir los resultados de la prueba
    std::ofstream outFile;
    
    cout << "Prueba para diferentes valores de h" << endl;
    
    if (tipo_prueba == '1') {
        
        l1 = new LinearSolver1();
        outFile.open("prueba_steps1.txt");
        cout << "Corriendo " << n_pruebas << " pruebas para LinearSolver1" << endl;
        
    } else if (tipo_prueba == '2') {
        
        l1 = new LinearSolver2();
        outFile.open("prueba_steps2.txt");
        cout << "Corriendo " << n_pruebas << " pruebas para LinearSolver2" << endl;
        
    } else if (tipo_prueba == '3') {
        
        l1 = new LinearSolver3();
        outFile.open("prueba_steps3.txt");
        cout << "Corriendo " << n_pruebas << " pruebas para LinearSolver3" << endl;
        
    } else if (tipo_prueba == '4') {
        
        l1 = new LinearSolver4();
        outFile.open("prueba_steps4.txt");
        cout << "Corriendo " << n_pruebas << " pruebas para LinearSolver4" << endl;
        
    } else {
        cout << "Error de argumentos, prueba inválida." << endl;
        delete[] h_steps;
        delete[] exe_times_prom;
        delete[] exe_sizes;
        return -1;
    }
    
    
    double *x_ptr, *y_ptr;
    int n_datos = 0;

    l1->setInitialValues(0,0);

    outFile.precision(10);
    
    for (int p = 0; p < promedio; p++){
        for(int i = 0; i<n_pruebas; i++){
    
        // Aumentar el stepsize
            double h_s = 0.1/((double)i+1); 
            l1->setStepSize(h_s);
            l1->setIntegrationArea(50);
    
    	// Medir el tiempo de solucion del algoritmo
            clock_t begin = clock(); 
            l1->solve();
            clock_t end = clock();
            double elapsed_secs = ((double)(end - begin)) / CLOCKS_PER_SEC;
    
    	    l1->getDataValues(x_ptr, y_ptr, n_datos);
    
            exe_times[i][p] = elapsed_secs; // Asignar los valores correspondientes
            if (p == 0) {
                h_steps[i] = h_s;
    	        exe_sizes[i] = n_datos;
            }
        }
    }

        // Finalmente, escribir los resultados en el archivo
    for (int i = 0; i < n_pruebas; i++){
        double sum = 0;
        for (int p = 0; p < promedio; p++){
            sum += exe_times[i][p];
        }
        exe_times_prom[i] = sum/promedio;
        outFile << exe_times_prom[i] << "\t" << h_steps[i] << "\t" << exe_sizes[i] << endl;

    }
    
    delete[] h_steps;
    delete[] exe_times_prom;
    delete[] exe_sizes;
    outFile.close();
    cout << "Finalizando pruebas!" << endl << endl;
    
    return 0;
}
