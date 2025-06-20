CC = g++
CFLAGS = -std=c++17 -Wall
LIBS = `pkg-config --cflags --libs opencv4` -I/usr/local/imgui -ldl -lglfw

SRC = main.cpp
IMGUI_SRC = /usr/local/imgui/imgui.cpp
OBJ = main.o imgui.o
TARGET = test_opencv

all:
	$(CC) $(CFLAGS) main.o imgui.o -o test_opencv $(LIBS)

main.o:
	$(CC) $(CFLAGS) -I/usr/local/imgui -c main.cpp -o main.o

imgui.o:
	$(CC) $(CFLAGS) -I/usr/local/imgui -c /usr/local/imgui/imgui.cpp -o imgui.o

clean:
	rm -f main.o imgui.o test_opencv Images/edges_output.jpg Images/laplacian_edges_output.jpg

run:
	./test_opencv
