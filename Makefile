CFLAGS = -Wall

main: src/6502.c src/memory.c src/main.c
	$(CC) $(CFLAGS) $? -o ${@}.o

clean:
	-rm *.o 
