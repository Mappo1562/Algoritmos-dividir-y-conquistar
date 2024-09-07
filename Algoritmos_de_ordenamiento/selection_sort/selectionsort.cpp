#include "../common.cpp"

using namespace std;

/*
void selectionsort(vector<int>& arr)
ordena el arreglo con selectionsort
*/
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