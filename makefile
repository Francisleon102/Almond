CC = g++
CXXFLAGS = -std=c++17 -Wall `pkg-config --cflags opencv4`
INCLUDES = -I/usr/local/include/imgui
#LIBS = `pkg-config --libs opencv4` -ldl -lglfw

SRC = main.cpp edges.cpp
IMGUI_SRC = /usr/local/include/imgui/imgui.cpp
OBJ = main.o edges.o imgui.o
TARGET = test_opencv

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(TARGET) `pkg-config --cflags opencv4`

%.o: %.cpp
	$(CC) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

imgui.o:
    $(CC) $(CXXFLAGS) $(INCLUDES) -c $(IMGUI_SRC) -o imgui.o

clean:
    rm -f $(OBJ) $(TARGET) Images/edges_output.jpg Images/laplacian_edges_output.jpg

run:
    ./$(TARGET)