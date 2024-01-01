#include <stdio.h>

/*
A function that takes in a value representing time in seconds and returns a string representing
the total hours, minutes and seconds to a maximum of 359999 seconds or 99:59:59
*/

char* human_readable_time (unsigned seconds, char *time_string)
{
  unsigned hours = 0;
  unsigned mins = 0;
  unsigned secs = 0;

  secs = seconds % 60;

  if (seconds >= 60) mins = seconds / 60 % 60;
  if (seconds >= 3600) hours = seconds / 60 / 60;
  if (seconds > 359999) {
    hours = 99;
    mins = 59;
    secs = 59;
  }

	*time_string = '\0';
  sprintf(time_string, "%.2d:%.2d:%.2d", hours, mins, secs); // write to time_string
  return time_string;
}

void main() {

  char time_string[] = "00:00:00";

  printf("%s\n", human_readable_time(0, &time_string[0]));
  printf("%s\n", human_readable_time(61, &time_string[0]));
  printf("%s\n", human_readable_time(86400, &time_string[0]));
  printf("%s\n", human_readable_time(359999, &time_string[0]));
}