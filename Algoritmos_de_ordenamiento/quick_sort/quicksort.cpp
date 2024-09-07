#include "../common.cpp"

using namespace std;

/*
void swap(int &a,int &b)
intercambia dos valores (los estara cambiando dentro del vector)
*/
void swap(int &a,int &b){
    int aux=a;
    a=b;
    b=aux;
}

/*
void quicksort(vector<int>& arr, int inicio, int final)
ordena el arreglo recursivamente con quicksort
*/
void quicksort(vector<int>& arr, int inicio, int final){
    if (final<=inicio)
        return;
    int pivote=arr[final],j=inicio-1;
    for (int i=inicio;i<final;i++){
        if (arr[i]<pivote){
            j++;
            swap(arr[i],arr[j]);
        }
    }
    j++;
    swap(arr[j],arr[final]);
    quicksort(arr,inicio,j-1);
    quicksort(arr,j+1,final);
}

int main(){
    vector<int> arr = generar_arr();
    quicksort(arr,0,nData-1);
    generar_txt(arr);
    return 0;
}