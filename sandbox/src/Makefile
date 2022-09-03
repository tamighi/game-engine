CC = c++
CFLAGS = -Wall -Wextra -Werror

OBJDIR = ../../bin-int/sandbox/
BINDIR = ../../bin/Debug-x64/

LIBSDBOX = $(BINDIR)sandbox/sandbox.a

VPATH = 
SRC = main.cpp
OBJ = $(addprefix $(OBJDIR), $(SRC:.cpp=.o))


$(OBJDIR)%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJ)
	ar rcs $(LIBSDBOX) $(OBJ)

clean: 
	rm -f $(LIBSDBOX)

fclean: clean
	rm -f $(OBJ)