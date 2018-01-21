CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

smithy.o: cards/smithy.c
	gcc -c cards/smithy.c -g  $(CFLAGS)

cards: smithy.o

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g $(CFLAGS)

playdom: dominion.o playdom.c cards
	gcc -o playdom playdom.c -g dominion.o rngs.o smithy.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o cards
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o smithy.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o cards
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o smithy.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o cards
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o smithy.o $(CFLAGS)

testAll: dominion.o testSuite.c cards
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o smithy.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o cards
	gcc -o player player.c -g  dominion.o rngs.o interface.o smithy.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
