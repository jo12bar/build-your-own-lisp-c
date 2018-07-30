BIN = lispy
BUILD_DIR = build

hello_world_src = hello_world.c
hello_world_obj = $(hello_world_src:%.c=$(BUILD_DIR)/%.o)

ch3_bonus_marks_src = ch3_bonus_marks.c
ch3_bonus_marks_obj = $(ch3_bonus_marks_src:%.c=$(BUILD_DIR)/%.o)

_ignored_sources = $(hello_world_src) $(ch3_bonus_marks_src)
src = $(filter-out $(_ignored_sources), $(wildcard *.c)) mpc/mpc.c
obj = $(src:%.c=$(BUILD_DIR)/%.o)
dep = $(obj:.o=.d) # one dependency file for each source, for dependency tracking.

CFLAGS = -std=c11 -Wall
LDFLAGS = -ledit -lm

all: $(BIN) hello_world ch3_bonus_marks

$(obj): $(BUILD_DIR)/%.o: %.c
	@mkdir -p $(BUILD_DIR) $(BUILD_DIR)/mpc
	$(CC) $(CFLAGS) -o $@ -c $<

$(BIN): $(obj)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(hello_world_obj): $(BUILD_DIR)/%.o: %.c
	@mkdir -p $(BUILD_DIR) $(BUILD_DIR)/mpc
	$(CC) $(CFLAGS) -o $@ -c $<

hello_world: $(hello_world_obj)
	$(CC) -o $@ $^

$(ch3_bonus_marks_obj): $(BUILD_DIR)/%.o: %.c
	@mkdir -p $(BUILD_DIR) $(BUILD_DIR)/mpc
	$(CC) $(CFLAGS) -o $@ -c $<

ch3_bonus_marks: $(ch3_bonus_marks_obj)
	$(CC) -o $@ $^

# Include all dep files in the Makefile
-include $(dep)

# Rule to generate a dep file by using the C preprocessor
# (see `man cpp` for details on the -MM and -MT options).
$(BUILD_DIR)/%.d: %.c
	@mkdir -p $(BUILD_DIR) $(BUILD_DIR)/mpc
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean
clean:
	rm -rv $(BUILD_DIR) $(BIN) hello_world ch3_bonus_marks

.PHONY: cleandep
cleandep:
	rm -v $(dep)
