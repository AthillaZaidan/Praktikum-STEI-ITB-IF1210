/* File : matrix.h */
/* Deskripsi : Definisi ADT Matrix untuk representasi matriks dengan elemen float */
#ifndef MATRIX_H
#define MATRIX_H
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct
{
  float data[MAX_ROWS][MAX_COLS];
  int rows;
  int cols;
} Matrix;

/* Konstruktor */
void CreateMatrix(int rows, int cols, Matrix *M){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            M->data[i][j] = 0;
        }
    }
    M->rows = rows;
    M->cols = cols;
}
/* I.S. rows dan cols terdefinisi dan valid (1 <= rows,cols <= MAX) */
/* F.S. Terbentuk matrix M dengan ukuran rows x cols */
/* Semua elemen diinisialisasi dengan 0.0 */

/* Selector */
int GetRows(Matrix M){
    return M.rows;
}
/* Mengembalikan jumlah baris matrix M */

int GetCols(Matrix M){
    return M.cols;
}
/* Mengembalikan jumlah kolom matrix M */

float *GetElement(Matrix *M, int row, int col){
    if (row < 0 || row >= M->rows || col < 0 || col >= M->cols){
        return NULL;
    } else {
        return &M->data[row][col];
    }
}
/* Mengembalikan pointer ke elemen matrix M pada baris row dan kolom col */
/* Mengembalikan NULL jika row atau col tidak valid untuk matrix M */

/* Mutator */
bool SetElement(Matrix *M, int row, int col, float value){
    if (GetElement(M, row, col) != NULL){
        M->data[row][col] = value;
        return true;
    }
    return false;
}
/* I.S. M terdefinisi */
/* F.S. Jika row dan col valid, elemen M pada baris row dan kolom col bernilai value, mengembalikan true */
/*      Jika row atau col tidak valid, mengembalikan false */

/* Operasi Baca/Tulis */
void ReadMatrix(Matrix *M){
    int row, col;
    scanf("%d %d", &row, &col);
    while (!(row > 0 && row <MAX_ROWS && col > 0 && col < MAX_COLS)){
        scanf("%d %d", row, col);
    }
    CreateMatrix(row, col, M);
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            scanf("%f", &M->data[i][j]);
        }
    }
}
/* I.S. M belum terdefinisi */
/* F.S. M terdefinisi dan diisi dengan nilai-nilai yang dibaca dari input */
/*      Meminta input ukuran matrix (rows, cols) hingga valid
        Valid: 0 < rows < MAX_ROWS and 0 < cols < MAX_COLS */
/*      Meminta input elemen matrix M sebanyak rows * cols 
        Format input: Setiap elemen dipisahkan oleh spasi
        Contoh input: 
        2 3
        1.0 2.0 3.0
        4.0 5.0 6.0
        Contoh input tidak valid:
        -1 -1
        2 3
        1.0 2.0 3.0
        4.0 5.0 6.0
*/

void PrintMatrix(Matrix M){
    for (int i = 0; i < M.rows; i++){
        for (int j = 0; j < M.cols; j++){
            if (j == M.cols-1){
                printf("%.2f \n", M.data[i][j]);
            } else {
                printf("%.2f ", M.data[i][j]);
            }
        }
    }
}
/* I.S. M terdefinisi */
/* F.S. Seluruh elemen M tertulis ke layar dalam format matrix */
/* Baris dipisahkan oleh newline, kolom dipisahkan oleh spasi */
/* Format output: Setiap elemen diformat "%.2f" */

/* Operator Relasional */
bool IsSquare(Matrix M){
    return (M.cols == M.rows);
}
/* Mengembalikan true jika M adalah matrix persegi (rows = cols) */

bool IsSymmetric(Matrix M){
    for (int i = 0; i < M.rows; i++){
        for (int j = 0; j < M.cols; j++){
            if (M.data[i][j] != M.data[j][i]) return false;
        }
    }
    return true;
}
/* Mengembalikan true jika M adalah matrix simetrik terhadap diagonal */
/* Matrix simetrik adalah matrix yang memiliki elemen tercermin oleh diagonal*/
/* Prekondisi: M adalah matrix persegi */

