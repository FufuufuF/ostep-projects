#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    if (argc == 2) {
        char* searchTerm = argv[1];
        char *line = NULL;
        size_t len = 0;
        ssize_t nread;
        while ((nread = getline(&line, &len, stdin)) != -1) {
            if (strstr(line, searchTerm) != NULL) {
                printf("%s", line);
            }
        }
        free(line);
        return 0;
    }

    char* searchTerm = argv[1];
    for (int i = 2; i < argc; i++) {
        FILE* file = fopen(argv[i], "r");
        if (file == NULL) {
            printf("wgrep: cannot open file\n");
            exit(1);
        }

        char *line = NULL;
        size_t len = 0;
        ssize_t nread;
        while ((nread = getline(&line, &len, file)) != -1) {
            if (strstr(line, searchTerm) != NULL) {
                printf("%s", line);
            }
        }
        free(line);
        fclose(file);
    }

    return 0;
}