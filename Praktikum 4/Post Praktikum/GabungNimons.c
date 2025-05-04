#include <stdio.h>
#include <stdbool.h>
#include "tester.h" // Comment this when developing in local
int main () {
    init(); // Comment this when developing in local

    /* Write your code here */
    FILE *f1;
    FILE *f2;
    int retval1, retval2;
    f1 = fopen("file_a.txt", "r");
    f2 = fopen("file_b.txt", "r");
    int NimonID1, NimonID2, JP1, JP2;
    bool fread1 = true, fread2 = true;
    retval1 = fscanf(f1, "%d %d", &NimonID1, &JP1);
    retval2 = fscanf(f2, "%d %d", &NimonID2, &JP2);
    if (NimonID1 == -1 && JP1 == 99) fread1 = false;
    if (NimonID2 == -1 && JP2 == 99) fread2 = false;
    while (fread1 && fread2){
        if (NimonID1 < NimonID2){
            printf("%d %d\n", NimonID1, JP1);
            retval1 = fscanf(f1, "%d %d", &NimonID1, &JP1);
            if (NimonID1 == -1 && JP1 == 99) fread1 = false;
        } else {
            printf("%d %d\n", NimonID2, JP2);
            retval2 = fscanf(f2, "%d %d", &NimonID2, &JP2);
            if (NimonID2 == -1 && JP2 == 99) fread2 = false;
        }
    }
    while (fread1){
        printf("%d %d\n", NimonID1, JP1);
        retval1 = fscanf(f1, "%d %d", &NimonID1, &JP1);
        if (NimonID1 == -1 && JP1 == 99) fread1 = false;
    }

    while (fread2){
        printf("%d %d\n", NimonID2, JP2);
        retval2 = fscanf(f2, "%d %d", &NimonID2, &JP2);
        if (NimonID2 == -1 && JP2 == 99) fread2 = false;
    }
    fclose(f1);
    fclose(f2);
    return 0;
}