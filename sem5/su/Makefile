CC = gcc
CFLAGS = -Wall -Werror

# Debug build
debug: CFLAGS += -g
debug: su
# Release build
release: CFLAGS += -O2
release: su

su: su.c
	$(CC) $(CFLAGS) -o su_build su.c
	./su_build



.PHONY: debug release clean su
clean:
	rm -f su_build