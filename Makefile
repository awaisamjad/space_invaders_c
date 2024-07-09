CC=gcc
CFLAGS=-Iinclude -Wall
LDFLAGS=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Define the source files and the target executable
SRCS=src/main.c src/bullet.c
OBJS=$(SRCS:.c=.o)
TARGET=bin/main

# Default target
all: $(TARGET)

# Rule to create the target executable
$(TARGET): $(OBJS)
→   $(CC) -o $@ $^ $(LDFLAGS)

# Rule to compile source files into object files
%.o: %.c
→   $(CC) -c $(CFLAGS) $< -o $@

# Rule to clean up generated files
clean:
→   rm -f $(OBJS) $(TARGET)

.PHONY: all clean