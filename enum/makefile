CC=g++
CFLAGS=-c -Wall -std=c++2a
LDFLAGS=
SOURCES=enum.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=enum

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *.o ${EXECUTABLE}	
