#include <stdio.h>
main(){
    int i = 100, cont;
    while (i<500){
        if ((i%7)==0){
            cont++;    
        }
    i++;    
    }
    printf("%d", cont);
}

