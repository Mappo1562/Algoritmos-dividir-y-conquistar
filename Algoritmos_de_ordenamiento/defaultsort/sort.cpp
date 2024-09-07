#include "../common.cpp"
#include <algorithm>

// cd /mnt/d/user/Admin/Documents/p/algoco/algoritmos-dividir-y-conquistar/Algoritmos_de_ordenamiento/defaultsort
// g++ -o out -Wall sort.cpp

int main(){
    vector<int> arr = generar_arr();
    sort(arr.begin(), arr.end());
    generar_txt(arr);
    return 0;
}