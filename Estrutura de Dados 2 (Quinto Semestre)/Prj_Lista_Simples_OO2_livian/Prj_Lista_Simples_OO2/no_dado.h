//no_dado.h

class no_dado{
	//atributos
	public:
		int info;
		no_dado* prox;
	
	public:
		no_dado(); //construtor sem passagem de parâmetros
		no_dado(int x, no_dado* ptr); //construtor com passagem de parâmetros	
};
