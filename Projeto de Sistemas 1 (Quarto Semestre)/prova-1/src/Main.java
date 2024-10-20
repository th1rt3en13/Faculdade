

//Crie um programa que simule a jogada de um dado de seis lados (números de 1 a 6)
//por seis vezes. Ao final,
//some os valores sorteados que são números primos
//apenas e apresente o resultado na tela.

public class Main {
    public static void main(String[] args) { //collections.sort
        int dado, soma=0;

        for (int cont =0; cont <6; cont++){
            dado = (int)(Math.random()*6+1);

            System.out.println("numero "+(cont+1)+": "+dado);

            if (dado == 2 | dado == 3 | dado==5){
                soma = soma + dado;
            }

        }
        System.out.println("valor da soma: "+ soma);

    }
}