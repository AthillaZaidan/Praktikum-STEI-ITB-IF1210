#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <stdio.h>
/**
 * @brief Mengurutkan array dalam urutan menaik.
 * @funfact, array pada sebuah parameter sudah di pass berupa pointer ke elemen pertama, sehingga modifikasi pada array akan mengubah nilai aslinya
 * @param arr Array yang akan diurutkan.
 * @param n Jumlah elemen dalam array.
 */
void sort(int arr[], int n){
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-1-i; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/**
 * @brief Menemukan indeks pertama elemen target dalam array.
 * 
 * @param arr Array yang akan dicari.
 * @param n Jumlah elemen dalam array.
 * @param target Elemen yang dicari.
 * @return Indeks elemen target, atau -1 jika tidak ditemukan.
 */
int find(int arr[], int n, int target){
    int i;
    for (i = 0; i < n; i++){
        if (arr[i] == target){
            return i;
        }
    }
    return -1;
}

/**
 * @brief Menghitung rata-rata elemen dalam array.
 * 
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Rata-rata elemen.
 */
double calculateAverage(int arr[], int n){
    double sum = 0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum/n;
}

/**
 * @brief Menemukan median dari elemen dalam array (dibulatkan).
 * 
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Median dari elemen.
 */
int findMedian(int arr[], int n){
    if (n % 2 == 0){
        return (arr[n/2 - 1] + arr[n/2]) / 2;
    } else {
        return arr[n/2];
    }
}
/**
 * @brief Menemukan modus dari elemen dalam array.
 * 
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Modus dari elemen, atau elemen pertama jika semua elemen memiliki frekuensi yang sama.
 */
int findMode(int arr[], int n){
    int maxvalue = 0, maxcount = 0, i, j;
    sort(arr, n);
    for (i = 0; i < n; i++){
        int count = 0;
        for (j = 0; j < n; j++){
            if (arr[j] == arr[i]){
                count ++;
            }
        }
        if (count > maxcount){
            maxcount = count;
            maxvalue = arr[i];
        }

    }
    return maxvalue;
}

/**
 * @brief Menemukan elemen maksimum dalam array.
 * 
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Elemen maksimum dalam array.
 */
int findMax(int arr[], int n){
    int i, max = arr[0];
    for (i = 0; i < n; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

/**
 * @brief Menemukan elemen minimum dalam array.
 * 
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Elemen minimum dalam array.
 */
int findMin(int arr[], int n){
    int i, min = arr[0];
    for (i = 0; i < n; i++){
        if (arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

/**
 * @brief Membalikkan elemen dalam array.
 * 
 * @param arr Array yang akan dibalik.
 * @param n Jumlah elemen dalam array.
 */
void reverseArray(int arr[], int n){
    int i = 0, j = n-1;
    while (i < j){
        // tukar elemem i dan j
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        i++;
        j--;
    }
}

#endif