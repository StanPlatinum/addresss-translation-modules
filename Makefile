filling: v2p.c filling.c
	$(CC) $^ -o $@
scan: v2p.c scan.c
	$(CC) $^ -o $@
test: v2p.c test.c
	$(CC) $^ -o $@

clean:
	rm -f *.o test scan filling
