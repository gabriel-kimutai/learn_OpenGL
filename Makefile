CC=g++
CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw3  -ldl -lpthread -lX11  -lXrandr -lXi -lGL -lGLEW

App: ./src/*.cpp
	$(CC) $(CFLAGS) -o ./build/App ./src/*.cpp $(LDFLAGS)

.PHONY: test clean

test: App
	./build/App
clean:
	rm -f ./build/App
