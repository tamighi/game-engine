CC = c++
CFLAGS = -Wall -Wextra -Werror

OBJDIR = ../../bin-int/engine/
BINDIR = ../../bin/Debug-x64/engine/

LIBENG = $(BINDIR)engine.a

VPATH = test
SRC =	test.cpp  \
		test2.cpp

OBJ = $(addprefix $(OBJDIR), $(SRC:.cpp=.o))


$(OBJDIR)%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJDIR) $(BINDIR) $(OBJ)
	ar rcs $(LIBENG) $(OBJ)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean: 
	rm -rf $(BINDIR)

fclean: clean
	rm -rf $(OBJDIR)
