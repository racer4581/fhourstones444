#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef WIDTH
#define WIDTH 16
#endif
#ifndef HEIGHT
#define HEIGHT 4
#endif

// bitmask corresponds to board as follows in 4x4x4 case:
//  . .  .  .  .  .  .  .  .  .  .  .  .  .  .  . TOP
//  3 8 13 18 23 28 33 38 43 48 53 58 63 68 73 78
//  2 7 12 17 22 27 32 37 42 47 52 57 62 67 72 77
//  1 6 11 16 21 26 31 36 41 46 51 56 61 66 71 76
//  0 5 10 15 20 25 30 35 40 45 50 55 60 65 70 75 BOTTOM
//  '___1___' '____2____' '____3____' '____4____' LAYERS (Front to Back)
#define HEIGHT1 (HEIGHT+1)
#define HEIGHT2 (HEIGHT+2)
#define SIZE (HEIGHT*WIDTH)
#define SIZE1 (HEIGHT1*WIDTH)

#if (SIZE1<=64)
typedef uint64_t bitboard;
#else
typedef __int128_t bitboard;
#endif

#define COL1 (((bitboard)1<<HEIGHT1)-(bitboard)1)
#if SIZE1 == 64
#define ALL1 (~(bitboard)0)
#else
#define ALL1 (((bitboard)1<<SIZE1)-(bitboard)1)
#endif
#define BOTTOM (ALL1 / COL1) // has bits i*HEIGHT1 set
#define TOP (BOTTOM << HEIGHT)
#define ALL (ALL1 & ~TOP)
#define ALTCOL ((COL1>>1)/3)
#define ALTO (ALTCOL * BOTTOM)
#define ALTX (ALTO << 1)

class Game {
public:
  bitboard color[2];  // black and white bitboard
  int moves[SIZE],nplies;
  char hight[WIDTH]; // holds bit index of lowest free square
  
  void reset() {
    nplies = 0;
    color[0] = color[1] = (bitboard)0;
    for (int i=0; i<WIDTH; i++)
      hight[i] = (char)(HEIGHT1*i);
  }

  bitboard positioncode() const {
    return color[nplies&1] + color[0] + color[1] + BOTTOM;
    // color[0] + color[1] + BOTTOM forms bitmap of hights
    // so that positioncode() is a complete board encoding
    // where player to move has 1s
  }

  void printMoves() {
    for (int i=0; i<nplies; i++)
      printf("%d", 1+moves[i]);
  }

  // return whether newboard lacks overflowing column
  int islegal(bitboard newboard) {
    return (newboard & TOP) == 0;
  }

  // return whether columns col has room
  int isplayable(int col) {
    return col >= 0 && col < WIDTH && islegal(color[nplies&1] | ((bitboard)1 << hight[col]));
  }

  // return number of stones in column col
  int height(int col) {
    return hight[col] % HEIGHT1;
  }

  bitboard haswond(bitboard x1, int dir) {
    bitboard x2 = x1 & (x1>>dir);
    return x2 & (x2 >> 2*dir);
  }

  // return non-zero iff newboard includes a win
  // (bitboard of least significant positions of 4-in-a-rows)
  // TODO: Adapt this to search in 12 directions
  bitboard haswon(bitboard x1) {
    return  haswond(x1,1)
            | haswond(x1,HEIGHT1)
            | haswond(x1,HEIGHT)
            | haswond(x1,HEIGHT2);
  }

  // return result of 2nd player evens strategy: 0 for drawing; +1 for winning; -1 otherwise
  int xevens() {
    bitboard xe = color[1] | (ALTX & ~(2*color[0]+color[1]+BOTTOM));
    bitboard oe = ALL - xe;
    if (haswond(oe,1))
      return -1;
    bitboard xeh = haswond(xe,HEIGHT1);
    bitboard xed1 = haswond(xe,HEIGHT);
    bitboard xed2 = haswond(xe,HEIGHT2);
    bitboard xeany = xeh|xed1|xed2;
    bitboard oeh = haswond(oe,HEIGHT1);
    bitboard oed1 = haswond(oe,HEIGHT);
    bitboard oed2 = haswond(oe,HEIGHT2);
    if (/* oeh && */ (oeh & (xeany-(TOP+1))))
      return -1;
    if (oed1 && ((oeh|oed1) & ((xeh|xed1)-(TOP+1))))
      return -1;
    if (oed2 && ((oeh|oed2) & ((xeh|xed2)-(TOP+1))))
      return -1;
    return xeany ? 1 : 0;
  }
  
  // return whether newboard is legal and includes a win
  int islegalhaswon(bitboard newboard) {
    return islegal(newboard) && haswon(newboard);
  }

  void backmove() {
    int n = moves[--nplies];
    color[nplies&1] ^= (bitboard)1<<--hight[n];
  }

  void makemove(int n) {
    color[nplies&1] ^= (bitboard)1<<hight[n]++;
    moves[nplies++] = n;
  }
};
