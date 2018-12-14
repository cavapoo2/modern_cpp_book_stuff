CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=auto.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=auto

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *.o ${EXECUTABLE}	
