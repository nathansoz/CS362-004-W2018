CFLAGS = -Wall -fpic -coverage -lm

CARDS = smithy.o adventurer.o council_room.o gardens.o village.o

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

smithy.o: cards/smithy.c
	gcc -c cards/smithy.c -g  $(CFLAGS)

adventurer.o: cards/adventurer.c
	gcc -c cards/adventurer.c -g  $(CFLAGS)

gardens.o: cards/gardens.c
	gcc -c cards/gardens.c -g  $(CFLAGS)

village.o: cards/village.c
	gcc -c cards/village.c -g  $(CFLAGS)

council_room.o: cards/council_room.c
	gcc -c cards/council_room.c -g  $(CFLAGS)

cards: $(CARDS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g $(CFLAGS)

playdom: dominion.o playdom.c cards
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CARDS) $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o cards
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CARDS) $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o cards
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CARDS) $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o cards
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CARDS) $(CFLAGS)

unittest1: unittest1.c dominion.o rngs.o cards
	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CARDS) $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o cards
	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CARDS) $(CFLAGS)

testAll: dominion.o testSuite.c cards
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CARDS) $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

rununittests: unittest1 unittest2
	./unittest1 > unittestresult.out
	./unittest2 >> unittestresult.out
	gcov dominion.c >> unittestresult.out


player: player.c interface.o cards
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CARDS) $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard badTestDrawCard testDrawCard.exe unittest1 unittest2
