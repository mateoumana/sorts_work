#include <stdio.h>
#include <stdlib.h>         //para atof() y atoi()
#include <string.h>         //para la función strchr()
#include <time.h>           //para la funcion clock_t que devuelve el tiempo que lleva el procesador en el programa
                            //clock_t tipo de variable, clock() es la funcion que returna el tiempo de procesamiento
#include "lib_gr5.h"
#include "lib1.h"
#define LONG 100000         //longitud máxima de datos a leer
int main(int argc, char *argv[]){
    double arr[LONG];
    double dt1 = 0, dt2 = 0, dt3 = 0;
    clock_t ti = 0, tf = 0;
    unsigned int ls_buff_len = 0;
    char *buffer;
    if (argc != 4){
        printf("\n\n>>>Error: cantidad de parametros insuficientes. Por favor, ingrese los necesarios.\n\n\n");
        
    }else if((*argv[1] != '1') && (*argv[1] != '2')){
        printf("\n\n<<No existe esa opcion, ingrese alguna de las siguientes:");
        printf("\n\t\tOpcion 1 para bubble sort.\n");
        printf("\t\tOpcion 2 para insertion sort.\n\n\n");    
    }else{
        buffer = read_file_to_buffer(argv[2], &ls_buff_len);
        ti = clock();
        convert_ch_d(arr, buffer, LONG);
        tf = clock();
        dt1 = (double)(tf - ti)/CLOCKS_PER_SEC;
        printf("\n\n<<<El tiempo de ejecución de la lectura del archivo fue: %.8f", dt1); //el tiempo se imprime con %ld
        if(*argv[1] == '1'){
            ti = clock();
            bubble_sort(arr, LONG);
            tf = clock();
            dt2 = (double)(tf - ti)/CLOCKS_PER_SEC;
            printf("\n<<<El tiempo de ejecución del bubble sort fue: %.8f", dt2);
        }else{
            ti = clock();
            insertion_sort(arr, LONG);
            tf = clock();
            dt2 = (double)(tf - ti)/CLOCKS_PER_SEC;
            printf("\n<<<El tiempo de ejecución del insertion sort fue: %.8f", dt2);
        }
        ti = clock();
        write_dArray_to_file(arr, LONG, argv[3]);
        tf = clock();
        dt3 = (double)(tf - ti)/CLOCKS_PER_SEC;
        printf("\n<<<El tiempo de ejecución de la escritura del archivo fue: %.8f\n\n", dt3);
        free_buffer_mem(buffer);
    }
}
//en files_ops1.c van las definiciones de las funciones de la libreria del profesor.