CC=g++
INC=.
CFLAGS=-c -Wall -I$(INC) -std=c++2a
LDFLAGS=
SOURCES=Garage.cpp garageTest.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=stock

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *.o ${EXECUTABLE}	
