#include <iostream>
#include <fstream>
#include <random>
using namespace std;

// nData define el largo del vector
int nData=100000000;

/*
de crea el archivo dataset.txt y se llena de
numeros aleatorios entre min y max
*/
int main(){
    random_device generador;
    mt19937 gen(generador());

    int min=0, max=1000000;
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
