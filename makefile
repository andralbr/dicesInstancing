# g++ -x c++ first_program.cpp -x c glad.c -lglfw -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

# Compiler options
CC = gcc
CXX = g++
CXXFLAGS = -std=c++11
CFLAGS =
debug: CXXFLAGS = -g -std=c++11
debug: CFLAGS = -g

# Name of Binary Output file
OUTFILE = cubes

# makefile
THISFILE = makefile

# include directory (/usr/local/include)
IDIR = /Users/andreas/Documents/programming/OpenGL/glm/
CINCL = -I$(IDIR)

# folder for object files
ODIR = ./obj

# libraries
LDIR = /usr/local/lib
# or -lglfw3 for static library, 
CLIB = -lglfw

# MAC frameworks, -framework GLUT
CFRAME = -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

# Object files
_OBJ = \
	main.o \
	libs/glad.o \
	libs/shader_input.o \
	libs/stb_image.o

OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))	

# Dependencies
DEPS = \
	./libs/camera.h \
	./libs/shader_input.h	


program: folder_exists $(OBJ)
	$(CXX) $(OBJ) -v -o $(OUTFILE) $(CLIB) $(CFRAME)

debug: folder_exists $(OBJ)
	$(CXX) $(OBJ) -o $(OUTFILE) $(CLIB) $(CFRAME)

# ! shell command must be in one line, if test <=> if []
folder_exists:
	if [ ! -d "$(ODIR)" ]; then mkdir $(ODIR); fi
	if [ ! -d "$(ODIR)/libs" ]; then mkdir $(ODIR)/libs; fi

$(ODIR)/%.o: %.c 
	$(CC) $(CFLAGS) -c -o $@ $<
	@echo "Compiling C-file"

$(ODIR)/%.o : ./%.cpp $(DEPS) $(THISFILE)
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	@echo "Compiling C++ files"


clean:
	rm -f $(ODIR)/*.o *~ 	

