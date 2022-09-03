CC = c++
CFLAGS = -Wall -Wextra -Werror

OBJDIR = ../../bin-int/engine/
BINDIR = ../../bin/Debug-x64/

LIBENG = $(BINDIR)engine/engine.a

VPATH = test
SRC =	test.cpp  \
		test2.cpp
OBJ = $(addprefix $(OBJDIR), $(SRC:.cpp=.o))


$(OBJDIR)%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJ)
	ar rcs $(LIBENG) $(OBJ)

clean: 
	rm -f $(LIBENG)

fclean: clean
	rm -f $(OBJ)
