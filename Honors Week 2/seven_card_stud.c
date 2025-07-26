#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PERCENTAGE      100
#define CARDS_IN_A_HAND 7
#define PIPS_IN_A_DECK  13
#define CARDS_IN_A_DECK 52

typedef enum {
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
} Suit;

typedef struct {
    Suit suit;
    short pips;
} Card;

void shuffleDeck(Card *deck, const int size)
{
    for (int i = 0; i < size - 1; i++) {
        int j = i + rand() % (size - i);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void evaluateProbabilities(int numHands)
{
    Card deck[CARDS_IN_A_DECK];

    // Initialize deck
    for (int i = 0; i < CARDS_IN_A_DECK; i++) {
        deck[i].suit = i / PIPS_IN_A_DECK;
        deck[i].pips = i % PIPS_IN_A_DECK + 1;
    }

    int noPairCount = 0, onePairCount = 0, twoPairCount = 0;
    int threeOfAKindCount = 0, fullHouseCount = 0, fourOfAKindCount = 0;

    for (int i = 0; i < numHands; i++) {
        shuffleDeck(deck, CARDS_IN_A_DECK);

        int counts[PIPS_IN_A_DECK] = {0};
        int pairCount = 0, threeCount = 0, fourCount = 0;

        for (int j = 0; j < CARDS_IN_A_HAND; j++) {
            counts[deck[j].pips - 1]++;
        }

        for (int j = 0; j < PIPS_IN_A_DECK; j++) {
            if (counts[j] == 2) pairCount++;
            else if (counts[j] == 3) threeCount++;
            else if (counts[j] == 4) fourCount++;
        }

        if (fourCount >= 1)
            fourOfAKindCount++;
        else if (threeCount >= 1) {
            if (pairCount == 0)
                threeOfAKindCount++;
            else
                fullHouseCount++;
        }
        else if (pairCount >= 2)
            twoPairCount++;
        else if (pairCount == 1)
            onePairCount++;
        else
            noPairCount++;
    }

    printf("\nOut of %d 7-card hands drawn from the top of a shuffled deck,\n", numHands);
    printf("these are the percentages of different hands observed:\n\n");
    printf("Percentage of No Pair: %.6f%%\n", (float)noPairCount / numHands * PERCENTAGE);
    printf("Percentage of One Pair: %.6f%%\n", (float)onePairCount / numHands * PERCENTAGE);
    printf("Percentage of Two Pair: %.6f%%\n", (float)twoPairCount / numHands * PERCENTAGE);
    printf("Percentage of Three of a Kind: %.6f%%\n", (float)threeOfAKindCount / numHands * PERCENTAGE);
    printf("Percentage of Full House: %.6f%%\n", (float)fullHouseCount / numHands * PERCENTAGE);
    printf("Percentage Four of a Kind: %.6f%%\n\n", (float)fourOfAKindCount / numHands * PERCENTAGE);
}

int main(void)
{
    srand(time(NULL));
    int numHands = 1000000;
    evaluateProbabilities(numHands);
    return 0;
}
