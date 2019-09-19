#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    struct timespec start, end;
    int nb;  // number of bytes read 
    unsigned long long telapsedsec = 0;
    unsigned long long telapsedns = 0;
    unsigned long long telapsed = 0;
    unsigned long long average = 0;
    unsigned long long sum = 0;

    // use clock_gettime with MONOTONIC
    
    // iterate a lot system calls to get a relatively consistent average
    for(int i = 0; i < 1000000; i++) {
    
    // get the start time
    clock_gettime(CLOCK_MONOTONIC, &start); 
   
    // What a useful system call!
    nb = write(fileno(stdout), NULL, 0);
     
    // get the end time
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    // get the elapsed time for the instance 
    telapsedns = (end.tv_nsec - start.tv_nsec);
    telapsedsec = ((end.tv_sec - start.tv_sec)*1000000000);
    telapsed = telapsedns + telapsedsec;

    // add the elapsed time to a sum so to calculate the average 
    sum += telapsed;
    }
    
    // get the average & print
    average = sum/1000000;
    printf("average elapsed time over 1,000,000 cycles = %11llu nanoseconds\n", average);
    
    if (nb != 0) {
        printf("Error with read\n");
    }
    return 0;
}
