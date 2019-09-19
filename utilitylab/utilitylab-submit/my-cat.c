/*********************************************************
 * my-cat.c
 *
 * Your Name: Matthew Lowery
 *********************************************************/
// using fopen, fgets, fclose

#include <stdio.h>
#include <stdlib.h>

// define a max line length, at least larger than the test cases
// given
#define MAXLENGTH 1000

int main(int argc, char *argv[]) {
    int i;
    // if no arguments/files given
    if(argc == 1) { return 0; }

    else {
        // for each argument/file given
        for(i = 1; i < argc; i++) {
            FILE *fp;
            char buffer[MAXLENGTH];
            // get first file
            fp = fopen(argv[i], "r");
            // file can't be opened
            if (fp == NULL) {
                printf("my-cat: cannot open file\n");
                exit(1);
                }
            // file is open so
            // print each line while fgets doesn't return null
            // (until the end of the file is reached)
            else {
                while (fgets(buffer, MAXLENGTH, fp)) {
                    printf("%s", buffer);
                    }
                fclose(fp);
                }
            }
        // non-error case so
        return 0;
        }
    }
