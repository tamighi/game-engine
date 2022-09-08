ROOTDIR = ../
include $(ROOTDIR)top.mk

#	Outdirs
OBJDIR = $(ROOTDIR)$(BASEOBJDIR)$(SANDBOX_DIR)
BINDIR = $(ROOTDIR)$(BASEBINDIR)$(SANDBOX_DIR)

#	Src dirs 
VPATH = src/
SRC=$(foreach d, $(VPATH), $(wildcard $d*.cpp))

#	Include dirs
INCDIR = $(ROOTDIR)$(ENGINE_DIR)/vendor/spdlog/include/ $(ROOTDIR)$(ENGINE_DIR)src/
INC_PARAMS=$(foreach d, $(INCDIR), -I$d)

#	Outfiles
NAME = $(BINDIR)$(SANDBOX_NAME)
OBJ = $(addprefix $(OBJDIR), $(notdir $(SRC:.cpp=.o)))

$(OBJDIR)%.o: %.cpp 
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INC_PARAMS) -c $< -o $@

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
