//
//    FILE: PrintSize_centering.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: demo printSize centering
//     URL: https://github.com/RobTillaart/PrintSize
//
// HISTORY:
// 0.1.0   2020-04-30 initial version
//


#include "PrintSize.h"

char woord[24];
int idx = 0;

PrintSize ps;

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.println(__FILE__);

  Serial.println("Determine length of 10 random numbers and right ");
  Serial.println("align the numbers in a table with their sum.");
  Serial.println();
  ps.reset();
}

void loop()
{
  uint32_t sum = 0;


  Serial.println();
  Serial.println("  Centering");
  for (int i = 0; i < 10; i++)
  {
    // create different order of magnitude random numbers
    uint32_t maxsize = pow(10, 1 + random(9));
    uint32_t rn = random(maxsize);
    int length = ps.println(rn);
    printSpaces((15 - length) / 2);
    sum += rn;
    Serial.println(rn);
  }
  Serial.print("================ +\n");
  int length = ps.println(sum);
  printSpaces((15 - length) / 2);
  Serial.println(sum);
  Serial.println();


  Serial.println();
  Serial.println("  Right Align");
  for (int i = 0; i < 10; i++)
  {
    // create different order of magnitude random numbers
    uint32_t maxsize = pow(10, 1 + random(9));
    uint32_t rn = random(maxsize);
    int length = ps.println(rn);
    printSpaces(15 - length);
    sum += rn;
    Serial.println(rn);
  }
  Serial.print("================ +\n");
  length = ps.println(sum);
  printSpaces(15 - length);
  Serial.println(sum);
  Serial.println();

  delay(1000);
}

void printSpaces(uint8_t n)
{
  while (n--) Serial.print(' ');
}

// -- END OF FILE --