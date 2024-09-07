#include <iostream>
#include <fstream>
#include <random>
using namespace std;
// cd /mnt/d/user/Admin/Documents/p/algoco/algoritmos-dividir-y-conquistar/Multiplicacion_de_matrices
// g++ -o out -Wall datasetgenerator.cpp
int main(){
    random_device generador;
    mt19937 gen(generador());

    int min=100, max=999, nData=10000;
    int numero;

    uniform_int_distribution<> distribucion(min,max);

    ofstream salida("A.txt"),salida2("B.txt");
    if (!salida){
        cout<<"Error al crear/abrir el archivo\n";
        return 1;
    }
    if (!salida2){
        cout<<"Error al crear/abrir el archivo\n";
        return 1;
    }

    for (int i=0;i<nData;i++){
        for(int j=0;j<nData;j++){
            numero=distribucion(gen);
            salida<<numero<<" ";
            numero=distribucion(gen);
            salida2<<numero<<" ";
        }
        salida<<"\n";
        salida2<<"\n";
    }

    salida.close();
    salida2.close();
    return 0;
}