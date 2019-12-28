test: v2p.c test.c
	$(CC) $^ -o $@

clean:
	rm -f *.o test
