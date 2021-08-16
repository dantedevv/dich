SRCS += scandir.c
LIBNAME += libdirscaner.so

all:
		gcc $(SRCS) -o $(LIBNAME) -shared -fPIC

install:
		cp $(LIBNAME) /usr/lib
		cp scandir.h /usr/include

uninstall:
		rm -f /usr/lib/$(LIBNAME) /usr/include/scandir.h

clean:
		rm -f $(LIBNAME) *.o