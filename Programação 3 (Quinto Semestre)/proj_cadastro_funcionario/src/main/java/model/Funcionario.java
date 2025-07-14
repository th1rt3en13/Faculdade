package model;

public class Funcionario {
    private String nome;
    private int idade;
    private String cargo;
    private double salario;

    public Funcionario(String nome, int idade, String cargo, double salario) {
        this.nome = nome;
        this.idade = idade;
        this.cargo = cargo;
        this.salario = salario;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public String getCargo() {
        return cargo;
    }

    public void setCargo(String cargo) {
        this.cargo = cargo;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    @Override
    public String toString() {
        return "Nome: " + nome + ", Idade: " + idade + ", Cargo: " + cargo + ", Salário: " + salario;
    }
}