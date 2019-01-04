// This software is copyright (c) 1996-2015 by
//      John Tromp
//      600 Route 25A
//      East Setauket
//      NY 11733
// E-mail: john.tromp@gmail.com
//
// This notice must not be removed.
// This software must not be sold for profit.
// You may redistribute if your distributees have the
// same rights and restrictions.

#include "Window.h"

int main(int argc, const char *argv[]) {
  printf("Input your position!\n");
  assert(SIZE1 <= 8*sizeof(bitboard));
  assert(TRANSIZE >= ((bitboard)1 << (SIZE1-LOCKSIZE))*31/32);
  char bookfile[64];
  sprintf(bookfile, "book%d%d%d", HEIGHT, HEIGHT, HEIGHT);
  Window wins(argc > 1 ? argv[1] : bookfile);
  bool ok = true;
  wins.reset();
  wins.refresh();
  int c;
  // Now using hexadecimal notation for column to put in
  while ((c = getchar()) != EOF && c != 'q') {
    switch (c) {
      case '0' : case '1' : case '2' : case '3' : case '4' : case '5' : case '6' : case '7' : case '8' : case '9' :
          ok = wins.play(c - '0');
          break;
      case 'a' : case 'b' : case 'c' : case 'd' : case 'e' : case 'f' :
          ok = wins.play(c - 'a' + 10);
          break;
      case '\n':
          wins.printBoard();
          ok = wins.solve();
          wins.reset();
		  break;
    }
    if (!ok) {
        //putchar('\7');
        ok = true;
    }
  }
  printf("Be seeing you...\n");
  return 0;
}
