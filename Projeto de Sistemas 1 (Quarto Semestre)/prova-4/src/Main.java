//Faça um programa que receba três matrizes de mesmo tamanho (6 x 6) e
// retorne a divisão das duas primeiras menos a terceira. Ou seja, Matriz1 / Matriz2 - Matriz3
// (considere para isso operações termo a termo).
// Os números das matrizes devem ser sorteados entre 100 e 120.

public class Main {
    public static void main(String[] args) {
        boolean b = false;
        float[][] matriz1 = new float[6][6];
        float[][] matriz2 = new float[6][6];
        float[][] matriz3 = new float[6][6];
        float[][] matriz_div = new float[6][6];
        float[][] matriz_tot = new float[6][6];

        //populando
        for (int i=0; i<6; i++){
            for (int j=0; j<6; j++){
                matriz1[i][j] = (float)(Math.random()*100+20);
                matriz2[i][j] = (float)(Math.random()*100+20);
                matriz3[i][j] = (float)(Math.random()*100+20);
            }
        }

        //dividindo
        for (int i=0; i<6; i++){
            for (int j=0; j<6; j++){
                matriz_div[i][j]= matriz1[i][j]/matriz2[i][j];

                //divisao por 0
                try{
                    if (matriz2[i][j] == 0) {
                        b = true;
                    }
                } catch (Exception erro) {
                    System.out.println(erro.getMessage());
                    erro.printStackTrace();
                }
                //se um numero da matriz2 for 0
//                try{
//                    matriz_div[i][j]= matriz1[i][j]/0;
//                } catch (Exception erro) {
//                    System.out.println(erro.getMessage());
//                    erro.printStackTrace();
//                }
            }
        }

        //subtraindo
        for (int i=0; i<6; i++){
            for (int j=0; j<6; j++){
                matriz_tot[i][j]= matriz_div[i][j]/matriz3[i][j];
            }
        }

        //printando m1
        for (int i=0; i<6; i++){
            for (int j=0; j<6; j++){
                System.out.print(matriz1[i][j]+"\t");
            }
            System.out.println(" ");
        }

        System.out.println(" ");

        //printando m2
        for (int i=0; i<6; i++){
            for (int j=0; j<6; j++){
                System.out.print(matriz2[i][j]+"\t");
            }
            System.out.println(" ");
        }

        System.out.println(" ");

        //printando m3
        for (int i=0; i<6; i++){
            for (int j=0; j<6; j++){
                System.out.print(matriz3[i][j]+"\t");
            }
            System.out.println(" ");
        }

        System.out.println(" ");

        //printando total final
        for (int i=0; i<6; i++){
            for (int j=0; j<6; j++){
                System.out.print(matriz_tot[i][j]+"\t");
            }
            System.out.println(" ");
        }

    }
}