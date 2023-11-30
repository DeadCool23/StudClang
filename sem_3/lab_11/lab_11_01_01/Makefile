CC = gcc
VALGRIND = valgrind --leak-check=full --quiet
CFLAGS = -std=gnu99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion
UNIFLAGS = -lcheck -lm -lsubunit
INC = -I inc

SRCDIR = src
UNITDIR = unit_tests
SRC = $(wildcard $(SRCDIR)/*.c) $(wildcard $(UNITDIR)/*.c)
HEADERS = $(wildcard inc/*.h)

OBJDIR = ./out
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(filter-out $(UNITDIR)/%.c, $(SRC)))
OBJ += $(patsubst $(UNITDIR)/%.c, $(OBJDIR)/%.o, $(filter-out $(SRCDIR)/%.c, $(SRC)))

UNITARGET = unit_tests.exe

debug_unit: CFLAGS += -g
debug_unit: $(UNITARGET)
	$(VALGRIND) ./$(UNITARGET)

.PHONY: unit
unit: $(UNITARGET)
	./$(UNITARGET)

.PHONY: clean
clean:
	$(RM) $(UNITARGET) -r $(OBJDIR)

$(UNITARGET): $(OBJDIR) $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS) $(UNIFLAGS)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	$(CC) -c $< -o $@ $(CFLAGS) $(INC)

$(OBJDIR)/%.o: $(UNITDIR)/%.c $(HEADERS)
	$(CC) -c $< -o $@ $(CFLAGS) $(INC)
