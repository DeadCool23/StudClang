CC = gcc
PYTON = python3
VALGRIND = valgrind --leak-check=full --quiet

CFLAGS = -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion
INC= -I inc
UNITLIBS = -lcheck -lm -lsubunit

LIBSRC = $(wildcard lib_src/*.c)
UNISRC = $(wildcard unit_test/*.c)

UNIHEADERS = $(wildcard inc/check_*.h)
HEADERS = $(filter-out $(wildcard inc/check_*.h), $(wildcard inc/*.h))

OBJDIR = out
UNIOBJ = $(patsubst unit_test/%.c, $(OBJDIR)/%.o, $(UNISRC))
LIBSOBJ = $(patsubst lib_src/%.c, $(OBJDIR)/lib_%.o, $(LIBSRC))

LIBSDIR = libs
LIBS = $(LIBSDIR)/libarr.so
LIBLINK = $(patsubst $(LIBSDIR)/lib%.so, -l%, $(LIBS))

BUILD =
UNITARGET = $(BUILD)unit_tests.exe

PYTON_MAIN = main.py

.PHONY: run
run: build_lib
	$(PYTON) $(PYTON_MAIN)

.PHONY: build_lib
build_lib: $(OBJDIR) $(LIBSDIR) $(LIBS)

.PHONY: unit
unit: $(UNITARGET)
	./$(UNITARGET)

.PHONY: debug_unit
debug_unit: CFLAGS += -g
debug_unit: $(UNITARGET)
	$(VALGRIND) ./$(UNITARGET)

.PHONY: clean
clean:
	$(RM) -r $(OBJDIR) $(LIBSDIR) *.exe

$(UNITARGET): $(OBJDIR) $(LIBSDIR) $(LIBS) $(UNIOBJ)
	$(CC) $(INC) $(UNIOBJ) -o $@ $(CFLAGS) -L./$(LIBSDIR) $(LIBLINK) -Wl,-rpath=./$(LIBSDIR) $(UNITLIBS)

$(OBJDIR):
	mkdir -p $@

$(LIBSDIR):
	mkdir -p $@

$(LIBS): $(LIBSOBJ)
	$(CC) $(CFLAGS) $(INC) -shared -g $^ -o $@

$(OBJDIR)/lib_%.o: lib_src/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -fPIC -g -c $< -o $@

$(OBJDIR)/%.o: unit_test/%.c $(UNIHEADERS)
	$(CC) $(INC) -c $< -o $@ $(CFLAGS)
