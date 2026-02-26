//algoritmo de varreduras de sucessivas
#include <iostream> 
#include <ctime> 

using namespace std;

//função para realizar a varredura sucessiva
void varreduraSucessivas(int original[], int ordenado[], int n){
    int tamanhoAtual = n;
    //for para cada posição do vetor ordenado
    for(int i = 0; i < n; i++){
        int indiceMenor = 0;
        //encontrar o menor elemento do vetor original
        for(int j = 1; j < tamanhoAtual; j++){
            if (original[j] < original[indiceMenor]){
                indiceMenor = j;
            }
        }
        ordenado[i] = original[indiceMenor];
        //remover o elemento encontrado do vetor original
        for(int j = indiceMenor; j < tamanhoAtual - 1; j++){
            original[j] = original[j+1];
        }
        tamanhoAtual--;
    }
}
//função principal
int main(){
    int n = 10000;
    int original[n];
    int ordenado[n];

    //pior caso(decrescente)
    for(int i = 0; i < n; i++){
        original[i] = n-i;
    }
    //medidor do tempo de execução
    clock_t inicio = clock();
    varreduraSucessivas(original, ordenado, n);

    //tempo gasto
    clock_t fim = clock();
    double tempo = double(fim - inicio) / CLOCKS_PER_SEC;
    cout << "Tempo Varreduras Sucessivas: " << tempo << " segundos" << endl;

    //exibir os primeiros 20 elementos ordenados
    cout << "Primeiros 20 elementos ordenados: " << endl;
    for (int i = 0; i < 20; i++) {
        cout << ordenado[i] << " " ;
    }
    cout << endl;

    return 0;
}


