#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    
    int cnt = 0;
    char c;

    for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");

        if (file == NULL) {
            exit(1);
        }
        while (fread(&cnt, sizeof(int), 1, file) == 1) {
            fread(&c, sizeof(char), 1, file);
            for (int i = 0; i < cnt; i++) {
                printf("%c", c);
            }
        }
    
        fclose(file);
    }

    return 0;
}