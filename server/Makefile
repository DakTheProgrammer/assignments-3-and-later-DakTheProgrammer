CROSS_COMPILE ?=

CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Wextra -g
TARGET = aesdsocket

all:$(TARGET)

default: $(TARGET)

$(TARGET): aesdsocket.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGET)
	rm -f *.o