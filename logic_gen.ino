#include "logic_gen.h"

/*
  possible modifiers
  1) AND/OR between two inputs
  2) NOT 2 inputs
  3) NOT output
  NOT_IP 0x3;
  AND/OR 0x4;
  NOT_OP 0x8;
*/

void setup_logic() {
  randomSeq = analogRead(0);
}

void generateSeq() { //iterate to next stage
  randomSeq ^= randomSeq << 7;
  randomSeq ^= randomSeq >> 9;
  randomSeq ^= randomSeq << 8;
}

char displayText[] = "!(!x + !y)";

const char *displayEqn() {
  strcpy(displayText, "!(!x + !y)");
  displayText[5] = '*' + bitRead(randomSeq, 2); // +*
  displayText[0] = ' ' + bitRead(randomSeq, 3); // !output
  if(bitRead(randomSeq, 3)) {
  displayText[1] = '(';// (
  displayText[9] = ')';// )
  } else {
    displayText[1] = ' ';
    displayText[9] = ' ';
  }
  displayText[2] = ' ' + bitRead(randomSeq, 0); // !x
  displayText[7] = ' ' + bitRead(randomSeq, 1); // !y
  return displayText;
}

bool checkAns(bool x, bool y) {
  bool z = 0;
  if(bitRead(randomSeq, 0)) x = !x;
  if(bitRead(randomSeq, 1)) y = !y; /*
  x = x + bitRead(randomSeq, 0);
  y = y + bitRead(randomSeq, 1);
  */
  
  if(bitRead(randomSeq, 2))
    z = (x | y);
  else
    z = (x & y);
  if(bitRead(randomSeq, 3)) z = !z;

  return z;
}