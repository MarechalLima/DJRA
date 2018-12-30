all: djra

CC = g++
CFLAGS = -std=c++11
LDFLAGS = `pkg-config --static --libs opencv4` -lGL -lglut
WARNINGS = -Wall
DEBUG = -ggdb -fno-omit-frame-pointer
OPTIMIZE = -O2
SOURCES = main.cpp background_render.cpp spheres.cpp render.cpp transition.cpp exit.cpp tutorial.cpp collision.cpp

djra: Makefile main.cpp
	$(CC) $(CFLAGS) -o djra $(WARNINGS) $(DEBUG) $(OPTIMIZE) $(SOURCES) $(LDFLAGS)

clean:
	rm -f djra

# Builder will call this to install the application before running.
install:
	echo "Installing is not supported"

# Builder uses this target to run your application.
run:
	./djra

