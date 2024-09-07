#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../common.cpp"

using namespace std;

// cd /mnt/d/user/Admin/Documents/p/algoco/algoritmos-dividir-y-conquistar/Multiplicacion_de_matrices/alg_optimizado
// g++ -o out -Wall optimizado.cpp

vector<vector<int>> transpuesta(vector<vector<int>>& B){

    vector<vector<int>> aux(nData, vector<int>(nData));
    for (int i=0;i<nData;i++){
        for (int j=0;j<nData;j++){
            aux[i][j]=B[j][i];
        }
    }
    return aux;
}


vector<vector<int>> multiplicar(vector<vector<int>>& A, vector<vector<int>>& B){
    vector<vector<int>> resultado(nData, vector<int>(nData));
    int sum;
    for (int i=0;i<nData;i++){
        for(int j=0;j<nData;j++){
            sum=0;
            for(int k=0;k<nData;k++)
                sum+=A[i][k]*B[j][k];
            
            resultado[i][j]=sum;
        }
    }
    return resultado;
}


int main(){
    vector<vector<int>> A = generar_mat("../A");
    vector<vector<int>> B = generar_mat("../B");
    B = transpuesta(B);
    vector<vector<int>> result = multiplicar(A,B);
    generar_txt(result);
    return 0;
}