package model;

public class Paciente {
    private Long id;
    private String nomeCompleto;
    private String dataNascimento;
    private Genero genero;
    private ContatoTelemail contato;
    private Endereco endereco;
    private int idade;
    private String dataCadastro;
    private String observacao;

    public Paciente(Long id, String nomeCompleto, String dataNascimento, Genero genero,
                    ContatoTelemail contato, Endereco endereco,
                    int idade, String dataCadastro, String observacao) {
        this.id = id;
        this.nomeCompleto = nomeCompleto;
        this.dataNascimento = dataNascimento;
        this.genero = genero;
        this.contato = contato;
        this.endereco = endereco;
        this.idade = idade;
        this.dataCadastro = dataCadastro;
        this.observacao = observacao;
    }

    // Getters e setters
    public Long getId() { return id; }
    public void setId(Long id) { this.id = id; }

    public String getNomeCompleto() { return nomeCompleto; }
    public void setNomeCompleto(String nomeCompleto) { this.nomeCompleto = nomeCompleto; }

    public String getDataNascimento() { return dataNascimento; }
    public void setDataNascimento(String dataNascimento) { this.dataNascimento = dataNascimento; }

    public Genero getGenero() { return genero; }
    public void setGenero(Genero genero) { this.genero = genero; }

    public ContatoTelemail getContato() { return contato; }
    public void setContato(ContatoTelemail contato) { this.contato = contato; }

    public Endereco getEndereco() { return endereco; }
    public void setEndereco(Endereco endereco) { this.endereco = endereco; }

    public int getIdade() { return idade; }
    public void setIdade(int idade) { this.idade = idade; }

    public String getDataCadastro() { return dataCadastro; }
    public void setDataCadastro(String dataCadastro) { this.dataCadastro = dataCadastro; }

    public String getObservacao() { return observacao; }
    public void setObservacao(String observacao) { this.observacao = observacao; }
}
