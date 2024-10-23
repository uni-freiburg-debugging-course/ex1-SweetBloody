CC := gcc

CFLAGS := -std=gnu99 -Wall -Werror -pedantic -ggdb -I inc

app.exe : out/main.o
	$(CC) -o $@ $^

out/main.o : main.c
	mkdir -p out
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY : clean
clean :
	rm out/*.o *.exe