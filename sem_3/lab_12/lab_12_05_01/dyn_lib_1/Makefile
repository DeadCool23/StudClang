CC = gcc
VALGRIND = valgrind --leak-check=full --quiet

CFLAGS = -std=c99 -Wall -Werror -Wextra -Wvla -Wfloat-equal -Wfloat-conversion
OBJFLAGS = 

INC= -I inc
UNITLIBS = -lcheck -lm -lsubunit

FUNC_TESTING = testing.sh
TEST_DIR = func_test

MAIN = src/main.c
SRC = $(wildcard src/*.c)
UNISRC = $(wildcard unit_test/*.c)
LIBSRC = $(filter-out $(MAIN), $(SRC))
HEADERS = $(filter-out $(wildcard inc/check_*.h), $(wildcard inc/*.h))

OBJDIR = out
OBJ = $(patsubst src/%.c, $(OBJDIR)/%.o, $(filter-out $(LIBSRC), $(SRC)))
UNIOBJ = $(patsubst unit_test/%.c, $(OBJDIR)/%.o, $(filter unit_test/%.c, $(UNISRC)))
LIBSOBJ = $(patsubst src/%.c, $(OBJDIR)/lib_%.o, $(LIBSRC))
UNIHEADERS = $(wildcard inc/check_*.h)

LIBSDIR = libs
LIBS = $(LIBSDIR)/libarr.so
LIBLINK = $(patsubst $(LIBSDIR)/lib%.so, -l%, $(LIBS))

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

.PHONY: unit
unit: $(UNITARGET)
	./$(UNITARGET)

.PHONY: debug_unit
debug_unit: CFLAGS += -g
debug_unit: $(UNITARGET)
	$(VALGRIND) ./$(UNITARGET)

.PHONY: clean
clean:
	$(RM) ./*.exe -r $(OBJDIR) $(LIBSDIR)

.PHONY: dyn_lib
dyn_lib: $(OBJDIR) $(LIBSDIR) $(LIBS)

$(TARGET): $(OBJDIR) $(LIBSDIR) $(LIBS) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L./$(LIBSDIR) $(LIBLINK) -Wl,-rpath=./$(LIBSDIR) -o $@

$(UNITARGET): $(OBJDIR) $(LIBSDIR) $(LIBS) $(UNIOBJ)
	$(CC) $(INC) $(UNIOBJ) -o $@ $(CFLAGS) -L./$(LIBSDIR) $(LIBLINK) -Wl,-rpath=./$(LIBSDIR) $(UNITLIBS)

$(OBJDIR):
	mkdir -p $@

$(LIBSDIR):
	mkdir -p $@

$(LIBS): $(LIBSOBJ)
	$(CC) $(CFLAGS) $(INC) -shared $^ -o $@

$(OBJDIR)/lib_%.o: src/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) $(OBJFLAGS) -fPIC -c $< -o $@

$(OBJDIR)/%.o: src/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) $(OBJFLAGS) -c $< -o $@

$(OBJDIR)/%.o: unit_test/%.c $(UNIHEADERS)
	$(CC) $(INC) -c $< -o $@ $(CFLAGS)
