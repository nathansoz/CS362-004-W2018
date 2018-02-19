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

unittest3: unittest3.c dominion.o rngs.o cards
	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CARDS) $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o cards
	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CARDS) $(CFLAGS)

cardtest1: cardtest1.c dominion.o rngs.o cards
	gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CARDS) $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o cards
	gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CARDS) $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o cards
	gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CARDS) $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o cards
	gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CARDS) $(CFLAGS)

rtu: randomTestingUtilities.c dominion.o rngs.o cards
	gcc -c randomTestingUtilities.c -g $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o cards rtu
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o randomTestingUtilities.o $(CARDS) $(CFLAGS)

randomtestcard1: randomtestcard1.c dominion.o rngs.o cards rtu
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o randomTestingUtilities.o $(CARDS) $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o cards rtu
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o randomTestingUtilities.o $(CARDS) $(CFLAGS)

testAll: dominion.o testSuite.c cards
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CARDS) $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

rununittests: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	./unittest1 > unittestresult.out
	./unittest2 >> unittestresult.out
	./unittest3 >> unittestresult.out
	./unittest4 >> unittestresult.out
	./cardtest1 >> unittestresult.out
	./cardtest2 >> unittestresult.out
	./cardtest3 >> unittestresult.out
	./cardtest4 >> unittestresult.out
	gcov dominion.c >> unittestresult.out

runrandomtests: randomtestadventurer randomtestcard1 randomtestcard2
	./randomtestadventurer > randomtestadventurer.out
	gcov adventurer.c >> randomtestadventurer.out
	cat adventurer.c.gcov >> randomtestadventurer.out
	./randomtestcard1 > randomtestcard1.out
	gcov village.c >> randomtestcard1.out
	cat village.c.gcov >> randomtestcard1.out
	./randomtestcard2 > randomtestcard2.out
	gcov gardens.c >> randomtestcard2.out
	cat gardens.c.gcov >> randomtestcard2.out

player: player.c interface.o cards
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CARDS) $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard badTestDrawCard testDrawCard.exe unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer randomtestcard1 randomtestcard2
