include ../config

CFLAGS=-I../lib -I/usr/include/cppunit
LFLAGS=-L../lib -L/usr/lib64
LIBS=-lcppunit

clean:
	rm -f *.o
	rm -f tests

SOURCES := t.cpp testmemaddr.cpp

OBJS := $(SOURCES:.cpp=.o)

test: $(OBJS)
	$(CC) $(CFLAGS) -o tests $(OBJS) $(LFLAGS) $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<
