package model;

public enum Genero {
    MASCULINO("Masculino"),
    FEMININO("Feminino"), 
    OUTRO("Outro");
    
    private final String descricao;
    
    Genero(String descricao) {
        this.descricao = descricao;
    }
    
    public String getDescricao() {
        return descricao;
    }
    
    public static Genero fromDescricao(String descricao) {
        for (Genero g : values()) {
            if (g.descricao.equalsIgnoreCase(descricao)) {
                return g;
            }
        }
        throw new IllegalArgumentException("Gênero inválido: " + descricao);
    }
}