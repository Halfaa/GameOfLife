CC=gcc
CFLAGS=-Wall
SRC=source/
H_DIR=header
EXEC=$(SRC)GameOfLife

S_FILES =$(SRC)main.c \
			$(SRC)grid.c \
			$(SRC)game.c \
			$(SRC)settings.c


all: Build
Build:
	$(CC) $(CFLAGS) -I$(H_DIR) $(S_FILES) -o $(EXEC)

build_run: Build
	$(EXEC)

clean:
	rm -f $(EXEC)

