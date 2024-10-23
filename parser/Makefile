CC := gcc

CFLAGS := -std=gnu99 -Wall -Werror -pedantic -ggdb -I inc

OBJS_MAIN := out/cdio.o out/file_process.o out/process.o out/struct.o

app.exe : out/main.o $(OBJS_MAIN)
	$(CC) -o $@ $^

out/main.o : src/main.c
	mkdir -p out
	$(CC) $(CFLAGS) -c $^ -o $@

out/cdio.o : src/cdio.c inc
	mkdir -p out
	$(CC) $(CFLAGS) -c src/cdio.c -o $@

out/file_process.o : src/file_process.c inc
	mkdir -p out
	$(CC) $(CFLAGS) -c src/file_process.c -o $@

out/process.o : src/process.c inc
	mkdir -p out
	$(CC) $(CFLAGS) -c src/process.c -o $@

out/struct.o : src/struct.c inc
	mkdir -p out
	$(CC) $(CFLAGS) -c src/struct.c -o $@

.PHONY : clean
clean :
	rm out/*.o *.exe