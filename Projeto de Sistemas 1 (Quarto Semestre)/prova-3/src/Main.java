//Faça um programa que leia do teclado 7 números inteiros e armazene-os numa arraylist
// denominado BÁSICO.
//Armazene os números múltiplos de três em um segundo arraylist denominado MULTIPLOS_DE_TRES e
//os demais em um terceiro arraylist denominado RESTANTE. Ordene os vetores e imprima-os.

import javax.swing.*;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        ArrayList<Integer> basico = new ArrayList<>();
        ArrayList<Integer> multiplo_de_tres = new ArrayList<>();
        ArrayList<Integer> restante = new ArrayList<>();

        for (int i=0; i<7; i++){
            int num = Integer.parseInt((JOptionPane.showInputDialog(null, "digite "+(i+1)+" numero:")));
            basico.add(num);
            if ((num % 3) != 0) {
                restante.add(num);
            } else {
                multiplo_de_tres.add(num);
            }
        }

        Collections.sort(basico);
        Collections.sort(multiplo_de_tres);
        Collections.sort(restante);

        System.out.println("basico: "+basico);
        System.out.println("multiplo de 3: "+multiplo_de_tres);
        System.out.println("restante: "+restante);
    }
}