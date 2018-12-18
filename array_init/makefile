CC=g++
CFLAGS=-c -Wall -std=c++2a
LDFLAGS=
SOURCES=init.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=init

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *.o ${EXECUTABLE}	
