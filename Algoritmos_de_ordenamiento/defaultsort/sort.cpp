#include "../common.cpp"
#include <algorithm>


int main(){
    vector<int> arr = generar_arr();
    sort(arr.begin(), arr.end());
    generar_txt(arr);
    return 0;
}