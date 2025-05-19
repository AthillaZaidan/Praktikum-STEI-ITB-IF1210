/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>
#include <stdio.h>

/* Ukuran maksimum baris dan kolom */
#define ROW_CAP 100
#define COL_CAP 100

typedef int IdxType; /* Index baris, kolom */
typedef int ElType;
typedef struct
{
   ElType mem[ROW_CAP][COL_CAP];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m){
    m->colEff = nCols;
    m->rowEff = nRows;
}
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMT(M, i, j) (M).mem[(i)][(j)]

/* *** Selektor "Dunia Matrix" *** */
bool isMatrixIdxValid(int i, int j){
    if ((i >= 0 && i < ROW_CAP) && (j >= 0 && j < COL_CAP)) return true;
    return false;
}
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m){
    return m.rowEff-1;
}
/* Mengirimkan Index baris terbesar m */
IdxType getLastIdxCol(Matrix m){
    return m.colEff-1;
}
/* Mengirimkan Index kolom terbesar m */
bool isIdxEff(Matrix m, IdxType i, IdxType j){
    if (i >= 0 && i < m.rowEff && j >= 0 && j < m.colEff) return true;
    return false;
}
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonal(Matrix m, IdxType i){
    return m.mem[i][i];
}
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut){
    mOut->rowEff = mIn.rowEff;
    mOut->colEff = mIn.colEff;
    for (int i = 0; i < mIn.rowEff; i++){
        for (int j = 0; j < mIn.colEff; j++){
            mOut->mem[i][j] = mIn.mem[i][j];
        }
    }
}
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
    createMatrix(nRow, nCol, m);
    for (int i = 0; i < nRow; i++){
        for (int j = 0; j < nCol; j++){
            scanf("%d", &m->mem[i][j]);
        }
    }
}
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void displayMatrix(Matrix m){
    for (int i = 0; i < m.rowEff; i++){
        for (int j = 0; j < m.colEff; j++){
            if (j == m.colEff -1){
                printf("%d\n", m.mem[i][j]);
            } else {
                printf("%d ", m.mem[i][j]);
            }
        }
    }
}
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2){
    Matrix m3;
    createMatrix(m1.rowEff, m1.colEff, &m3);
    for (int i = 0; i < m1.rowEff; i++){
        for (int j = 0; j < m1.colEff; j++){
            m3.mem[i][j] = m1.mem[i][j] + m2.mem[i][j];
        }
    }
    return m3;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
Matrix subtractMatrix(Matrix m1, Matrix m2){
    Matrix m3;
    createMatrix(m1.rowEff, m1.colEff, &m3);
    for (int i = 0; i < m1.rowEff; i++){
        for (int j = 0; j < m1.colEff; j++){
            m3.mem[i][j] = m1.mem[i][j] - m2.mem[i][j];
        }
    }
    return m3;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
Matrix multiplyMatrix(Matrix m1, Matrix m2){
    Matrix m3;
    createMatrix(m1.rowEff, m2.colEff, &m3);
    for (int i = 0; i < m1.rowEff; i++){
        for (int j = 0; j < m2.colEff; j++){
            m3.mem[i][j] = 0;
            for (int k = 0; k < m1.colEff; k++){
                m3.mem[i][j] += m1.mem[i][k] * m2.mem[k][j];
            }
        }
    }
    return m3;
}

/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
Matrix multiplyByConst(Matrix m, ElType x){
    Matrix m3;
    createMatrix(m.rowEff, m.colEff, &m3);
    for (int i = 0; i < m.rowEff; i++){
        for (int j = 0; j < m.colEff; j++){
            m3.mem[i][j] = m.mem[i][j] * x;
        }
    }
    return m3;
}
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyByConst(Matrix *m, ElType k){
    for (int i = 0; i < m->rowEff; i++){
        for (int j = 0; j < m->colEff; j++){
            m->mem[i][j] *= k;
        }
    }
}
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
bool isMatrixEqual(Matrix m1, Matrix m2){
    if (m1.rowEff != m2.rowEff || m1.colEff != m2.colEff) return false;
    if (getLastIdxCol(m1) != getLastIdxCol(m2)) return false;
    for (int i = 0; i < m1.rowEff; i++){
        for (int j = 0; j < m1.colEff; j++){
            if (m1.mem[i][j] != m2.mem[i][j]) return false;
        }
    }
    return true;
}
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
bool isMatrixNotEqual(Matrix m1, Matrix m2){
    return !(isMatrixEqual(m1, m2));
}
/* Mengirimkan true jika m1 tidak sama dengan m2 */
bool isMatrixSizeEqual(Matrix m1, Matrix m2){
    return (m1.rowEff == m2.rowEff && m1.colEff == m2.colEff);
}
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

/* ********** Operasi lain ********** */
int countElmt(Matrix m){
    return m.rowEff * m.colEff;
}
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
bool isSquare(Matrix m){
    if (m.rowEff == m.colEff) return true;
    return false;
}
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
bool isSymmetric(Matrix m){
    if (!(isSquare(m))) return false;
    for (int i = 0; i < m.rowEff; i++){
        for (int j = 0; j < m.colEff; j++){
            if (m.mem[i][j] != m.mem[j][i]) return false;
        }
    }
    return true;
}
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
bool isIdentity(Matrix m){
    if (!isSquare(m)) return false;
    for (int i = 0; i < m.rowEff; i++){
        for (int j = 0; j < m.colEff; j++){
            if (i == j){
                if (m.mem[i][j] != 1) return false;
            } else {
                if (m.mem[i][j] != 0) return false;
            }
        }
    }
    return true;
}
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
bool isSparse(Matrix m){
    int total = m.rowEff * m.colEff;
    int count = 0;
    for (int i = 0; i < m.rowEff; i++){
        for (int j = 0; j < m.colEff; j++){
            if (m.mem[i][j] != 0) count++;
        }
    }
    if (count <= 0.05 * total) return true;
    else return false;
}
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
Matrix negation(Matrix m){
    Matrix mOut;
    createMatrix(m.rowEff, m.colEff, &mOut);
    for (int i = 0; i < m.rowEff; i++){
        for (int j = 0; j < m.colEff; j++){
            mOut.mem[i][j] = m.mem[i][j] * -1;
        }
    }
    return mOut;
}
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
void pNegation(Matrix *m){
    for (int i = 0; i < m->rowEff; i++){
        for (int j = 0; j < m->colEff; j++){
            m->mem[i][j] *= -1;
        }
    }
}
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
float determinant(Matrix m) {
    if (!isSquare(m)) {
        return 0;
    }

    int n = ROW_EFF(m);
    
    if (n == 1) {
        return ELMT(m, 0, 0);
    }

    if (n == 2) {
        return ELMT(m, 0, 0) * ELMT(m, 1, 1) - ELMT(m, 0, 1) * ELMT(m, 1, 0);
    }

    float det = 0;

    for (int k = 0; k < n; k++) {
        Matrix minor;
        createMatrix(n - 1, n - 1, &minor);

        for (int i = 1; i < n; i++) {
            int colIdx = 0;
            for (int j = 0; j < n; j++) {
                if (j != k) {
                    ELMT(minor, i - 1, colIdx) = ELMT(m, i, j);
                    colIdx++;
                }
            }
        }

        float cofactor;
        if (k % 2 == 0) {
            cofactor = ELMT(m, 0, k);
        } else {
            cofactor = -ELMT(m, 0, k);
        }

        det += cofactor * determinant(minor);
    }

    return det;
}
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
Matrix transpose(Matrix m){
    Matrix mT;
    createMatrix(m.colEff, m.rowEff, &mT);
    for (int i = 0; i < m.colEff; i++){
        for (int j = 0; j < m.rowEff; j++){
            mT.mem[i][j] = m.mem[j][i];
        }
    }
    return mT;
}
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
void pTranspose(Matrix *m){
    for (int i = 0; i < m->rowEff; i++){
        for (int j = i + 1; j < m->colEff; j++){
            int temp = m->mem[i][j];
            m->mem[i][j] = m->mem[j][i];
            m->mem[j][i] = temp;
        }
    }
}

/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */

#endif