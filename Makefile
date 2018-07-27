hello_world_src = hello_world.c
hello_world_obj = $(hello_world_src:.c=.o)

hello_world: $(hello_world_src)
	$(CC) -o $@ $^

.PHONY: clean
clean:
	rm -v hello_world
