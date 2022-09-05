CC = c++
CFLAGS = -Wall -Wextra -Werror

OBJDIR = ../bin-int/sandbox/
BINDIR = ../bin/Debug-x64/sandbox/
SRCDIR = src
INCDIR = ../engine/src/

LIBSDBOX = $(BINDIR)sandbox.a

VPATH = $(SRCDIR)
SRC = SandboxApp.cpp
OBJ = $(addprefix $(OBJDIR), $(SRC:.cpp=.o))


$(OBJDIR)%.o: %.cpp
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

all: $(OBJDIR) $(BINDIR) $(OBJ)
	ar rcs $(LIBSDBOX) $(OBJ)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean: 
	rm -rf $(BINDIR)

fclean: clean
	rm -rf $(OBJDIR)