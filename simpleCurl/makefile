CC=g++
INCLUDE=-I../../input_output/get_args -Idist/json
CFLAGS=-c -Wall -std=c++2a $(INCLUDE)
LDFLAGS=-lcurl
SOURCES=main.cpp dist/jsoncpp.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=simpleCurl

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *.o ${EXECUTABLE}	
