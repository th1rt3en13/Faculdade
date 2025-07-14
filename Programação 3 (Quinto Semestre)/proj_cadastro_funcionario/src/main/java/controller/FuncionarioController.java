package controller;

import model.Funcionario;
import java.util.ArrayList;
import java.util.List;

public class FuncionarioController {
    private static FuncionarioController instance;
    private List<Funcionario> funcionarios;

    private FuncionarioController() {
        funcionarios = new ArrayList<>();
    }

    public static FuncionarioController getInstance() {
        if (instance == null) {
            instance = new FuncionarioController();
        }
        return instance;
    }

    public void adicionarFuncionario(Funcionario funcionario) {
        if (funcionario.getNome() == null || funcionario.getNome().isEmpty()) {
            throw new IllegalArgumentException("O nome não pode ser vazio!");
        }
        if (funcionario.getIdade() <= 0) {
            throw new IllegalArgumentException("A idade deve ser maior que zero!");
        }
        if (funcionario.getSalario() <= 0) {
            throw new IllegalArgumentException("O salário deve ser maior que zero!");
        }
        funcionarios.add(funcionario);
    }

    public List<Funcionario> listarFuncionarios() {
        return funcionarios;
    }
}