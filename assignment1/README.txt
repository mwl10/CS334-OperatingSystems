You need to write some instrumentation code to time a zero byte
write to standard out. You'll do this using the clock_gettime function
with the MONOTONIC clock_id and with the start_counter and get_counter
functions defined in clock.c.

Type 'make' to create the timer file and make clean to get rid of it.

Type 'make submit' to submit your assignment. 
