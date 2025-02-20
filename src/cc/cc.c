#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "cc.h"
#include "../common/load_file.h"
#include "tokenize.h"

int main(int argc, char *argv[]) {
	if(argc != 2) {
		printf("Usage: cc example.i");
	}

	char *data = read_file(argv[1]);
}

