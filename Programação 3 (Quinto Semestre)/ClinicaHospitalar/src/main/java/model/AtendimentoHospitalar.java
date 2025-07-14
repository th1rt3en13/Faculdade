package model;

public class AtendimentoHospitalar extends DadoPessoal {
    private String setor;
    private Integer cargaHoraria;

    // Construtor, getters e setters

    public AtendimentoHospitalar (String nomeCompleto, String dataNascimento, Endereco endereco, ContatoTelemail contato, Genero genero, String setor, Integer cargaHoraria){
        super(nomeCompleto, dataNascimento, endereco, contato, genero);
        this.setor = setor;
        this.cargaHoraria = cargaHoraria;
    }

    public String getSetor() {
        return setor;
    }

    public Integer getCargaHoraria() {
        return cargaHoraria;
    }

    public void setSetor(String setor) {
        this.setor = setor;
    }

    public void setCargaHoraria(Integer cargaHoraria) {
        this.cargaHoraria = cargaHoraria;
    }
    
}
