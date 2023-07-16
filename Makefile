# Compiler
CC = gcc
# Source files
SRC = src/*.c
# Name of executable file
Name = maze 
# Remove files
RM = rm -f
# Compiler flags
CFLAGS = -g -Wall -Werror -Wextra -pedantic
# Linker flags
LFLAGS = -lSDL2 -lSDL2_image -lm

# Compilation
all: $(SRC)
	$(CC) $(SRC) $(CFLAGS) $(LFLAGS) -o maze 
# Remove temporary files and executable
clean:
	$(RM) *~ $(NAME)
# Remove all created files and re-compile
re: clean all
