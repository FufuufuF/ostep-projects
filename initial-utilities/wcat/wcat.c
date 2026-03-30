#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
            printf("wcat: cannot open file\n");
            exit(1);
        }

        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("%s", buffer);
        }

        fclose(file);
    }

    return 0;
}