# Using the gcc compiler
CC = g++

# Compile-time flags
CFLAGS = -std=c++11 -c 

# Include external header files
INCLUDES = -I../nsh

# Define the source files
SRCS = main.cpp boardClass.cpp

# Define the external libraries
LIBS = -lsfml-graphics -lsfml-window -lsfml-system 

# Define the object files
OBJS = $(SRCS:.cpp=.o)

# Define the name of the executable file
MAIN = MinesweeperApp

# Build the executable
default: $(MAIN)
		 @echo Compiled Minesweeper project successfully

# Files required to maintain the executable
$(MAIN): $(OBJS)
		 $(CC) $(OBJS) -o $(MAIN) $(LIBS)

# Compiles all .c files into .o files 
.c.o:
		 $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean up the old project
clean:
		 $(RM) *.o *~ $(MAIN)

