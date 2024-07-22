//calc_esfera
#include "calc_esfera.h"
#include <math.h>

void calc_esfera(float raio, float *area, float *volume){
	float pi = 3.14159;
	*area = 4*pi*pow(raio, 2);
	*volume = (4.0/3.0)*pi*pow(raio,3); 
}

