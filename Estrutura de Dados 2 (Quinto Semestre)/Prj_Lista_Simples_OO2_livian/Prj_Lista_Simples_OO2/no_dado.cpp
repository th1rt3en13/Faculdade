//no_dado.cpp
#include "no_dado.h"

no_dado::no_dado(){
	info = 0;
	prox = 0;
}

no_dado::no_dado(int x, no_dado* ptr){
	info = x;
	prox = ptr;
}
