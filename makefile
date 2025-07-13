CC      = g++
CXXFLAGS= -std=c++17 -Wall `pkg-config --cflags opencv4`
LDFLAGS = `pkg-config --libs opencv4`

SRC     = main.cpp edges.cpp
OBJ     = main.o 
TARGET  = test_opencv
COMMAND = LD_PRELOAD=/lib/x86_64-linux-gnu/libpthread.so.0 ./test_opencv

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET) Images/edges_output.jpg Images/laplacian_edges_output.jpg

run: $(TARGET)
	 $(COMMAND)