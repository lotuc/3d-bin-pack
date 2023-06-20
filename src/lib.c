#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char getch() { return 'a'; }

char kbhit() { return 0; }

char toupper1(char c) { return c; }

char* itoa (unsigned long long  value,  char str[],  int radix)
{
  char  buf [66];
  char* dest = buf + sizeof(buf);
  char  sign = 0;

  if (value == 0) {
    memcpy (str, "0", 2);
    return str;
  }

  if (radix < 0) {
    radix = -radix;
    if ( (long long) value < 0) {
      value = -value;
      sign = 1;
    }
  }

  *--dest = '\0';

  switch (radix)
    {
    case 16:
      while (value) {
        * --dest = '0' + (value & 0xF);
        if (*dest > '9') *dest += 'A' - '9' - 1;
        value >>= 4;
      }
      break;
    case 10:
      while (value) {
        *--dest = '0' + (value % 10);
        value /= 10;
      }
      break;

    case 8:
      while (value) {
        *--dest = '0' + (value & 7);
        value >>= 3;
      }
      break;

    case 2:
      while (value) {
        *--dest = '0' + (value & 1);
        value >>= 1;
      }
      break;

    default:            // The slow version, but universal
      while (value) {
        *--dest = '0' + (value % radix);
        if (*dest > '9') *dest += 'A' - '9' - 1;
        value /= radix;
      }
      break;
    }

  if (sign) *--dest = '-';

  memcpy (str, dest, buf +sizeof(buf) - dest);
  return str;
}
