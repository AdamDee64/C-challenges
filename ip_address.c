#include <inttypes.h>
#include <stdio.h>

/*
a function that takes in two IP addresses, a start and an end.
returns the total number of unique IP addresses that exist between the two addresses
*/

uint32_t ips_between (const char *start, const char *end)
{
  uint32_t a = 0;
  uint32_t b = 0;

  uint32_t value = 0;

  while(*start) {
    if(*start >= 48 && *start <= 57) {
      value *= 10;
      value += *start - 48;
    } else {
      a += value;
      a *= 256;
      value = 0;
    }
    start += 1;
  }
  a += value;
  value = 0;

  while(*end) {
    if(*end >= 48 && *end <= 57) {
      value *= 10;
      value += *end - 48;
    } else {
      b += value;
      b *= 256;
      value = 0;
    }
    end += 1;
  }
  b += value;

  return b - a;

}

// alternate solution
uint32_t ips_between2 (const char *start, const char *end)
{
  uint32_t a,b,c,d;
  uint32_t s = 0;
  uint32_t e = 0;
  sscanf(start, "%d.%d.%d.%d", &a, &b, &c, &d);
  s = a << 24 | b << 16 | c << 8 | d;
  sscanf(end, "%d.%d.%d.%d", &a, &b, &c, &d);
  e = a << 24 | b << 16 | c << 8 | d;
  return e-s;
}



void main() {

  ips_between("20.0.0.10", "20.0.1.0");


}