#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Game logic for a game of snakes and ladders between two players
Players both start on square 0
Players take turn rolling 2 six-sided dice at a time
Player advances based on total sum of the dice
Game ends if a player reaches square 100

Special rules: 
Rolling doubles allows player to take another turn.
A player must make a roll that puts them exactly on square 100 
to win.
If a player makes a roll that takes them beyond square 100,
they must move in reverse for the number beyond 100.
For example, if a player is on square 98:
a roll of 3 will send them back to square 99, 
4 to 98, 10 to 92, etc.
*/

const char *snakes_ladders (int die1, int die2)
{
  static int player_1 = 0;
  static int player_2 = 0;
  static int turn = -1;
  static int current_player = 1;

  if(player_1 == 100 || player_2 == 100) return "Game over!";
  int move = die1 + die2;

  if(current_player == 1) move += player_1;
  else move += player_2;
  if(move > 100) move = 100 - (move - 100);

  switch(move) { 
    case 2:   // ladders
    move = 38;
    break;
    case 7:
    move = 14;
    break;
    case 8:
    move = 31;
    break;
    case 15:
    move = 26;
    break;
    case 21:
    move = 42;
    break;
    case 28:
    move = 84;
    break;
    case 36:
    move = 44;
    break;
    case 51:
    move = 67;
    break;
    case 71:
    move = 91;
    break;
    case 78:
    move = 98;
    break;
    case 87:
    move = 94;
    break;

    case 16:  // snakes
    move = 6;
    break;
    case 46:
    move = 25;
    break;
    case 49:
    move = 11;
    break;
    case 62:
    move = 19;
    break;
    case 64:
    move = 60;
    break;
    case 74:
    move = 53;
    break;
    case 89:
    move = 68;
    break;
    case 92:
    move = 88;
    break;
    case 95:
    move = 75;
    break;
    case 99:
    move = 80;
    break;
  }

  if(current_player == 1) player_1 = move;
  else player_2 = move;

  static char out[64];
  if(move == 100) sprintf(out, "Player %d Wins!", current_player);
  else sprintf(out, "Player %d is on square %d", current_player, move);
  
  if(die1 != die2){
    turn *= -1;
    current_player += turn;
  } 

  return out; 
}

int main() {

  srand(time(NULL));
  int rolls = 30;
  while(rolls--) printf("%s\n", snakes_ladders(rand() % 6 + 1, rand() % 6 + 1));

  return 0;
}