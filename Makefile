CC = clang
CFLAGS = -O3 -Wall
LIBS = -lm
TARGET = lavascript
PREFIX = /usr/local

all:
 $(CC) $(CFLAGS) src/main.c -o $(TARGET) $(LIBS)

install: all
 install -Dm755 $(TARGET) $(PREFIX)/bin/$(TARGET)

uninstall:
 rm -f $(PREFIX)/bin/$(TARGET)

clean:
 rm -f $(TARGET)


