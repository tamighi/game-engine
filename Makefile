include top.mk

OBJDIR = $(BASEOBJDIR)
BINDIR = $(BASEBINDIR)

GLFWLIB = $(BINDIR)$(GLFW_DIR)$(GLFW_NAME)
ENGLIB = $(BINDIR)$(ENGINE_DIR)$(ENGINE_NAME)
SDBOXLIB = $(BINDIR)$(SANDBOX_DIR)$(SANDBOX_NAME)

NAME = $(EXEC_NAME)

all: check_os $(NAME)

check_os:
ifeq ($(detected_OS), Linux)
	@echo Linux detected.
else
	@echo Platform $(detected_OS) not supported.
	exit 1
endif

$(NAME): $(OBJDIR) $(BINDIR) $(GLFWLIB) $(ENGLIB) $(SDBOXLIB)
	$(CC) -o $(NAME) $(SDBOXLIB) $(ENGLIB) $(GLFWLIB) 

$(ENGLIB): force_look
	make -C $(ENGINE_DIR)

$(SDBOXLIB): force_look
	make -C $(SANDBOX_DIR)

$(GLFWLIB): force_look
	make -C $(ENGINE_DIR)vendor/$(GLFW_DIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	make clean -C $(SANDBOX_DIR)
	make clean -C $(ENGINE_DIR)
	make clean -C $(ENGINE_DIR)vendor/$(GLFW_DIR)
	rm -rf bin
	rm -f $(NAME)

fclean: clean
	make fclean -C $(SANDBOX_DIR)
	make fclean -C $(ENGINE_DIR)
	make fclean -C $(ENGINE_DIR)vendor/$(GLFW_DIR)
	rm -rf $(OBJDIR)

force_look:
