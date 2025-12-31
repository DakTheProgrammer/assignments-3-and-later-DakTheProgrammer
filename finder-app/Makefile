# Set to run without cross compiler if one isn't provided
CROSS_COMPILE ?=

C_COMPILER = $(CROSS_COMPILE)gcc
C_FLAGS = -Wall -Wextra

TARGET = writer

SOURCES = writer.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(C_COMPILER) $(C_FLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c
	$(C_COMPILER) $(C_FLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean