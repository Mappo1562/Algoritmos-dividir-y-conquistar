#include <iostream>
#include <fstream>
#include <random>
using namespace std;

/*
int main()
crea las matrices A y B aleatoriamente
y las guarda en su respectivo txt
*/
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