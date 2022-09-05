CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11

#	Outdirs
OBJDIR = ../bin-int/sandbox/
BINDIR = ../bin/Debug-x64/sandbox/

#	Src dirs !!The name VPATH is important here!!
VPATH = src/
SRC=$(foreach d, $(VPATH), $(wildcard $d*.cpp))

#	Include dirs
INCDIR = ../engine/vendor/spdlog/include/ ../engine/src/
INC_PARAMS=$(foreach d, $(INCDIR), -I$d)

#	Outfiles
LIB = $(BINDIR)sandbox.a
OBJ = $(addprefix $(OBJDIR), $(notdir $(SRC:.cpp=.o)))

$(OBJDIR)%.o: %.cpp $(INCDIR)*.hpp
	$(CC) $(CFLAGS) $(INC_PARAMS) -c $< -o $@

all: $(LIB)

$(LIB): $(OBJDIR) $(BINDIR) $(OBJ)
	ar rcs $(LIB) $(OBJ)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean: 
	rm -rf $(BINDIR)

fclean: clean
	rm -rf $(OBJDIR)