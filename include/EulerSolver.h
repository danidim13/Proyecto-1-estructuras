#ifndef __EULERSOLVER_H__
#define __EULERSOLVER_H__

/**
 * Clase abstracta para resolver ecuaciones diferenciales.
 */
class EulerSolver{
	public:
		/**
		 * Constructor por defecto.
		 */
		EulerSolver():
			h_step(0.1), x_initial(0), y_initial(0), x_data(0), y_data(0), data_size(0){
		};

		/**
		 * Destructor por defecto.
		 */
		virtual ~EulerSolver(){
			dataClear();
		};

		/**
		 * Define los valores iniciales.
		 * @param x0 Valor inicial en x.
		 * @param y0 Valor de y(x0).
		 */
		void setInitialValues(double x0, double y0){
			x_initial = x0;
			y_initial = y0;
		};

		/**
		 * Define el paso de integración.
		 * @param h Paso de integración.
		 */
		void setStepSize(double h){
			h_step = h;
		};

		/**
		 * Define el valor final.
		 * @param xf Valor final.
		 */
		void setIntegrationArea(double xf){
			data_size = (int)((xf - x_initial)/h_step);
		};

		/**
		 * Retorna el valor de la derivada.
		 * Define la ecuación de la primera derivada en función
		 * de X y Y es decir, f'(x,y).
		 * @param x Valor de la variable x.
		 * @param y Valor de y.
		 * @return Resultado de la ecuación diferencial en el punto (x,y).
		 */
		virtual double DiffEquation(double x, double y) = 0;

		/**
		 * Resuelve la ecuación diferencial para los parámetros dados.
		 * Obtiene los puntos (x,y) desde los valores iniciales
		 * (x0, y0), hasta el valor final de x, usando el paso
		 * de integración dado por h_step. Los puntos se guardan
		 * en los arreglos x_data y y_data.
		 */
		int solve(){
			dataClear();
			x_data = new double[data_size+1];
			y_data = new double[data_size+1];
			x_data[0] = x_initial;
			y_data[0] = y_initial;

			for (int i = 1; i <= data_size; i++){
				//Metodo de Euler
				x_data[i] = x_data[i-1] + h_step;
				y_data[i] = y_data[i-1] + h_step*DiffEquation(x_data[i-1],y_data[i-1]);
			}
			return 0;
		}

		/**
		 * Copia por referencia los arreglos de datos x_data, y_data y el tamaño de los mismos.
		 * @param x Puntero a los puntos en x.
		 * @param y Puntero a los puntos en y.
		 * @param size Tamaño de ambos arreglos de datos.
		 * @return NA
		 */
		int getDataValues(double *&x, double *&y, int &size){
			x = x_data;
			y = y_data;
			size = data_size+1;
			return 0;
		}

	protected:

		double h_step;
		double x_initial;
		double y_initial;
		double *x_data;
		double *y_data;
		int data_size;

		/**
		 * Libera la memoria de los arreglos de datos X y Y.
		 */
		void dataClear(){
			if (x_data) {
				delete[] x_data;
				x_data = 0;
			}
			if (y_data) {
				delete[] y_data;
				y_data = 0;
			};
		};
};

#endif
