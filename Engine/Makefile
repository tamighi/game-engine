include ../top.mk

#	Outdirs
OBJDIR = ../$(BASEOBJDIR)$(ENGINE_DIR)
BINDIR = ../$(BASEBINDIR)$(ENGINE_DIR)

#	Src dirs !!The name VPATH is important here!!
VPATH = src/Engine/ 
SRC=$(foreach d, $(VPATH), $(wildcard $d*.cpp))

#	Include dirs
INCDIR = vendor/spdlog/include/ src/
INC_PARAMS=$(foreach d, $(INCDIR), -I$d)

#	Outfiles
NAME = $(BINDIR)$(ENGINE_LIB)
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

