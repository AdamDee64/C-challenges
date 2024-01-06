/*
A function that when given a perfect square, will return the next highest 
perfect square.
A perfect square is a square of an integer.
exampled 4*4 = 16. The next perfect square would be 25

if a non-perfect square is entered, returns -1
*/

long int findNextSquare(long int sq)
{
  long int try = 1;
  while(try * try < sq){
    if (sq / try == try && sq % try == 0) break;
    try++;
  }
  if (sq / try == try) return (try + 1 ) * (try + 1 ) ;
  return -1;
}