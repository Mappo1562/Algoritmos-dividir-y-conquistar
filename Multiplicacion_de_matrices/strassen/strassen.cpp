#include <bits/stdc++.h>
#include "../common.cpp"
using namespace std;
 
// Code Contributed By:
// lucasletum
// https://www.geeksforgeeks.org/strassens-matrix-multiplication/

// cd /mnt/d/user/Admin/Documents/p/algoco/algoritmos-dividir-y-conquistar/Multiplicacion_de_matrices/strassen
// g++ -o out -Wall strassen.cpp

// Funcion que suma o resta matrices 
vector<vector<int> > add_matrix(vector<vector<int> > matrix_A, const vector<vector<int> >& matrix_B, int split_index, int multiplier = 1){
    for (auto i = 0; i < split_index; i++)
        for (auto j = 0; j < split_index; j++)
            matrix_A[i][j]= matrix_A[i][j]+ (multiplier * matrix_B[i][j]);
    return matrix_A;
}

// se optimiza con el cons
vector<vector<int> >multiply_matrix(const vector<vector<int> >& matrix_A,const vector<vector<int> >& matrix_B){
    int col_1 = matrix_A[0].size();
    int row_1 = matrix_A.size();
    int col_2 = matrix_B[0].size();
    //int row_2 = matrix_B.size();
 
    vector<int> result_matrix_row(col_2, 0);
    vector<vector<int> > result_matrix(row_1,result_matrix_row);

    // caso termino de recursion:
    if (col_1 == 1)
        result_matrix[0][0] = matrix_A[0][0] * matrix_B[0][0];
    else {
        // se crean las particiones
        int split_index = col_1 / 2;
 
        vector<int> row_vector(split_index, 0);
 
        vector<vector<int> > a00(split_index, row_vector);
        vector<vector<int> > a01(split_index, row_vector);
        vector<vector<int> > a10(split_index, row_vector);
        vector<vector<int> > a11(split_index, row_vector);
        vector<vector<int> > b00(split_index, row_vector);
        vector<vector<int> > b01(split_index, row_vector);
        vector<vector<int> > b10(split_index, row_vector);
        vector<vector<int> > b11(split_index, row_vector);
 
        // se hacen las particiones, las matrices se parten en 4
        for (auto i = 0; i < split_index; i++)
            for (auto j = 0; j < split_index; j++) {
                a00[i][j] = matrix_A[i][j];
                a01[i][j] = matrix_A[i][j + split_index];
                a10[i][j] = matrix_A[split_index + i][j];
                a11[i][j] = matrix_A[i + split_index][j + split_index];
                b00[i][j] = matrix_B[i][j];
                b01[i][j] = matrix_B[i][j + split_index];
                b10[i][j] = matrix_B[split_index + i][j];
                b11[i][j] = matrix_B[i + split_index][j + split_index];
            }

        // se calculan las multiplicaciones con 7 llamadas recursivas:
        vector<vector<int> > p(multiply_matrix(a00, add_matrix(b01, b11, split_index, -1)));
        vector<vector<int> > q(multiply_matrix(add_matrix(a00, a01, split_index), b11));
        vector<vector<int> > r(multiply_matrix( add_matrix(a10, a11, split_index), b00));
        vector<vector<int> > s(multiply_matrix(a11, add_matrix(b10, b00, split_index, -1)));
        vector<vector<int> > t(multiply_matrix(add_matrix(a00, a11, split_index),add_matrix(b00, b11, split_index)));
        vector<vector<int> > u(multiply_matrix(add_matrix(a01, a11, split_index, -1),add_matrix(b10, b11, split_index)));
        vector<vector<int> > v(multiply_matrix(add_matrix(a00, a10, split_index, -1),add_matrix(b00, b01, split_index)));

        // se calculan los resultados de las 4 particiones
        vector<vector<int> > result_matrix_00(add_matrix(add_matrix(add_matrix(t, s, split_index), u,split_index),q, split_index, -1));
        vector<vector<int> > result_matrix_01(add_matrix(p, q, split_index));
        vector<vector<int> > result_matrix_10(add_matrix(r, s, split_index));
        vector<vector<int> > result_matrix_11(add_matrix(add_matrix(add_matrix(t, p, split_index), r,split_index, -1),v, split_index, -1));

        // se pasan los resultados a la matriz a retornar
        for (auto i = 0; i < split_index; i++)
            for (auto j = 0; j < split_index; j++) {
                result_matrix[i][j]= result_matrix_00[i][j];
                result_matrix[i][j + split_index]= result_matrix_01[i][j];
                result_matrix[split_index + i][j]= result_matrix_10[i][j];
                result_matrix[i + split_index][j + split_index]= result_matrix_11[i][j];
            }

        // se libera la memoria de variables auxiliares
        a00.clear();
        a01.clear();
        a10.clear();
        a11.clear();
        b00.clear();
        b01.clear();
        b10.clear();
        b11.clear();
        p.clear();
        q.clear();
        r.clear();
        s.clear();
        t.clear();
        u.clear();
        v.clear();
        result_matrix_00.clear();
        result_matrix_01.clear();
        result_matrix_10.clear();
        result_matrix_11.clear();
    }
    return result_matrix;
}

int main(){
    vector<vector<int>> A = generar_mat("../A");
    vector<vector<int>> B = generar_mat("../B");
    vector<vector<int>> result = multiply_matrix(A,B);
    generar_txt(result);
    return 0;
}