CC = gcc
VALGRIND = valgrind --leak-check=full --quiet

CFLAGS = -std=c99 -Wall -Werror -Wextra -Wvla -Wfloat-equal -Wfloat-conversion
OBJFLAGS = 

INC= -I inc

FUNC_TESTING = testing.sh
TEST_DIR = func_test

MAIN = src/main.c
SRC = $(wildcard src/*.c)
HEADERS = $(wildcard inc/*.h)

OBJDIR = out
OBJ = $(patsubst src/%.c, $(OBJDIR)/%.o, $(filter-out $(LIBSRC), $(SRC)))

LIBLOAD = -ldl

BUILD = 
TARGET = $(BUILD)app.exe
UNITARGET = $(BUILD)unit_tests.exe

.PHONY: asan
asan: CC = clang
asan: OBJFLAGS += -O0
asan: OBJFLAGS += -g3
asan: OBJFLAGS += -fno-omit-frame-pointer
asan: CFLAGS += -fsanitize=address
asan: $(TARGET)

.PHONY: msan
msan: CC = clang
msan: OBJFLAGS += -O0
msan: OBJFLAGS += -g3
msan: OBJFLAGS += -fno-omit-frame-pointer
msan: CFLAGS += -fsanitize=memory
msan: $(TARGET)

.PHONY: ubsan
ubsan: CC = clang
ubsan: OBJFLAGS += -O0
ubsan: OBJFLAGS += -g3
ubsan: OBJFLAGS += -fno-omit-frame-pointer
ubsan: CFLAGS += -fsanitize=undefined
ubsan: $(TARGET)

.PHONY: coverage
coverage: CFLAGS += --coverage
coverage: $(TARGET)

.PHONY: build
build: $(TARGET)

.PHONY: release
release: CFLAGS += -O3
release: $(TARGET)

.PHONY: func
func: $(TEST_DIR)/$(FUNC_TESTING)
	cd $(TEST_DIR) && bash $(FUNC_TESTING) -v

.PHONY: debug
debug: CFLAGS += -g
debug: CFLAGS += -O0
debug: $(TARGET)

.PHONY: clean
clean:
	$(RM) ./*.exe -r $(OBJDIR)

$(TARGET): $(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INC) $(LIBLOAD) -o $@

$(OBJDIR):
	mkdir -p $@

$(OBJDIR)/%.o: src/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) $(OBJFLAGS) -c $< -o $@