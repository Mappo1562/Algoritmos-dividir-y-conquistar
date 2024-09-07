#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// nData define el largo del vector
int nData = 2000000;

/*
vector<int> generar_arr()
guarda los numeros de dataset.txt en un vector
*/
vector<int> generar_arr(){
    ifstream data("../dataset.txt");

    if (!data){
        cout<<"No se pudo abrir el archivo.\n";
        return {};
    }

    vector<int> arr(nData);

    for (int i=0;i<nData;i++){
        data>>arr[i];
    }
    data.close();
    return arr;
}

/*
void generar_txt(vector<int>& arr)
escribe el resultado final en salida.txt
*/
void generar_txt(vector<int>& arr){
    ofstream salida("salida.txt");
    if (!salida){
        cout<<"Error al crear/abrir el archivo de salida\n";
        return;
    }
    for (int i=0;i<nData;i++){
        salida<<arr[i]<<"\n";
    }
    salida.close();
}