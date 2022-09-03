CALLED_FROM_TOP = true
export CALLED_FROM_TOP

CC = c++
CFLAGS = -Wall -Wextra -Werror

OBJDIR = bin-int/sandbox/
BINDIR = bin/Debug-x64/

LIBENG = $(BINDIR)engine/engine.a
LIBSDBOX = $(BINDIR)sandbox/sandbox.a
EXEC = exec

all:
	cd engine/src; make
	cd sandbox/src; make
	$(CC) $(CFLAGS) $(LIBSDBOX) $(LIBENG) -o $(EXEC)

clean:
	cd engine/src; make clean
	cd sandbox/src; make clean
	rm -f $(EXEC)

fclean:
	cd engine/src; make fclean
	cd sandbox/src; make fclean