CC = g++
CFLAGS = -std=c++17 -Wall
INCLUDES = -I/usr/local/include/imgui
LIBS = `pkg-config --cflags --libs opencv4` -ldl -lglfw

SRC = main.cpp edges.cpp
IMGUI_SRC = /usr/local/include/imgui/imgui.cpp
OBJ = main.o edges.o imgui.o
TARGET = test_opencv

<<<<<<< HEAD
# Default rule
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) main.cpp -o $(TARGET) $(LIBS)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)
=======
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

imgui.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $(IMGUI_SRC) -o imgui.o
>>>>>>> refs/remotes/origin/main

clean:
	rm -f $(OBJ) $(TARGET) Images/edges_output.jpg Images/laplacian_edges_output.jpg

run:
	./$(TARGET)
