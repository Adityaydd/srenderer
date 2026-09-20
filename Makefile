# Compiler and flags
CC      = gcc
CFLAGS  = -Wall -Wextra -O2
LDFLAGS = -lSDL3 -lcglm -lm

# Source files, object files, and final output name
SRCS    = main.c matrices.c utils.c
OBJS    = $(SRCS:.c=.o)
TARGET  = app

# Default rule: runs when you just type 'make'
all: $(TARGET)

# Link the compiled object files into the final executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Rule to compile individual .c files into .o object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Run the program directly with 'make run'
run: $(TARGET)
	./$(TARGET)

# Delete object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# Mark targets that aren't actual files
.PHONY: all run clean
