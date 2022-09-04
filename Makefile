CALLED_FROM_TOP = true
export CALLED_FROM_TOP

CC = c++
CFLAGS = -Wall -Wextra -Werror

OBJDIR = bin-int/
BINDIR = bin/Debug-x64/

LIBENG = $(BINDIR)engine/engine.a
LIBSDBOX = $(BINDIR)sandbox/sandbox.a
EXEC = exec

all: $(OBJDIR) $(BINDIR)
	cd engine/src; make
	cd sandbox/src; make
	$(CC) $(CFLAGS) $(LIBSDBOX) $(LIBENG) -o $(EXEC)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	rm -rf bin
	rm -f $(EXEC)

fclean: clean
	rm -rf $(OBJDIR)