#include <iostream>
#include <fstream>
#include <random>
using namespace std;
// cd /mnt/d/user/Admin/Documents/p/algoco/algoritmos-dividir-y-conquistar/Algoritmos_de_ordenamiento
// g++ -o out -Wall datasetgenerator.cpp
int nData=100000000;

int main(){
    random_device generador;
    mt19937 gen(generador());

    int min=0, max=1000000;//1000000
    int numero;

    uniform_int_distribution<> distribucion(min,max);

    ofstream salida("dataset.txt");
    if (!salida){
        cout<<"Error al crear/abrir el archivo\n";
        return 1;
    }


    for (int i=0;i<nData;i++){
        numero=distribucion(gen);
        salida<<numero<<"\n";
    }


    salida.close();
    return 0;
}
