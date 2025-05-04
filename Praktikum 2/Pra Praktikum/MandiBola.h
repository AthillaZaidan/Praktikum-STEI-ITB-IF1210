#ifndef MANDIBOLA_H
#define MANDIBOLA_H

#include <stdio.h>

int HitungBiayaTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia){
    return 10000 * jumlah_anak + 20000 * jumlah_dewasa + 15000 * jumlah_lansia;
}

void PrintTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia){
    printf("Tiket berhasil dibeli!\n");
    printf("Rincian:\n");
    printf("- Jumlah anak-anak: %d\n",jumlah_anak);
    printf("- Jumlah dewasa: %d\n",jumlah_dewasa);
    printf("- Jumlah lansia: %d\n",jumlah_lansia); 
    printf("- Total biaya: %d\n",HitungBiayaTiket(jumlah_anak,jumlah_dewasa,jumlah_lansia));

    return;

}

void SelamatDatang(int input){
    int anak = input % 10;
    input /= 10;
    int dewasa = input % 10;
    input /= 10;
    int lansia = input % 10;

    printf("----------------------------------------\n");
    printf("Selamat datang di Wahana Mandi Bola!\n");
    printf("\n");
    printf("Silakan beli tiket terlebih dahulu untuk masuk ke wahana ini.\n");
    printf("\n");
    printf("Harga tiket:\n");
    printf("- Anak-anak (usia 0-12 tahun): Rp 10000\n");
    printf("- Dewasa (usia 13-64 tahun): Rp 20000\n");
    printf("- Lansia (usia 65 tahun ke atas): Rp 15000\n");
    printf("\n");
    printf("Jumlah anak: %d\n",anak);
    printf("Jumlah dewasa: %d\n",dewasa);
    printf("Jumlah lansia: %d\n",lansia);
    PrintTiket(anak,dewasa,lansia);
    return;
}

void HandleNimonsHunting(long input){
    int pergerakan = input % 10;
    input /= 10;
    int lubang = input % 10;
    input /= 10;
    int harta = input % 10;
    input /= 10;
    printf("----------------------------------------\n");
    printf("Selamat datang di Treasure Hunting Nimons!\n");
    printf("\n");
    printf("Jumlah pergerakan Nimons di dalam kolam: %d\n",pergerakan);
    printf("Jumlah lubang yang ada di kolam: %d\n",lubang);
    printf("Jumlah harta karun yang ada di kolam: %d\n",harta);
    printf("Langkah ke-1\n");
    int hartatemu = 0;
    int lubangtutup = 0;
    int totallangkah = 0;
    if(input%10 == 0){
        printf("Nimons tidak bergerak\n");
    }
    if(input%10 > 0){
        printf("Nimons bergerak sejauh %d langkah\n",input%10);
        totallangkah += input%10;
    }
    input /= 10;
    if(input%10 == 1){
        printf("Nimons menemukan harta karun!\n");
        hartatemu++;
    }
    input /= 10;
    if(input%10 == 1){
        printf("Nimons menutup lubang!\n");
        lubangtutup++;
    }
    input /= 10;
    for(int i = 2; i <= pergerakan; i++){
        printf("Langkah ke-%d\n",i);
        if(input%10 == 0){
            printf("Nimons tidak bergerak\n");
        }
        if(input%10 > 0){
            printf("Nimons bergerak sejauh %d langkah\n",input%10);
            totallangkah += input%10;
        }
        input /= 10;
        if(input%10 == 1){
            printf("Nimons menemukan harta karun!\n");
            hartatemu++;
        }
        input /= 10;
        if(input%10 == 1){
            printf("Nimons menutup lubang!\n");
            lubangtutup++;
        }
        input /= 10;
    }
    printf("\n");
    printf("Total lubang yang ditutup: %d dari %d lubang\n", lubangtutup, lubang);
    printf("Total harta karun yang ditemukan: %d\n",hartatemu);
    printf("Total harga harta karun yang ditemukan: %d\n", hartatemu * input * 5);
    printf("Total langkah yang ditempuh: %d\n", totallangkah);
    printf("Total biaya ganti rugi Pak Gro: %d\n",input*lubangtutup);
    printf("Total keuntungan Nimons dan Pak Gro: %d\n", (hartatemu * input * 5) - (input*lubangtutup));
    return;
}

#endif