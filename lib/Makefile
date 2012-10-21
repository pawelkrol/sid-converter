include ../config

SOURCES := memaddr.cpp siddata.cpp sidheader.cpp sidheaderv2.cpp sidfile.cpp sidflags.cpp sidstring.cpp sidutils.cpp

OBJS := $(SOURCES:.cpp=.o)

clean:
	rm -f *.o

compile: $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<
