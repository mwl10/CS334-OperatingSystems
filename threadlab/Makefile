# Default set to debugging flags. 
CFLAGS?=-g -Wall -Wno-unused-value -Og

CC=gcc

all: train reaction

train: train-runner.c train.c thread.h
	$(CC) $(CFLAGS) -o train train-runner.c -lpthread 

reaction: reaction-runner.c reaction.c thread.h
	$(CC) $(CFLAGS) -o reaction reaction-runner.c -lpthread 

run: train reaction
	./train
	./train
	./train
	./reaction 0
	./reaction 0
	./reaction 20
	./reaction 20
	./reaction 40
	./reaction 40
	./reaction 60
	./reaction 60
	./reaction 80
	./reaction 80
	./reaction 100
	./reaction 100

submit:
	cp -f train.c reaction.c threadlab-submit
	submit334 threadlab-submit threadlab-submit

clean:
	$(RM) train reaction
