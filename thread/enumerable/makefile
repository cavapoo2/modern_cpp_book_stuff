CC=g++
INCLUDE=-I../../input_output/get_args
CFLAGS=-c -Wall -std=c++2a $(INCLUDE)
LDFLAGS=
SOURCES=enumer.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=enumer

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *.o ${EXECUTABLE}	
