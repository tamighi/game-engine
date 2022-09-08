include ../top.mk

#	Outdirs
OBJDIR = ../$(BASEOBJDIR)$(ENGINE_DIR)
BINDIR = ../$(BASEBINDIR)$(ENGINE_DIR)

#	Src dirs !!The name VPATH is important here!!
VPATH = src/Engine/ 
SRC=$(foreach d, $(VPATH), $(wildcard $d*.cpp))

#	Precompiled header
PCH_SRC = src/pch.hpp
PCH_OUT = src/pch.hpp.gch

#	Include dirs
INCDIR = vendor/spdlog/include/ src/
INC_PARAMS=$(foreach d, $(INCDIR), -I$d) -include $(PCH_SRC)

#	Outfiles
NAME = $(BINDIR)$(ENGINE_LIB)
OBJ = $(addprefix $(OBJDIR), $(notdir $(SRC:.cpp=.o)))

$(OBJDIR)%.o: %.cpp $(PCH_OUT)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INC_PARAMS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJDIR) $(BINDIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(PCH_OUT): $(PCH_SRC)
	$(CC) $(CFLAGS) $(DEPFLAGS) $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean: 
	rm -rf $(BINDIR)

fclean: clean
	rm -rf $(OBJDIR) $(PCH_OUT) $(PCH_OUT:.gch=.d)

-include $(OBJ:%.o=%.d) $(PCH_OUT:.gch=.d)
