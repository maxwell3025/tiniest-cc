#include <stdio.h>
#include <stdlib.h>

#include "../common/load_file.h"

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: parser_codegen <name of my file>\n");
        exit(1);
    }

    char *file_data = read_file(argv[1]);
    
    free(file_data);
}
