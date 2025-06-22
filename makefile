CC = g++
CFLAGS = -std=c++17 -Wall
LIBS = `pkg-config --cflags --libs opencv4` 

SRC = main.cpp
OBJ = main.o
TARGET = test_opencv

# Default rule
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) main.cpp -o $(TARGET) $(LIBS)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET) Images/edges_output.jpg Images/laplacian_edges_output.jpg

run:
	./$(TARGET)
