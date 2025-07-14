package model;

import java.util.Date;

public class DadoPessoal {
    protected String nomeCompleto;
    protected String dataNascimento;
    protected Endereco endereco;
    protected ContatoTelemail contato;
    protected Genero genero;

    // Construtor, getters e setters

    public DadoPessoal(String nomeCompleto, String dataNascimento, Endereco endereco, ContatoTelemail contato, Genero genero) {
        this.nomeCompleto = nomeCompleto;
        this.dataNascimento = dataNascimento;
        this.endereco = endereco;
        this.contato = contato;
        this.genero = genero;
    }

    public String getNomeCompleto() {
        return nomeCompleto;
    }

    public String getDataNascimento() {
        return dataNascimento;
    }

    public Endereco getEndereco() {
        return endereco;
    }

    public ContatoTelemail getContato() {
        return contato;
    }

    public Genero getGenero() {
        return genero;
    }

    public void setNomeCompleto(String nomeCompleto) {
        this.nomeCompleto = nomeCompleto;
    }

    public void setDataNascimento(String dataNascimento) {
        this.dataNascimento = dataNascimento;
    }

    public void setEndereco(Endereco endereco) {
        this.endereco = endereco;
    }

    public void setContato(ContatoTelemail contato) {
        this.contato = contato;
    }

    public void setGenero(Genero genero) {
        this.genero = genero;
    }
    
}
