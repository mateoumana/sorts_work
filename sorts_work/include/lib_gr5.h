#ifndef LIB_GR5
#define LIB_GR5
    #include <stdio.h>
    #include <stdlib.h>         //para atof() y atoi()
    #include <string.h> 
    void insertion_sort(double *a, unsigned int lon);
    void bubble_sort(double *a, unsigned int lon);
    void swap_d(double *a, double *b);                //swap de dos valores double
    void convert_ch_d(double *a, char *buff, unsigned int lon);
#endif