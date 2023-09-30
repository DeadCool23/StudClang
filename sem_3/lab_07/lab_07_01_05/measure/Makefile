CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -lm
INC= -I mes_inc

SRC = $(wildcard mes_src/*.c)

OBJDIR = mes_out
OBJ = $(patsubst mes_src/%.c, $(OBJDIR)/%.o, $(SRC))

BUILD = 
TARGET = $(BUILD)app.exe

DATA = data/mysort_sorted.txt data/qsort_sorted.txt data/mysort_reversed.txt data/qsort_reversed.txt data/mysort_random.txt data/qsort_random.txt
DRAWER = graphs_draw.sh

.PHONY: graphs_draw
graphs_draw: $(DATA)
	$(SHELL) $(DRAWER)

$(DATA): data

data: $(TARGET)
	./$(TARGET)

.PHONY: build
build: $(TARGET)

.PHONY: release
release: CFLAGS += -O3
release: $(TARGET)

.PHONY: debug
debug: CFLAGS += -g
debug: CFLAGS += -O0
debug: $(TARGET)


$(TARGET): $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS)

$(OBJDIR)/%.o: mes_src/%.c
	$(CC) $(INC) -c $< -o $@ $(CFLAGS)

.PHONY: clean
clean:
	$(RM) ./*.exe $(OBJ) $(DATA)
