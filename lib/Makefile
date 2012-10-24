include ../config

SOURCES := memaddr.cpp siddata.cpp sidexception.cpp sidfile.cpp sidfileutils.cpp sidflags.cpp sidheader.cpp sidheaderv2.cpp sidstring.cpp sidutils.cpp

OBJS := $(SOURCES:.cpp=.o)

clean:
	rm -f *.o

compile: $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<
