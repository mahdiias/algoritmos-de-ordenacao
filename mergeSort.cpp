//algoritmo de junções sucessivas
#include <iostream> 
#include <ctime> 

using namespace std;

//função para realizar a junção sucessiva
void merge(int original[], int inicio, int meio, int fim){
    int tamanho = fim - inicio + 1;
    //ponteiro para o vetor temporário
    int* temp = new int[tamanho];

    //indices para percorrer as duas sub-sequências
    int i = inicio;
    int j = meio+1;
    int k = 0;

    //comparacao de duas a duas subseq
    while(i <= meio && j <= fim){
        if(original[i] <= original[j]){
            temp[k++] = original[i++];
        }else{
            temp[k++] = original[j++];
        }
    }
    //copia os elementos restantes da esquerda
    while(i <= meio){
        temp[k++] = original[i++];
    }

    //copia os elementos restantes da direita
    while(j <= fim){
      temp[k++] = original[j++];
    }

    //copia de volta para o vetor original
    for(int o = 0; o < tamanho; o++){
        original[inicio + o] = temp[o];
    }
    delete[] temp;
}
//função para realizar o merge sort(dividindo para conquistar)
void mergeSort(int original[], int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim)/2;
        mergeSort(original, inicio, meio);
        mergeSort(original, meio+1, fim);
        merge(original, inicio, meio, fim);
    }
}
//função principal
int main(){
    int n = 10000;
    int original[n];

    //pior caso(decrescente)
    for(int i = 0; i < n; i++){
        original[i] = n-i;
    }
    //medidor do tempo de execução
    clock_t inicio = clock();
    mergeSort(original, 0, n-1);
    //tempo gasto
    clock_t fim = clock();
    double tempo = double(fim - inicio) / CLOCKS_PER_SEC;

    cout << "Tempo Junções Sucessivas: " << tempo << " segundos" << endl;
    
    //exibir os primeiros 20 elementos ordenados
    cout << "Primeiros 20 elementos ordenados: " << endl;
    for (int i = 0; i < 20; i++) {
        cout << original[i] << " ";
    }
    cout << endl;
    
    return 0;
}
