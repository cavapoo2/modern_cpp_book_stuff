CC=g++
INCLUDE=-I../../input_output/get_args -I../dist
CFLAGS=-c -Wall -std=c++2a $(INCLUDE)
LDFLAGS=-lcurl
SOURCES=main.cpp ../dist/jsoncpp.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=params

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *.o ${EXECUTABLE}	
