#include <stdio.h>
#include <math.h>

float cf(float c){
    return c * 9 / 5 + 32;
}

float ck (float c){
    return c + 273.15;
}

float fk (float f){
    return (f-32) * 5/9 + 273.15; 
}
float fc (float f){
    return (f-32) * 5/9;
}

float kc (float k){
    return k - 273.15;
}

float kf (float k){
    return (k-273.15) *9/5 + 32;
}
int main (){
    int N;
    scanf("%d", &N);
    float suhu[N];
    char asal[N], akhir[N];
    for (int i = 0; i < N; i++){
        scanf("%f %c %c", &suhu[i], &asal[i], &akhir[i]);
    }
    for (int i = 0; i < N; i++){
        if (asal[i] == 'C' && akhir[i] == 'F'){
            suhu[i] = cf(suhu[i]);
        } else if (asal[i] == 'C' && akhir[i] == 'K'){
            suhu[i] = ck(suhu[i]);
        } else if (asal[i] == 'F' && akhir[i] == 'K'){
            suhu[i] = fk(suhu[i]);
        } else if (asal[i] == 'F' && akhir[i] == 'C'){
            suhu[i] = fc(suhu[i]);
        } else if (asal[i] == 'K' && akhir[i] == 'C'){
            suhu[i] = kc(suhu[i]);
        } else if (asal[i] == 'K' && akhir[i] == 'F'){
            suhu[i] = kf(suhu[i]);
        }
    }
    for (int i = 0; i < N; i++){
        if (fabs(suhu[i]) < 0.005){
            printf("0.00");
        } else {
            printf("%.2f\n", roundf(suhu[i] * 100) / 100);
        }
    }
}