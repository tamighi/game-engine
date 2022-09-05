CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11

#	Outdirs
OBJDIR = ../bin-int/engine/
BINDIR = ../bin/Debug-x64/engine/

#	Src dirs !!The name VPATH is important here!!
VPATH = src/engine/
SRC=$(foreach d, $(VPATH), $(wildcard $d*.cpp))

#	Include dirs
INCDIR = vendor/spdlog/include/ src/engine/
INC_PARAMS=$(foreach d, $(INCDIR), -I$d)

#	Outfiles
NAME = $(BINDIR)engine.a
OBJ = $(addprefix $(OBJDIR), $(notdir $(SRC:.cpp=.o)))

$(OBJDIR)%.o: %.cpp $(INCDIR)*.hpp
	$(CC) $(CFLAGS) $(INC_PARAMS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJDIR) $(BINDIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean: 
	rm -rf $(BINDIR)

fclean: clean
	rm -rf $(OBJDIR)
