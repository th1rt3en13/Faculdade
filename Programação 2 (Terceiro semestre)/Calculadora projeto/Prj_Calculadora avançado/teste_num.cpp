//teste_num.cpp
#include "teste_num.h"


bool eh_par (float nn1){
	if ((int)nn1 % 2 == 0){
		return true;
	}
	else{
		return false;
	}
}

bool eh_impar (float nn1){
	if ((int)nn1 % 2 != 0){
		return true;
	}
	else{
		return false;
	}
}

bool eh_primo (float nn1){
	float i;
	if (nn1<=1){
		return false;
	}
	else{
		for (i=2; i<nn1; i++){
			if ((int)nn1 % (int)i == 0){
				return false;
				break;
			}
		}
		if (i==nn1){
			return true;
		}
	}
	return 0;
}
