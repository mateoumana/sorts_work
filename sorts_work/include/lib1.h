#ifndef LIB1_H
#define LIB1_H
    #include <stdio.h>
    #include <stdlib.h>         //para atof() y atoi()
    #include <string.h> 
    char *read_file_to_buffer (const char *, unsigned int *);
    void free_buffer_mem(char *);
    void write_dArray_to_file (const double *, unsigned int , const char *);

#endif