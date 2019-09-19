CC = gcc
CFLAGS = -g -Wall -Og


TARGETA = timer

all: $(TARGETA)

$(TARGETA): $(TARGETA).c
	$(CC) $(CFLAGS) -o $(TARGETA) $(TARGETA).c

clean:
	$(RM) $(TARGETA)

submit:
	cp answers.txt timer.c assignment1-submit
	submit334 assignment1-submit assignment1-submit

