class Ordenacao {
private:
    int *vetor;
    int tamanho;

public:
    Ordenacao(int tamanho);
    ~Ordenacao();

    void gerarAleatorio();
    int* getVetor();
    int getTamanho();

    void copiarVetor(int origem[], int destino[]);

    void bubbleSort(int v[]);
    void selectionSort(int v[]);
    void insertionSort(int v[]);

    void imprimir(int v[]);
};
