CC = gcc
CFLAGS = -Wall

# Debug build
debug: CFLAGS += -g
debug: scn

# Release build
release: CFLAGS += -O2
release: scn

scn: scn.c
	$(CC) $(CFLAGS) -o scn_build scn.c
	echo "5 world 13 Hello, world!" | ./scn_build
	echo "3 abc 51 qffUt g abcykvabcb x Lv BRabc g KUrabcN wQabcylz R" | ./scn_build
	echo "5 xExEx 73 h E EMRTxExEx iAxExExbTxExEx xExExG Tkp xExExcTDxExEx q xCjUfxExEx dahfS" | ./scn_build

.PHONY: debug release clean scn
clean:
	rm -f *build