package model;

public class ConsultaMedica {
    private Long id;
    private Long idPaciente;
    private Long idMedico;
    private String exame;
    private String diagnosticoCodigo;
    private String prescricao;
    private boolean indicacaoCirurgica;

    public ConsultaMedica(Long id, Long idPaciente, Long idMedico, String exame, String diagnosticoCodigo, String prescricao, boolean indicacaoCirurgica) {
        this.id = id;
        this.idPaciente = idPaciente;
        this.idMedico = idMedico;
        this.exame = exame;
        this.diagnosticoCodigo = diagnosticoCodigo;
        this.prescricao = prescricao;
        this.indicacaoCirurgica = indicacaoCirurgica;
    }

    public Long getId() { return id; }
    public void setId(Long id) { this.id = id; }

    public Long getIdPaciente() { return idPaciente; }
    public void setIdPaciente(Long idPaciente) { this.idPaciente = idPaciente; }

    public Long getIdMedico() { return idMedico; }
    public void setIdMedico(Long idMedico) { this.idMedico = idMedico; }

    public String getExame() { return exame; }
    public void setExame(String exame) { this.exame = exame; }

    public String getDiagnosticoCodigo() { return diagnosticoCodigo; }
    public void setDiagnosticoCodigo(String diagnosticoCodigo) { this.diagnosticoCodigo = diagnosticoCodigo; }

    public String getPrescricao() { return prescricao; }
    public void setPrescricao(String prescricao) { this.prescricao = prescricao; }

    public boolean isIndicacaoCirurgica() { return indicacaoCirurgica; }
    public void setIndicacaoCirurgica(boolean indicacaoCirurgica) { this.indicacaoCirurgica = indicacaoCirurgica; }
}
