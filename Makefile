hello_world_src = hello_world.c
hello_world_obj = $(hello_world_src:.c=.o)

ch3_bonus_marks_src = ch3_bonus_marks.c
ch3_bonus_marks_obj = $(ch3_bonus_marks_src:.c=.o)

hello_world: $(hello_world_src)
	$(CC) -o $@ $^

ch3_bonus_marks: $(ch3_bonus_marks_src)
	$(CC) -o $@ $^

.PHONY: clean
clean:
	rm -v hello_world ch3_bonus_marks
