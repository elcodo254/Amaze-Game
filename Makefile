# Compiler
CC = gcc
# Source files
SRC = *.c
# Object files
OBJ = $(SRC:.c=.o)
# Name of executable file
Name = main
# Remove files
RM = rm -f
# Compiler flags
CFLAGS = -Wall -Werror -Wextra -pedantic
# Linker flags
LFLAGS = -lSDL2 -lSDL2_image -lm

# Compilation
all: $(SRC)
	$(CC) $(SRC) $(CFLAGS) $(LFLAGS) -o main
# Remove temporary files and executable
clean:
	$(RM) *~ $(NAME)
# Remove object files
oclean:
	$(RM) $(OBJ)
# Remove temporary,object and executable files
fclean: clean oclean
# Remove all created files and re-compile
re: fclean all
