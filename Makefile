CC=gcc
CCFLAGS=-Wall -Werror -Wextra -pedantic
DEBUG_CCFLAGS=-ggdb -Wall -Werror -Wextra -pedantic
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
TARGET=monty

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(CCFLAGS)

debug: $(OBJECTS)
	$(CC) -o $(TARGET) $^ $(DEBUG_CCFLAGS)

%.o: %.c %.h
	$(CC) $(CCFLAGS) -c $<

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)
