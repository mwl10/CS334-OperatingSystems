CC = gcc
CFLAGS = -g -Wall -Og


LABNAME = utilitylab

all: my-cat my-grep my-zip my-unzip

my-cat: my-cat.c
	$(CC) $(CFLAGS) -o my-cat my-cat.c 

my-grep: my-grep.c
	$(CC) $(CFLAGS) -o my-grep my-grep.c 

my-zip: my-zip.c
	$(CC) $(CFLAGS) -o my-zip my-zip.c 

my-unzip: my-unzip.c
	$(CC) $(CFLAGS) -o my-unzip my-unzip.c 

clean:
	$(RM) my-cat my-grep my-zip my-unzip

test-cat: my-cat
	cd test-cat ; ./test-cat.sh

test-grep: my-grep
	cd test-grep ; ./test-grep.sh

test-zip: my-zip
	cd test-zip ; ./test-zip.sh

test-unzip: my-unzip
	cd test-unzip ; ./test-unzip.sh

submit:
	cp my-cat.c my-grep.c my-zip.c my-unzip.c $(LABNAME)-submit
	submit334 $(LABNAME)-submit $(LABNAME)-submit


