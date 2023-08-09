#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    size_t size;

    if (!isatty(fileno(stdin))) {
        
        int i = 0;
        char *pipe, *str;

        getline(&str, &size, stdin);
        pipe = strtok(str, " \n");

        fprintf(stdout, "piped content: >>%s<<\n", pipe);
        free(str);
    }

}