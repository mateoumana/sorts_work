#include "lib_gr5.h"
void insertion_sort(double *a, unsigned int longi){
    double key = 0;
    int cont2 = 0,cont = 1;
    for(cont = 1; (cont < longi) && (*(a+cont) != '\0'); cont++){
        key = *(a+cont);
        cont2 = cont - 1;
        while((cont2 >= 0) && (*(a+cont2) > key)){
            *(a+cont2+1) = *(a+cont2);
            cont2 -= 1;
        }
        *(a+cont2+1) = key;
    }
}
void bubble_sort(double *a, unsigned int lon){
    int i = 0, j = 0;
    for(i = 0; (i < lon) && (*(a+i) != '\0'); i++){
        for(j = 0; (j < lon) && (*(a+j) != '\0'); j++){
            if(*(a+i) < *(a+j)){
                swap_d((a+i),(a+j));
            }
        }
    }
}
void swap_d(double *a, double *b){
    double temp = *a;
    *a = *b;
    *b = temp;
}
void convert_ch_d(double *arr, char *buffer, unsigned int lon){
    unsigned int i = 0;
    char *pos;
    *(arr) = atof(buffer);
    pos = strchr(buffer, '\n');
    *(arr+1) = atof(pos+1);
    for (i = 2; (i < lon) && (*(pos+1) != '\0'); i++){
        pos = strchr(pos + 1, '\n');
        *(arr+i) = atof(pos+1);
    }
}
//atof recive la direccion del valor a convertir, solo necesita la posicion inicial ya que lee hasta que halla un caracter de escape
//caracteres de escape: '\0', '\n', etc