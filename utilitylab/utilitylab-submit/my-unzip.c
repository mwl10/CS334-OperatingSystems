/*********************************************************
 * my-unzip.c
 *
 * Your Name: Matthew Lowery
 *********************************************************/
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
int main(int argc, char *argv[]) {

    if (argc == 1) {
        printf("my-unzip: file1 [file2 ...]\n");
        exit(1);
        }
    else {
        // loop through all the file arguments
        for(int i = 1; i < argc; i++) {
            FILE *fp;
            // open the particular file
            fp = fopen(argv[i], "r");
            // ensuring fopen works
            if (fp == NULL) {
                printf("my-unzip: cannot open file\n");
                exit(1);
                }
            // file is open to be processed
            else {
                // find the size of the file
                fseek(fp, 0L, SEEK_END);
                long int size = ftell(fp);
                // need to go back to the start of it after finding its size
                fseek(fp, 0L, SEEK_SET);
                // k counts in 5s for each 5 byte chunk that represents a run of a certain character
                int k = 0;
                // loop until we read through the whole file
                while (k < size) {
                    char *character = calloc(1, 2);
                    int *runlength = calloc(1, 5);
                    char *run = calloc(1, 1000);
                    // read the 4 byte integer from the file representing the run length
                    fread(runlength, 4, 1, fp);
                    // read the char
                    fread(character, 1, 1, fp);
                    // make a string of the particular char as long as the run length, store it in run
                    for (int j = 0; j < runlength[0]; j++) {
                        strcat(run, character);
                        }
                    // write the str of chars to stdout
                    fwrite(run, strlen(run), 1, stdout);
                    // ready for the next chunk
                    k = k+5;
                    }
                }
            }
        return 0;
        }
    }
