package controller;

import model.Enfermeiro;
import java.util.ArrayList;
import java.util.List;

public class EnfermeiroController {
    private static List<Enfermeiro> enfermeiros = new ArrayList<>();
    private static Long proximoId = 1L;

    public void adicionarEnfermeiro(Enfermeiro enf) {
        if (enf.getId() == null) {
            enf.setId(proximoId++);
            enfermeiros.add(enf);
        } else {
            // Verifica se já existe
            Enfermeiro existente = buscarPorId(enf.getId());
            if (existente == null) {
                enfermeiros.add(enf);
            } else {
                atualizarEnfermeiro(enf); // Se já existe, atualiza em vez de duplicar
            }
        }
    }

    public void atualizarEnfermeiro(Enfermeiro enfAtualizado) {
        for (int i = 0; i < enfermeiros.size(); i++) {
            if (enfermeiros.get(i).getId().equals(enfAtualizado.getId())) {
                enfermeiros.set(i, enfAtualizado);
                return;
            }
        }
    }

    public void removerEnfermeiro(Long id) {
        enfermeiros.removeIf(e -> e.getId().equals(id));
    }

    public Enfermeiro buscarPorId(Long id) {
        return enfermeiros.stream()
                .filter(e -> e.getId().equals(id))
                .findFirst()
                .orElse(null);
    }

    public List<Enfermeiro> listarEnfermeiros() {
        return new ArrayList<>(enfermeiros);
    }
}
