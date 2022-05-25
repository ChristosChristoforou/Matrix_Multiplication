#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct dimention{

    size_t row;
    size_t column;
}Dimention;

typedef struct Matrix{
    
    long** array;
    Dimention Dim;
}Matrix;

void zero_matrix(Matrix* mat);
void random_matrix(Matrix* mat);
int matrix_mult(Matrix* mat_1, Matrix* mat_2, Matrix* solution);
void print_matrix(Matrix mat);


int main(){

    srand(time(NULL));

    Matrix mat_1, mat_2, mat_3;
    const size_t a = 4; // To make multiplication valid for all mat_1 and mat_2

    //Matrix_1
    mat_1.Dim.row = 3;
    mat_1.Dim.column = a;
    long tmp[mat_1.Dim.row * mat_1.Dim.column];
    long* tmp_2[mat_1.Dim.row];


    mat_1.array = tmp_2;
    mat_1.array[0] = tmp;
    for (size_t i = 1; i < mat_1.Dim.row; i++)
    {
        mat_1.array[i] = mat_1.array[0] + i * mat_1.Dim.row + 1;
    }

    //Matrix_2
    mat_2.Dim.row = a;
    mat_2.Dim.column = 5;
    long tmp_3[mat_2.Dim.row * mat_2.Dim.column];
    long* tmp_4[mat_2.Dim.row];


    mat_2.array = tmp_4;
    mat_2.array[0] = tmp_3;
    for (size_t i = 1; i < mat_2.Dim.row; i++)
    {
        mat_2.array[i] = mat_2.array[0] + i * mat_2.Dim.row + 1;
    }

    //Matrix_3
    mat_3.Dim.row = mat_1.Dim.row;
    mat_3.Dim.column = mat_2.Dim.column;
    long tmp_5[mat_3.Dim.row * mat_3.Dim.column];
    long* tmp_6[mat_3.Dim.row];


    mat_3.array = tmp_6;
    mat_3.array[0] = tmp_5;
    for (size_t i = 1; i < mat_3.Dim.row; i++)
    {
        mat_3.array[i] = mat_3.array[0] + i * mat_3.Dim.row + 1;
    }
    
    random_matrix(&mat_1);
    printf("Matrix A\n_____________________________________________________________________________________\n\n");
    print_matrix(mat_1);

    random_matrix(&mat_2);
    printf("Matrix B\n_____________________________________________________________________________________\n\n");
    print_matrix(mat_2);


    zero_matrix(&mat_3);
    if (!matrix_mult(&mat_1, &mat_2, &mat_3))
    {
        printf("Matrix C\n_____________________________________________________________________________________\n\n");
        print_matrix(mat_3);
    }else
    {
        printf("No Valid Outcome Available\n");
    }
    
    
    
    
    return(0);
}

void random_matrix(Matrix* mat){

    
    for (size_t i = 0; i < mat->Dim.row; i++)
    {
        for (size_t j = 0; j < mat->Dim.column; j++)
        {
            mat->array[i][j] = rand() % 20 - 10;
        }

    }
}

void zero_matrix(Matrix* mat){

    
    for (size_t i = 0; i < mat->Dim.row; i++)
    {
        for (size_t j = 0; j < mat->Dim.column; j++)
        {
            mat->array[i][j] = 0;
        }

    }
}

int matrix_mult(Matrix* mat_1, Matrix* mat_2, Matrix* solution){

    if (mat_1->Dim.column != mat_2->Dim.row)
    {
        printf("Dimention error\n");
        return 1;
    }
    

    for (size_t i = 0; i < solution->Dim.row; i++)
    {
        for (size_t j = 0; j < solution->Dim.column; j++)
        {
            for (size_t k = 0; k < mat_1->Dim.column; k++)
            {
                solution->array[i][j] += mat_1->array[i][k] * mat_2->array[k][j];
            }
            
        }
        
    }
    return 0 ;
    
}

void print_matrix(Matrix mat){

    for (size_t i = 0; i < mat.Dim.row; i++)
    {
        for (size_t j = 0; j < mat.Dim.column; j++)
        {
            
            printf("\t%ld\t", mat.array[i][j]);
        }
        printf("\n\n");
    }
    printf("\n");

}

