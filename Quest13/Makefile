APPNAME += main
SRSC += main.c
SRSC += tempf.c


all:
		gcc $(SRSC) -o $(APPNAME)

debug:
		gcc $(SRSC) -o $(APPNAME) -g -O0 -DDEBUG

clean:
		rm -f *.o $(APPNAME)