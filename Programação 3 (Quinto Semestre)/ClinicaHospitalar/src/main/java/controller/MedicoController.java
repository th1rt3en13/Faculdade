package controller;

import model.Medico;
import java.util.ArrayList;
import java.util.List;

public class MedicoController {
    private static List<Medico> medicos = new ArrayList<>();
    private static Long proximoId = 1L;

    public void adicionarMedico(Medico medico) {
        if (medico.getId() == null) {
            // Novo médico → gera ID e adiciona
            medico.setId(proximoId++);
            medicos.add(medico);
        } else {
            // Médico já tem ID → atualizar
            atualizarMedico(medico);
        }
    }

    public void atualizarMedico(Medico medicoAtualizado) {
        for (int i = 0; i < medicos.size(); i++) {
            if (medicos.get(i).getId().equals(medicoAtualizado.getId())) {
                medicos.set(i, medicoAtualizado);
                return;
            }
        }
        // Caso não encontre, adiciona com ID novo (opcional, pode remover se quiser evitar isso)
        medicoAtualizado.setId(proximoId++);
        medicos.add(medicoAtualizado);
    }

    public void removerMedico(Long id) {
        medicos.removeIf(m -> m.getId().equals(id));
    }

    public List<Medico> listarMedicos() {
        return new ArrayList<>(medicos);
    }

    public Medico buscarPorId(Long id) {
        return medicos.stream()
            .filter(m -> m.getId().equals(id))
            .findFirst()
            .orElse(null);
    }
}
