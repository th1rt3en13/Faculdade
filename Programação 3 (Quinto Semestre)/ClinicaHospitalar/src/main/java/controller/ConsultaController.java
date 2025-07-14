// ConsultaController.java
package controller;

import model.ConsultaMedica;
import java.util.ArrayList;
import java.util.List;

public class ConsultaController {
    private static List<ConsultaMedica> consultas = new ArrayList<>();
    private static Long proximoId = 1L;

    public void adicionarConsulta(ConsultaMedica consulta) {
        if (consulta.getId() == null) {
            consulta.setId(proximoId++);
            consultas.add(consulta);
        } else {
            atualizarConsulta(consulta);
        }
    }

    public void atualizarConsulta(ConsultaMedica consultaAtualizada) {
        for (int i = 0; i < consultas.size(); i++) {
            if (consultas.get(i).getId().equals(consultaAtualizada.getId())) {
                consultas.set(i, consultaAtualizada);
                return;
            }
        }
        consultaAtualizada.setId(proximoId++);
        consultas.add(consultaAtualizada);
    }

    public void removerConsulta(Long id) {
        consultas.removeIf(c -> c.getId().equals(id));
    }

    public List<ConsultaMedica> listarConsultas() {
        return new ArrayList<>(consultas);
    }

    public ConsultaMedica buscarPorId(Long id) {
        return consultas.stream()
                .filter(c -> c.getId().equals(id))
                .findFirst()
                .orElse(null);
    }
} 
