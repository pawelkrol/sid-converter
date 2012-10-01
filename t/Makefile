include ../config

CFLAGS=-I../lib -I/usr/include/cppunit
LFLAGS=-L../lib -L/usr/lib64
LIBS=-lcppunit

clean:
	rm -f *.o
	rm -f $(TEST_EXEC_FILENAME)

SOURCES := testrunner.cpp testmemaddr.cpp

OBJS := $(SOURCES:.cpp=.o)

LIBS += ../lib/memaddr.o

test-compile: $(OBJS)
	$(CC) $(CFLAGS) -o $(TEST_EXEC_FILENAME) $(OBJS) $(LFLAGS) $(LIBS)
	chmod u+x $(TEST_EXEC_FILENAME)

test: test-compile
	./$(TEST_EXEC_FILENAME)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<
