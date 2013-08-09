CC=gcc
CFLAGS=-Wall -fPIC -I/usr/include/lua5.1 -shared
LDFLAGS=-lcrypt -llua5.1

all: 
	$(CC) $(CFLAGS) -o crypt.so luacrypt.c $(LDFLAGS) 

install:
	cp crypt.so /usr/local/lib/lua/5.1/

clean:
	rm -f crypt.so
