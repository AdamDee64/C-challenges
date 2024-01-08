#include <inttypes.h>
#include <stdio.h>

void uint32_to_ip (uint32_t number, char *IPv4)
{
// write to IPv4
  
  
  // 11111111 00000000 00000000 00000000
  *IPv4 = '\0';
  sprintf(IPv4, 
          "%d.%d.%d.%d", 
          number >> 24 & 255,
          number >> 16 & 255,
          number >> 8 & 255,
          number & 255
         );
}

int main() {

  char IPv4[16];
  uint32_t number = 1234;

  uint32_to_ip(number, IPv4);
  printf("%s\n", IPv4);


  return 0;
}