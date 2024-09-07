#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// nData define la longitud de la matriz
int nData = 7000;


/*
vector<vector<int>> generar_mat(string datatype)
crea una matriz a partir del txt con nombre datatype
*/
vector<vector<int>> generar_mat(string datatype){
    ifstream data(datatype+".txt");

    if (!data){
        cout<<"No se pudo abrir el archivo.\n";
        return {};
    }

    vector<vector<int>> matriz(nData, vector<int>(nData));

    for (int i=0;i<nData;i++){
        for(int j=0;j<nData;j++){
            data>>matriz[i][j];
        }
    }
    data.close();
    return matriz;
}

/*
void generar_txt(vector<vector<int>> matriz)
escribe el resultado final en salida.txt
*/
void generar_txt(vector<vector<int>> matriz){
    ofstream salida("salida.txt");
    if (!salida){
        cout<<"Error al crear/abrir el archivo de salida\n";
        return;
    }
    for (int i=0;i<nData;i++){
        for(int j=0;j<nData;j++){
            salida<<matriz[i][j]<<" ";
        }
        salida<<"\n";
    }
    salida.close();
}