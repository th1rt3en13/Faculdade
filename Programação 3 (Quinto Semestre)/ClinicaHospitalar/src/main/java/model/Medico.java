package model;


public class Medico extends AtendimentoHospitalar {
    // Campos específicos do Médico 
    private Long id;
    private Integer crm;
    private String especialidade;
    private Boolean cirurgiao;

    // Construtor completo
    public Medico(Long id, String nomeCompleto, String dataNascimento, 
                 Endereco endereco, ContatoTelemail contato, Genero genero,
                 String setor, Integer cargaHoraria, Integer crm, 
                 String especialidade, Boolean cirurgiao) {
        
        super(nomeCompleto, dataNascimento, endereco, contato, genero, setor, cargaHoraria);
        this.id = id;
        this.crm = crm;
        this.especialidade = especialidade;
        this.cirurgiao = cirurgiao;
    }

    // Getters e Setters 
    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public Integer getCrm() {
        return crm;
    }

    public void setCrm(Integer crm) {
        this.crm = crm;
    }

    public String getEspecialidade() {
        return especialidade;
    }

    public void setEspecialidade(String especialidade) {
        this.especialidade = especialidade;
    }

    public Boolean getCirurgiao() {
        return cirurgiao;
    }

    public void setCirurgiao(Boolean cirurgiao) {
        this.cirurgiao = cirurgiao;
    }

    // exibição na tabela
    @Override
    public String toString() {
        return nomeCompleto + " (CRM: " + crm + ")";
    }
}