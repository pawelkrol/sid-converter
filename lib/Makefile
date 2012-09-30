include ../config

SOURCES := memaddr.cpp siddata.cpp sidfile.cpp

OBJS := $(SOURCES:.cpp=.o)

clean:
	rm -f *.o

compile: $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<
