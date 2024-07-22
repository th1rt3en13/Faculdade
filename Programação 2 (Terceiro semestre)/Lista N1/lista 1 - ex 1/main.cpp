#include <iostream>
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char ler_tecla(){
	return getch();
}

void escreve_tecla_ascii(char tecla){
	std::cout<< "Caractere: " << tecla << " | Dec. ASCII: "<<  int(tecla)<< std::endl;
}

int main(int argc, char** argv) {
	char tecla;

	while (true){
		std::cout<<"Digite tecla: "<<std::endl;
		tecla = ler_tecla();
		
		if (tecla==27){
			std::cout<< "Fim de programa, tecla ESC foi pressionada";
			break;
		}
		else{
			escreve_tecla_ascii(tecla);
		}
	}
	
	return 0;
}

