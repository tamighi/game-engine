ROOTDIR = ../
include $(ROOTDIR)top.mk

#	Outdirs
OBJDIR = $(ROOTDIR)$(BASEOBJDIR)$(ENGINE_DIR)
BINDIR = $(ROOTDIR)$(BASEBINDIR)$(ENGINE_DIR)

#	Src dirs
VPATH = src/Engine/ src/Platform/Linux/
SRC = $(foreach d, $(VPATH), $(wildcard $d*.cpp))

#	Precompiled header
PCH_SRC = src/pch.hpp
PCH_OUT = src/pch.hpp.gch
INC_PCH = -include $(PCH_SRC)

#	Include dirs
INCDIR = vendor/spdlog/include/ src/ vendor/GLFW/include/
INC_PARAMS = $(foreach d, $(INCDIR), -I$d)

#	Outfiles
NAME = $(BINDIR)$(ENGINE_NAME)
OBJ = $(addprefix $(OBJDIR), $(notdir $(SRC:.cpp=.o)))

$(OBJDIR)%.o: %.cpp $(PCH_OUT)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INC_PARAMS) $(INC_PCH) -c $< -o $@

all: $(NAME)

$(NAME): Makefile | $(BINDIR) $(OBJDIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(PCH_OUT): $(PCH_SRC)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INC_PARAMS) $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean: 
	rm -rf $(BINDIR)

fclean: clean
	rm -rf $(OBJDIR) $(PCH_OUT) $(PCH_OUT:.gch=.d)

-include $(OBJ:%.o=%.d) $(PCH_OUT:.gch=.d)
