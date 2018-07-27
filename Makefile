BIN = lispy

hello_world_src = hello_world.c
hello_world_obj = $(hello_world_src:.c=.o)

ch3_bonus_marks_src = ch3_bonus_marks.c
ch3_bonus_marks_obj = $(ch3_bonus_marks_src:.c=.o)

_ignored_sources = $(hello_world_src) $(ch3_bonus_marks_src)
src = $(filter-out $(_ignored_sources), $(wildcard *.c))
obj = $(src:.c=.o)

CFLAGS = -std=c11 -Wall

all: $(BIN) hello_world ch3_bonus_marks

$(BIN): $(obj)
	$(CC) $(CFLAGS) -o $@ $^

hello_world: $(hello_world_obj)
	$(CC) -o $@ $^

ch3_bonus_marks: $(ch3_bonus_marks_obj)
	$(CC) -o $@ $^

.PHONY: clean
clean:
	rm -v $(obj) $(BIN) $(hello_world_obj) hello_world $(ch3_bonus_marks_obj) ch3_bonus_marks
