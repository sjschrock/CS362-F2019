CFLAGS= -Wall -fpic -coverage -lm -std=c99

runtest: testme.c
	gcc -o testme -g  testme.c $(CFLAGS)
	./testme &> testresults.out

testcov: 
	gcov -b -f testme.c >> testresults.out
	gcov -b -f testme.c
	cat testme.c.gcov >> testresults.out
	cat testme.c.gcov

clean:
	rm -f testme testresults.out *.o *.gcno *.gcda
