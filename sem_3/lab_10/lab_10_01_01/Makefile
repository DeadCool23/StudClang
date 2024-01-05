CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion
INC= -I inc
UNIFLAGS = -lcheck -lm #-lsubunit
DYNLIBS = -lm

FUNC_TESTING = testing.sh
TEST_DIR = func_test
SRC = $(wildcard src/*.c)
MAIN = src/main.c
UNIT = $(wildcard unit_test/*.c)
UNISRC = $(filter-out $(MAIN), $(SRC)) $(UNIT)
HEADERS = $(filter-out $(wildcard inc/check_*.h), $(wildcard inc/*.h))

OBJDIR = out
OBJ = $(patsubst src/%.c, $(OBJDIR)/%.o, $(SRC))
UNIOBJ = $(patsubst unit_test/%.c, $(OBJDIR)/%.o, $(filter unit_test/%.c, $(UNISRC)))
UNIOBJ += $(patsubst src/%.c, $(OBJDIR)/%.o, $(filter src/%.c, $(UNISRC)))
UNIHEADERS = $(wildcard inc/check_*.h)

BUILD = 
TARGET = $(BUILD)app.exe
UNITARGET = $(BUILD)unit_tests.exe

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

.PHONY: clean
clean:
	$(RM) ./*.exe -r $(OBJDIR)

$(TARGET): $(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(DYNLIBS)

$(UNITARGET): $(OBJDIR) $(UNIOBJ)
	$(CC) $(INC) $(UNIOBJ) -o $@ $(CFLAGS) $(UNIFLAGS)

$(OBJDIR):
	@mkdir -p out

$(OBJDIR)/%.o: src/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJDIR)/%.o: unit_test/%.c $(UNIHEADERS)
	$(CC) -g $(INC) -c $< -o $@ $(CFLAGS)