bool IsDiagonallyDominant(Matrix M){
    for (int i = 0; i < M.rows; i++){
        float d = fabsf(M.data[i][i]);
        float sum = 0.0;
        for (int j = 0; j < M.cols; j++){
            if (j != i){
                sum += fabsf(M.data[i][j]);
            }
        }
        if (d <= sum){
            return false;
        }
    }
    return true;
}
/* Mengembalikan true jika M adalah matrix diagonal dominant */
/* |a[i][i]| > sum(|a[i][j]|) untuk j != i pada setiap baris i */
/* Hint: Gunakan fabs untuk melakukan abs terhadap float */

/* Operator Aritmatika */
Matrix *MultiplyMatrix(Matrix M1, Matrix M2){
    if (M1.cols != M2.rows) {
        return NULL;
    }
    Matrix *M3 = (Matrix *)malloc(sizeof(Matrix));
    CreateMatrix(M1.rows, M2.cols, M3);
    for (int i = 0; i < M1.rows; i++){
        for (int j = 0; j < M2.cols; j++){
            float sum = 0.0f;
            for (int k = 0; k < M1.cols; k++){
                sum += M1.data[i][k] * M2.data[k][j];
            }
            M3->data[i][j] = sum;
        }
    }
    return M3;
}
/* Menghasilkan hasil perkalian matrix M1 dan M2 */
/* Mengembalikan NULL jika jumlah kolom M1 != jumlah baris M2 */
/* Hint: Gunakan Matrix* pointer = (Matrix *)malloc(sizeof(Matrix)) untuk menghasilkan pointer ke Matrix baru */
/* Jika anda membuat driver sendiri, jangan lupa di free ya -> free(pointer) */

Matrix *AddMatrix(Matrix M1, Matrix M2){
    if (M1.rows != M2.rows || M1.cols != M2.cols){
        return NULL;
    }
    Matrix *M3 = (Matrix *)malloc(sizeof(Matrix));
    CreateMatrix(M1.rows, M1.cols, M3);
    for (int i = 0; i < M1.rows; i++){
        for (int j = 0; j < M1.cols; j++){
            M3->data[i][j] = M1.data[i][j] + M2.data[i][j];
        }
    }
    return M3;
}
/* Menghasilkan hasil penjumlahan matrix M1 dan M2 */
/* Mengembalikan NULL jika ukuran matrix M1 dan M2 berbeda */
/* Hint: Gunakan Matrix* pointer = (Matrix *)malloc(sizeof(Matrix)) untuk menghasilkan pointer ke Matrix baru */
/* Jika anda membuat driver sendiri, jangan lupa di free ya -> free(pointer) */

Matrix *SubtractMatrix(Matrix M1, Matrix M2){
    if (M1.rows != M2.rows || M1.cols != M2.cols){
        return NULL;
    }
    Matrix *M3 = (Matrix *)malloc(sizeof(Matrix));
    CreateMatrix(M1.rows, M1.cols, M3);
    for (int i = 0; i < M1.rows; i++){
        for (int j = 0; j < M1.cols; j++){
            M3->data[i][j] = M1.data[i][j] - M2.data[i][j];
        }
    }
    return M3;
}
/* Menghasilkan hasil pengurangan matrix M1 dan M2 (M1 - M2) */
/* Mengembalikan NULL jika ukuran matrix M1 dan M2 berbeda */
/* Hint: Gunakan Matrix* pointer = (Matrix *)malloc(sizeof(Matrix)) untuk menghasilkan pointer ke Matrix baru */
/* Jika anda membuat driver sendiri, jangan lupa di free ya -> free(pointer) */

Matrix MultiplyScalar(Matrix M, float scalar){
    Matrix MS;
    CreateMatrix(M.rows, M.cols, &MS);
    for (int i = 0; i < M.rows; i++){
        for (int j = 0; j < M.cols; j++){
            MS.data[i][j] = M.data[i][j] * scalar;
        }
    }
    return MS;
}
/* Menghasilkan hasil perkalian matrix M dengan skalar scalar */
/* Prekondisi: M terdefinisi dan skalar terdefinisi */
/* Hint: Buat matrix baru untuk menyimpan hasil */

Matrix GetTranspose(Matrix M){
    Matrix MT;
    CreateMatrix(M.cols, M.rows, &MT);
    for (int i = 0; i < M.rows; i++){
        for (int j = 0; j < M.cols; j++){
            MT.data[j][i] = M.data[i][j];
        }
    }
    return MT;
}
/* Menghasilkan matrix transpose dari M */
/* Hint: Buat matrix baru untuk menyimpan hasil */

#endif