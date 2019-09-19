/*********************************************************
 * my-grep.c
 *
 * Your Name: Matthew Lowery
 *********************************************************/
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

// helper function that takes in an open file, reads from it line by line
// while printing the lines that have the searchterm included in it
void searcher(FILE *fp, char *searchterm) {
    char *buffer = NULL;
    size_t buffer_size = 0;
    ssize_t rf;
    // if searchterm is the empty string, match none of the lines
    if (searchterm[0] != '\0') {
        while ((rf = getline(&buffer, &buffer_size, fp)) != -1) {
         // use strstr to check if searchterm is a substring of buffer
            char *ss = strstr(buffer, searchterm);
            // return val of strstr isn't null for this line
            // so it contains the searchterm and we should print it
            if (ss) {
                printf("%s", buffer);
                }
            }
        }
    }

int main(int argc, char *argv[]) {
    char *searchterm = argv[1];
    // no command line args
    if (argc == 1) {
        printf("my-grep: searchterm [file ...]\n");
        exit(1);
        }
    // searchterm with no files, so we read from stdin
    else if (argc == 2) {
        searcher(stdin, searchterm);
        }
    // one or multiple files given
    else {
        for(int i = 2; i < argc; i++) {
            FILE *fp;
            // open file
            fp = fopen(argv[i], "r");
            // make sure fopen works
            if (fp == NULL) {
                printf("my-grep: cannot open file\n");
                exit(1);
                }
            else {
            // use the helper function to print the lines that have matches
                searcher(fp, searchterm);
                }
            // close the file
            fclose(fp);
            }
        return 0;
        }
    }
