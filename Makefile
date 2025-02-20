# Compiler and options
CC = gcc
CFLAGS = -Wall -g

# Source files
SRCS = main.c system.c
OBJS = $(SRCS:.c=.o)

# Output binary
TARGET = wordlist_generator

# Default target
all: $(TARGET)

# Link object files to create the binary
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Run the program
run: all
	./$(TARGET)

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)
