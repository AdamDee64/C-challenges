#include <stdio.h>

/*
function takes in 3 values
h = the starting height of a bouncing ball in floors of a building
bounce = how much bounce the ball will have as a percentage (0-1.0) 
window = the height of the window that the ball will pass over as it bounces and drops.
function returns how many times it will pass the window (drops and bounces)

the function will return -1 if the ball never passes the window ( h < window)
or if the ball passes infinite times (1.0 bounce or negative bounce)
*/

int bouncingBall(double h, double bounce, double window) {
    if(h <= window || bounce >= 1.0 || bounce < 0) return -1;
    int output = 0;
    double height = h;

    while(height > window) {
      output += 1;
      height *= bounce;
      if (height > window) output += 1;
    }

    return output;
}


void main() {

    printf("%d\n", bouncingBall(3, 0.66, 1.5)); // 3 

}