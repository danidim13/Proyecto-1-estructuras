#ifndef __EULERSOLVER_H__
#define __EULERSOLVER_H__

/**
 * Plantilla para u
 */
class EulerSolver{
	public:
		/**
		 * Constructor por defecto
		 */
		EulerSolver():
			h_step(0.1), x_initial(0), y_initial(0), x_data(0), y_data(0), data_size(0){
		};

		virtual ~EulerSolver(){
			dataClear();
		};

		void setInitialValues(double x0, double y0){
			x_initial = x0;
			y_initial = y0;
		};

		void setStepSize(double h){
			h_step = h;
		};

		void setIntegrationArea(double xf){
			data_size = (int)((xf - x_initial)/h_step);
		};

		virtual double DiffEquation(double x, double y) = 0;

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
