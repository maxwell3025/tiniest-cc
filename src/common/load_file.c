#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "load_file.h"

char *read_file(const char *file_name) {
    FILE *file_pointer = fopen(file_name, "rb");
    if(file_pointer == NULL) {
        fprintf(stderr, "ERROR: failed to open file %s\n", file_name);
        exit(0);
    }
    
    fseek(file_pointer, 0L, SEEK_END);
    size_t file_size = ftell(file_pointer);
    fseek(file_pointer, 0L, SEEK_SET);
    
    char *buffer = malloc(file_size + 1);
    fread(buffer, file_size, 1, file_pointer);
    
    fclose(file_pointer);
    
    buffer[file_size] = '\0';
    for(int i = 0; i < file_size; i++) {
        if(buffer[i] == '\0') {
            fprintf(stderr, "ERROR: found null terminator at character %d\n", i);
            exit(0);
        }
    }
    return buffer;
}

