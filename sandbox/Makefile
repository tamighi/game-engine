CC = c++
CFLAGS = -Wall -Wextra -Werror

#	Outdirs
OBJDIR = ../bin-int/sandbox/
BINDIR = ../bin/Debug-x64/sandbox/

#	Src dirs !!The name VPATH is important here!!
VPATH = src/
SRC=$(foreach d, $(VPATH), $(wildcard $d*.cpp))

#	Inc dirs
INCDIR = ../engine/src ../engine/vendor/spdlog/include
INC_PARAMS=$(foreach d, $(INCDIR), -I$d)

#	Out files
LIB = $(BINDIR)sandbox.a
OBJ = $(addprefix $(OBJDIR), $(notdir $(SRC:.cpp=.o)))


$(OBJDIR)%.o: %.cpp
	$(CC) $(CFLAGS) $(INC_PARAMS) -c $< -o $@

all: $(OBJDIR) $(BINDIR) $(OBJ)
	ar rcs $(LIB) $(OBJ)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean: 
	rm -rf $(BINDIR)

fclean: clean
	rm -rf $(OBJDIR)