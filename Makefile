CFLAGS = -Wall

main: src/6502.c src/memory.c src/main.c
	$(CC) $(CFLAGS) $? -o $@

clean:
	-rm main
