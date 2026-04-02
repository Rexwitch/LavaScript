CC = clang
TARGET = lavascript
PREFIX = /usr/local
SRC = src/main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET)

.PHONY: clean
clean:
	$(RM) $(TARGET)

.PHONY: install
install: $(TARGET)
	mkdir -p $(PREFIX)/bin
	install $(TARGET) $(PREFIX)/bin/$(TARGET)

.PHONY: uninstall
uninstall:
	$(RM) $(PREFIX)/bin/$(TARGET)
