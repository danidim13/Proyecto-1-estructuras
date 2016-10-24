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
int main(int argc, char* argv[])
{
    // Comparar tiempos de ejecucion para diferente area de integracion
    
    int n_pruebas = atoi(argv[1]); // numero de pruebas
    char tipo_prueba = argv[2][0]; // LinearSolver a usar

    double *x_finales = new double[n_pruebas]; // Eje x de la grafica
    double *exe_times = new double[n_pruebas]; // Eje y de la grafica
    double *exe_sizes = new double[n_pruebas]; 

    EulerSolver *l1;
    
    // Abrir archivo donde se van a escribir los resultados de la prueba
    std::ofstream outFile;       
    
    cout << "Prueba para diferentes valores de xf." << endl;
    
    if (tipo_prueba == '1') {
        
        l1 = new LinearSolver1();
        outFile.open("prueba_iteraciones1.txt");
        cout << "Corriendo " << n_pruebas << " pruebas para LinearSolver1" << endl;
        
    } else if (tipo_prueba == '2') {
        
        l1 = new LinearSolver2();
        outFile.open("prueba_iteraciones2.txt");
        cout << "Corriendo " << n_pruebas << " pruebas para LinearSolver2" << endl;
        
    } else if (tipo_prueba == '3') {
        
        l1 = new LinearSolver3();
        outFile.open("prueba_iteraciones3.txt");
        cout << "Corriendo " << n_pruebas << " pruebas para LinearSolver3" << endl;
        
    } else if (tipo_prueba == '4') {
        
        l1 = new LinearSolver4();
        outFile.open("prueba_iteraciones4.txt");
        cout << "Corriendo " << n_pruebas << " pruebas para LinearSolver4" << endl;
        
    } else {
        cout << "Error de argumentos, prueba inválida." << endl;
        delete[] exe_sizes;
        delete[] exe_times;
        delete[] x_finales;
        return -1;
    }
    
    outFile.precision(10);
    l1->setInitialValues(0,0);
    l1->setStepSize(0.1);



    double *x_ptr, *y_ptr;
    int n_datos = 0;

    for(int i = 0; i<n_pruebas; i++){
	    //
	// Hacer el area de integracion mas grande
        double x_final = 10 + ((double)i*2);              
	//cout << "Iteracion: " << i << endl;
	//cout << "Valor final: " << x_final << endl;

        l1->setIntegrationArea(x_final);


	// Medir el tiempo de solucion del algoritmo
        clock_t begin = clock(); 
        l1->solve();
        clock_t end = clock();
        double elapsed_secs = ((double)(end - begin)) / CLOCKS_PER_SEC;

	    l1->getDataValues(x_ptr, y_ptr, n_datos);


	// Asignar los valores correspondientes
        exe_times[i] = elapsed_secs; 
        x_finales[i] = x_final;
	    exe_sizes[i] = n_datos;

        // Finalmente, escribir los resultados en el archivo

        outFile << exe_times[i] << "\t" << x_finales[i] << "\t" << exe_sizes[i] << endl;

    }

    delete[] exe_sizes;
    delete[] exe_times;
    delete[] x_finales;
    outFile.close();
    cout << "Finalizando pruebas!" << endl << endl;
    
    return 0;
}
