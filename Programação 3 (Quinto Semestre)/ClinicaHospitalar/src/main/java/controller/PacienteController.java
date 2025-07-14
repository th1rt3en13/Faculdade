package controller;

import model.Paciente;
import java.util.ArrayList;
import java.util.List;

public class PacienteController {
    private static List<Paciente> pacientes = new ArrayList<>();
    private static Long proximoId = 1L;

    public void adicionarPaciente(Paciente paciente) {
        if (paciente.getId() == null) {
            paciente.setId(proximoId++);
            pacientes.add(paciente);
        } else {
            atualizarPaciente(paciente);
        }
    }

    public void atualizarPaciente(Paciente pacienteAtualizado) {
        for (int i = 0; i < pacientes.size(); i++) {
            if (pacientes.get(i).getId().equals(pacienteAtualizado.getId())) {
                pacientes.set(i, pacienteAtualizado);
                return;
            }
        }
        pacienteAtualizado.setId(proximoId++);
        pacientes.add(pacienteAtualizado);
    }

    public void removerPaciente(Long id) {
        pacientes.removeIf(p -> p.getId().equals(id));
    }

    public Paciente buscarPorId(Long id) {
        return pacientes.stream()
                .filter(p -> p.getId().equals(id))
                .findFirst()
                .orElse(null);
    }

    public List<Paciente> listarPacientes() {
        return new ArrayList<>(pacientes);
    }
}

