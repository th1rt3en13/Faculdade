import javax.swing.*;

//No método main que receba 3 notas de cada aluno
//de uma turma e informe a média do aluno e a média
//da turma

public class Main {
    public static void main(String[] args) {
        float n1, n2, n3, media_aluno, media_turma=0;
        int qtd;

        qtd = Integer.parseInt(JOptionPane.showInputDialog("Quantidade de aluno: "));

        for (int i=0; i<qtd; i++){

            n1 = Float.parseFloat(JOptionPane.showInputDialog("Aluno "+(i+1)+" Nota 1: "));
            n2 = Float.parseFloat(JOptionPane.showInputDialog("Aluno "+(i+1)+" Nota 2: "));
            n3 = Float.parseFloat(JOptionPane.showInputDialog("Aluno "+(i+1)+" Nota 3: "));
            media_aluno = (n1+n2+n3)/3;
            JOptionPane.showMessageDialog(null, "Media do aluno "+ (i+1)+"  = "+media_aluno);
            media_turma += media_aluno;
        }
        media_turma = media_turma/qtd;
        JOptionPane.showMessageDialog(null, "Media da turma = "+media_turma);

    }

}