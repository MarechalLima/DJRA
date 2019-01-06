all: djra
ocv = "/usr/include/opencv4"
CC = g++
CFLAGS = -std=c++11
LDFLAGS = `pkg-config --static --libs opencv4` -lGL -lGLU -lglut
WARNINGS = -Wall
DEBUG = -ggdb -fno-omit-frame-pointer
OPTIMIZE = -O2
SOURCES = main.cpp background_render.cpp spheres.cpp render.cpp transition.cpp exit.cpp tutorial.cpp collision.cpp background_render.hpp spheres.hpp render.hpp transition.hpp exit.hpp tutorial.hpp collision.hpp
# SOURCES = main.cpp
djra: Makefile main.cpp
	env CPATH=$(ocv) $(CC) $(SOURCES) -o $@ $(WARNINGS) $(DEBUG) $(OPTIMIZE) $(LDFLAGS)

clean:
	rm -f djra

# Builder will call this to install the application before running.
install:
	echo "Installing is not supported"

# Builder uses this target to run your application.
run:
	./djra

