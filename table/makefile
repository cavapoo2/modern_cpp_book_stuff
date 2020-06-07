CC=g++
INCLUDE=-I../../input_output/get_args
CFLAGS=-c -Wall -std=c++11 $(INCLUDE)
LDFLAGS=
SOURCES=main.cpp table.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=prog

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *.o ${EXECUTABLE}	
