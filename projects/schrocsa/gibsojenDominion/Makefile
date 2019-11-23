CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

kingdom_cards.o: kingdom_cards.h kingdom_cards.c
	gcc -c kingdom_cards.c -g $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o kingdom_cards.o
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

unittestresults: unittest1.c unittest2.c unittest3.c unittest4.c dominion.o rngs.o kingdom_cards.o
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o kingdom_cards.o $(CFLAGS)
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o kingdom_cards.o $(CFLAGS)
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o kingdom_cards.o $(CFLAGS)
	gcc -o unittest4 -g unittest4.c dominion.o rngs.c kingdom_cards.o $(CFLAGS)
	gcc -o unittest5 -g unittest5.c dominion.o rngs.c kingdom_cards.o $(CFLAGS)
	./unittest1 $> unittestresults.out
	./unittest2 $> unittestresults.out
	./unittest3 $> unittestresults.out
	./unittest4 $> unittestresults.out
	./unittest5 $> unittestresults.out
	gcov -b -f kingdom_cards.c >> unittestresults.out
	cat kingdom_cards.c.gcov >> unittestresults.out

randomtestresults: randomtestcard1.c randomtestcard2.c randomtestcard3.c dominion.o rngs.o kingdom_cards.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o kingdom_cards.o $(CFLAGS)
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o kingdom_cards.o $(CFLAGS)
	gcc -o randomtestcard3 -g randomtestcard3.c dominion.o rngs.o kingdom_cards.o $(CFLAGS)
	./randomtestcard1 $> randomtestresults.out
	./randomtestcard2 $> randomtestresults.out
	./randomtestcard3 $> randomtestresults.out
	gcov -b -f kingdom_cards.c >> randomtestresults.out
	cat kingdom_cards.c.gcov >> randomtestresults.out

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe randomtestcard1 randomtestcard2 randomtestcard3 unittest1 unittest2 unittest3 unittest4 unittest5
