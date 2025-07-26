# Poker Hand Probability Simulation (7-Card Hands)

This program simulates drawing 7-card poker hands from a standard 52-card deck to estimate the probabilities of the following outcomes:

- No pair (Ace-high or less)
- One pair
- Two pair
- Three of a kind
- Full house
- Four of a kind

The results are calculated through a Monte Carlo simulation with a configurable number of hands.

## 🧠 Concepts Used

- Enums and structs to model a deck of cards
- Fisher-Yates shuffle algorithm
- Monte Carlo simulation
- Array-based frequency counting
- Probability estimation

Notes:
This simulation only evaluates pip matches, not full poker hand rankings (no flushes, straights, or full rules).
It treats Ace as high only, with no wildcards or jokers.

## 🛠 How to Compile and Run

```bash
gcc poker_simulation.c -o poker
./poker
