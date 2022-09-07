include ../top.mk

#	Outdirs
OBJDIR = ../$(BASEOBJDIR)$(SANDBOX_DIR)
BINDIR = ../$(BASEBINDIR)$(SANDBOX_DIR)

#	Src dirs !!The name VPATH is important here!!
VPATH = src/
SRC=$(foreach d, $(VPATH), $(wildcard $d*.cpp))

#	Include dirs
INCDIR = ../Engine/vendor/spdlog/include/ ../Engine/src/
INC_PARAMS=$(foreach d, $(INCDIR), -I$d)

#	Outfiles
NAME = $(BINDIR)$(SANDBOX_LIB)
OBJ = $(addprefix $(OBJDIR), $(notdir $(SRC:.cpp=.o)))

$(OBJDIR)%.o: %.cpp 
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

-include $(OBJ:%.o=%.d)
