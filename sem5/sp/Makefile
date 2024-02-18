CC = gcc
CFLAGS = -Wall -Werror

# Debug build
debug: CFLAGS += -g
debug: sp
# Release build
release: CFLAGS += -O2
release: sp

sp: sp.c
	$(CC) $(CFLAGS) -o sp_build sp.c
	./sp_build



.PHONY: debug release clean sp
clean:
	rm -f sp_build