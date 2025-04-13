CC = gcc

CFLAGS = -Wall -Wextra -std=c99



# List of source files

SRCS = main.c tokenizer.c history.c

OBJS = $(SRCS:.c=.o)



# Target executable

TARGET = tokenizer



all: $(TARGET)



$(TARGET): $(OBJS)

    $(CC) $(CFLAGS) -o $(TARGET) $(OBJS)



# Compile each source file into an object file

%.o: %.c

    $(CC) $(CFLAGS) -c $<



# Clean up build files

clean:

    rm -f $(OBJS) $(TARGET)



.PHONY: all clean
