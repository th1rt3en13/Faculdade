import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        int [] nrs = new int [5];

        for (int i=0; i<5; i++){
            nrs[i] = (int)(Math.random()*100);
            System.out.println(nrs[i]);
        }
        int [][] matriz = new int [2][4];

        for (int linha=0; linha<2; linha++){
            for (int coluna =0; coluna<4; coluna++){
                matriz[linha][coluna] = (int)(Math.random()*100);
                System.out.print(matriz[linha][coluna]+"\t");
            }
            System.out.println("");
        }
        System.out.println(matriz.length);
        System.out.println(matriz[0].length);

        ArrayList<Double> peso = new ArrayList<>();

        for (int i=0; i<50; i++){
            peso.add(Math.random()*100);
        }

        int num = peso.size();
        for (int i=0; i<num; i++){
            System.out.println(peso.get(i));
        }

    }
}