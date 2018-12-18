CC=g++
CFLAGS=-c -Wall -std=c++2a
LDFLAGS=
SOURCES=exception.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=excep

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *.o ${EXECUTABLE}	
