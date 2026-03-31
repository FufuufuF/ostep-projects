#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }


    int now = -1, c;
    int cnt = 0;
    for (int i = 1; i < argc; i++) {
        FILE* file = fopen(argv[i], "r");
        if (file == NULL) {
            printf("wzip: cannot open file\n");
            exit(1);
        }

        while ((c = fgetc(file)) != EOF) {
            if (now == -1) {
                now = c;
                cnt = 1;
            } else if (now == c) {
                cnt++;
            } else {
                char out_char = (char)now;
                fwrite(&cnt, sizeof(int), 1, stdout);
                fwrite(&out_char, sizeof(char), 1, stdout);
                now = c;
                cnt = 1;
            }
        }
        fclose(file);
    }

    if (cnt > 0) {
        char out_char = (char)now;
        fwrite(&cnt, sizeof(int), 1, stdout);
        fwrite(&out_char, sizeof(char), 1, stdout);
    }

    return 0;
}