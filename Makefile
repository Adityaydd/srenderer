CC       := gcc
CFLAGS   := -Wall -Wextra -O2 -Iinclude -MMD -MP
LDFLAGS  := -lSDL3 -lcglm -lm

# Source files, object files, dependency files, and final output name
SRCS     := src/main.c src/matrices.c src/utils.c
OBJS     := $(SRCS:.c=.o)
DEPS     := $(OBJS:.o=.d)
TARGET   := app

# Default rule
all: $(TARGET)

# Link the compiled object files into the final executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Rule to compile individual .c files into .o object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Include generated dependency rules (ignoring errors if they don't exist yet)
-include $(DEPS)

# Run the program directly
run: $(TARGET)
	./$(TARGET)

# Clean compiled objects, dependency files, and the executable
clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)

.PHONY: all run clean
