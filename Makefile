include top.mk

OBJDIR = $(BASEOBJDIR)
BINDIR = $(BASEBINDIR)

LIBENG = $(BINDIR)$(ENGINE_DIR)$(ENGINE_LIB)
LIBSDBOX = $(BINDIR)$(SANDBOX_DIR)$(SANDBOX_LIB)
NAME = $(EXEC_NAME)

all: $(NAME)

$(NAME): $(OBJDIR) $(BINDIR) $(LIBENG) $(LIBSDBOX)
	$(CC) $(LIBSDBOX) $(LIBENG) -o $(NAME)

$(LIBENG): force_look
	make -C $(ENGINE_DIR)

$(LIBSDBOX): force_look
	make -C $(SANDBOX_DIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	make clean -C $(SANDBOX_DIR)
	make clean -C $(ENGINE_DIR)
	rm -rf bin
	rm -f $(NAME)

fclean: clean
	make fclean -C $(SANDBOX_DIR)
	make fclean -C $(ENGINE_DIR)
	rm -rf $(OBJDIR)

force_look:
