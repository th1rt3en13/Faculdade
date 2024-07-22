#include <stdio.h>
main(){
    int idade;
    printf ("idade: ");
    scanf ("%d", &idade);
    
    if (idade<5 || idade>17){
        printf("invalido");
    }
    else if (idade>=5 && idade<=7) {
        printf("infantil a");
    }
    else if (idade>=8 && idade<=10){
        printf ("infantil b");
    }
    else if (idade>=11 && idade<=13){
        printf ("juvenil a");
    }
    else{
        printf ("juvenil b");
    }
}
