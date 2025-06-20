CC = g++
CFLAGS = -std=c++17 -Wall
LIBS = `pkg-config --cflags --libs opencv4` 

SRC = main.cpp
OBJ = main.o
TARGET = test_opencv

# Default rule
all:
	$(CC) $(CFLAGS) main.cpp -o test_opencv $(LIBS) 

# Compile source to object
main.o:
	$(CC) $(CFLAGS) -c main.cpp -o main.o

# Clean build files
clean:
	rm -f main.o test_opencv Images/edges_output.jpg Images/laplacian_edges_output.jpg

run: test_opencv
	./$(TARGET)