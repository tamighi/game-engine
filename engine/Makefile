CC = c++
CFLAGS = -Wall -Wextra -Werror

#	Outdirs
OBJDIR = ../bin-int/engine/
BINDIR = ../bin/Debug-x64/engine/

#	Src dirs !!The name VPATH is important here!!
VPATH = src/engine/
SRC=$(foreach d, $(VPATH), $(wildcard $d*.cpp))

#	Include dirs
INCDIR = vendor/spdlog/include
INC_PARAMS=$(foreach d, $(INC), -I$d)

#	Outfiles
LIB = $(BINDIR)engine.a
OBJ = $(addprefix $(OBJDIR), $(notdir $(SRC:.cpp=.o)))

$(OBJDIR)%.o: %.cpp %.hpp
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
