#include "../common.cpp"

using namespace std;

/*
void merge(vector<int>& arr, int inicio, int centro, int final)
crea dos vectores y los va eligiendo el menor a la vez guardandolo
en el vector principal
*/

void merge(vector<int>& arr, int inicio, int centro, int final){
    int n1 = centro-inicio+1, n2 = final-centro;
    vector<int> izq(n1),der(n2);

    for(int i=0;i<n1;i++){
        izq[i]=arr[inicio+i];
    }
    for(int i=0;i<n2;i++){
        der[i]=arr[centro+1+i];
    }

    int i=0,j=0,k=inicio;
    while (i < n1 && j < n2) {
        if (izq[i] <= der[j]) {
            arr[k] = izq[i];
            i++;
        } else {
            arr[k] = der[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = izq[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = der[j];
        j++;
        k++;
    }
}

/*
void mergesort(vector<int>& arr, int inicio, int final)
funcion recursiva que separa el vector para ordenarlo
*/
void mergesort(vector<int>& arr, int inicio, int final){
    if (inicio<final){
        int centro=(inicio+final)/2;
        mergesort(arr,inicio,centro);
        mergesort(arr,centro+1,final);
        merge(arr, inicio, centro, final);      
    }

}

int main() {
    vector<int> arr = generar_arr();
    mergesort(arr,0,nData-1);
    generar_txt(arr);
    return 0;
}