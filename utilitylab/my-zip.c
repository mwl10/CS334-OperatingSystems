/*********************************************************
 * my-zip.c
 *
 * Your Name: Matthew Lowery
 *********************************************************/
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

int main(int argc, char *argv[]) {
    // memory not being allocated?
    // buffer overflow for test 6? too big for the heap? 10150875 bytes
    char *mainbuffer = (char *)malloc(1000);
    // no arguements given
    if (argc == 1) {
        printf("my-zip: file1 [file2 ...]\n");
        exit(1);
      }
    else {
        // for each file
        for(int i = 1; i < argc; i++) {
            FILE *fp;
            fp = fopen(argv[i], "r");
            // fopen doesn't work
            if (fp == NULL) {
                printf("my-zip: cannot open file\n");
                exit(1);
                }
            // files open
            else {
                // don't have allocate memory for the buffer here as getline() does this dynamically
                // but this means we need to free it
                char *buffer = NULL;
                size_t buffer_size = 0;
                // reading the file, line by line
                while ((getline(&buffer, &buffer_size, fp)) != -1) {
                        // collect all the lines to one str
                        strcat(mainbuffer, buffer);
                        }
                // done with buffer
                free(buffer);
                }
            fclose(fp);
            }
        int j = 0;
        // mainbuffer now contains all the lines from each file
        // loop until we reach the end of the str
        while(j < strlen(mainbuffer)) {
            // variable to keep track of count of a particular characters run
            int runlength = 1;
            // make sure we don't try to index past the end of the mainbuffer
            if (j + 1 < strlen(mainbuffer)) {
                // loop until this particular letter's run ends
                while(mainbuffer[j] == mainbuffer[j+1]) {
                    // keep track of the run length
                    runlength++;
                    j++;
                    // make sure after we increment j we won't index past the end of mainbuffer again
                    if (j+1 >= strlen(mainbuffer)) {
                        break;
                        }
                    }
                }
            // write the runlength of the letter in correct form to stdout
            fwrite(&runlength, 4, 1, stdout);
            //write the particular character out to stdout
            fwrite(&mainbuffer[j], sizeof(mainbuffer[j]), 1, stdout);
            // next contrasting letter
            j++;
            }
        return 0;
        }
    }
