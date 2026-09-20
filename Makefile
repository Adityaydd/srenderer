# Compiler and flags
CC       := gcc
CFLAGS   := -Wall -Wextra -O2 -Iinclude
LDFLAGS  := -lSDL3 -lcglm -lm

# Source files, object files, and final output name
SRCS     := src/main.c src/matrices.c src/utils.c
OBJS     := $(SRCS:.c=.o)
TARGET   := app

# Default rule
all: $(TARGET)

# Link the compiled object files into the final executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Rule to compile individual .c files into .o object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Run the program directly
run: $(TARGET)
	./$(TARGET)

# Clean compiled objects and the executable
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all run clean
