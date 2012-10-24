include ../config

CFLAGS=-I../lib -I/usr/include/cppunit
LFLAGS=-L../lib -L/usr/lib64
LIBS=-lcppunit

clean:
	rm -f *.o
	rm -f $(TEST_EXEC_FILENAME)

SOURCES := testrunner.cpp testmemaddr.cpp testsiddata.cpp testsidfile.cpp testsidfileutils.cpp testsidflags.cpp testsidheader.cpp testsidstring.cpp testutils.cpp

OBJS := $(SOURCES:.cpp=.o)

LIBS += ../lib/memaddr.o ../lib/sidexception.o ../lib/siddata.o ../lib/sidfile.o ../lib/sidfileutils.o ../lib/sidflags.o ../lib/sidheader.o ../lib/sidheaderv2.o ../lib/sidstring.o ../lib/sidutils.o

test-compile: $(OBJS)
	$(CC) $(DEBUG_OPTS) $(CFLAGS) -o $(TEST_EXEC_FILENAME) $(OBJS) $(LFLAGS) $(LIBS)
	chmod u+x $(TEST_EXEC_FILENAME)

test: test-compile
	./$(TEST_EXEC_FILENAME)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<
