CC = gcc
CFLAGS = -std=gnu99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion
UNIFLAGS = -lcheck -lm #-lsubunit

SRC = $(wildcard *.c)
HEADERS = $(wildcard *.h)

OBJDIR = ../impl_out
OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

UNITARGET = unit_tests.exe

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

$(OBJDIR)/%.o: %.c $(HEADERS)
	$(CC) -c $< -o $@ $(CFLAGS)
