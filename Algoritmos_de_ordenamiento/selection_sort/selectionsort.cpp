#include "../common.cpp"

using namespace std;

// cd /mnt/d/user/Admin/Documents/p/algoco/algoritmos-dividir-y-conquistar/Algoritmos_de_ordenamiento/selection_sort
// g++ -o out -Wall selectionsort.cpp


void selectionsort(vector<int>& arr){
    int m, aux;
    for (int i=0;i<nData;i++){
        m=i;
        for (int j=i+1;j<nData;j++) {
            if (arr[j]<arr[m])
                m=j;
        }
        aux=arr[i];
        arr[i]=arr[m];
        arr[m]=aux;
    }
}

int main(){
    vector<int> arr = generar_arr();
    selectionsort(arr);
    generar_txt(arr);
    return 0;
}