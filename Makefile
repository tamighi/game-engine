CALLED_FROM_TOP = true
export CALLED_FROM_TOP

CC = c++
CFLAGS = -Wall -Wextra -Werror

OBJDIR = bin-int/
BINDIR = bin/Debug-x64/

LIBENG = $(BINDIR)engine/engine.a
LIBSDBOX = $(BINDIR)sandbox/sandbox.a
NAME = exec

all: $(NAME)

$(NAME): $(OBJDIR) $(BINDIR) $(LIBENG) $(LIBSDBOX)
	$(CC) $(CFLAGS) $(LIBSDBOX) $(LIBENG) -o $(NAME)

$(LIBENG): force_look
	make -C engine/

$(LIBSDBOX): force_look
	make -C sandbox/

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	rm -rf bin
	rm -f $(NAME)

fclean: clean
	rm -rf $(OBJDIR)

force_look:
	true
