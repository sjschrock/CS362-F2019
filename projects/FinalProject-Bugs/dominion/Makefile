CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

unittestresults: dominion.o

	echo "RESULTS OF ALL UNIT TESTS:" > unittestresults.out
	echo "***********************************************" >> unittestresults.out

	echo "Result for running Unit 5 tests, unittest5.c:" >> unittestresults.out
	gcc -o unittest5 -g unittest5.c dominion.o rngs.o $(CFLAGS)
	./unittest5 >> unittestresults.out


	echo "Result for running Unit 6 tests, unittest6.c:" >> unittestresults.out
	gcc -o unittest6 -g unittest6.c dominion.o rngs.o $(CFLAGS)
	./unittest6 >> unittestresults.out

	echo "Result for running Unit 7 tests, unittest7.c:" >> unittestresults.out
	gcc -o unittest7 -g unittest7.c dominion.o rngs.o $(CFLAGS)
	./unittest7 >> unittestresults.out

	echo "Result for running Unit 8 tests, unittest8.c:" >> unittestresults.out
	gcc -o unittest8 -g unittest8.c dominion.o rngs.o $(CFLAGS)
	./unittest8 >> unittestresults.out

	echo "Result for running Unit 9 tests, unittest9.c:" >> unittestresults.out
	gcc -o unittest9 -g unittest9.c dominion.o rngs.o $(CFLAGS)
	./unittest9 >> unittestresults.out
	
	gcov dominion.c -f -b >> unittestresults.out

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe 
	rm -rf *.dSYM
	rm -f unittest5 unittest6 unittest7 unittest8 unittest9
