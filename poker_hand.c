#include <stdio.h>

typedef struct Hand Hand;
typedef enum { Win, Loss, Tie } Result;

Hand* PokerHand (const char *cards) {
  return 0;
}

int translate(char c) {
  return  c == 'S' ? 0 : 
          c == 'H' ? 1 :
          c == 'C' ? 2 :
          c == 'D' ? 3 :
          c == 'A' ? 0 : 
          c == '2' ? 1 : 
          c == '3' ? 2 : 
          c == '4' ? 3 : 
          c == '5' ? 4 : 
          c == '6' ? 5 : 
          c == '7' ? 6 : 
          c == '8' ? 7 : 
          c == '9' ? 8 :
          c == 'T' ? 9 :
          c == 'J' ? 10 :
          c == 'Q' ? 11 : 12;
}

Result compare (char *player, char *opponent) {
  int p_suits[4] = {0};
  int o_suits[4] = {0};

  int p_values[14] = {0};
  int o_values[14] = {0};

  int get_value = 1;
  
  while(*player){
    player += (*player == 32) ? 1 : 0;
    if(get_value > 0) p_values[translate(*player++)]++;
    else p_suits[translate(*player++)]++;
    get_value *= -1;
  }
  while(*opponent){
    opponent += (*opponent == 32) ? 1 : 0;
    if(get_value > 0) o_values[translate(*opponent++)]++;
    else o_suits[translate(*opponent++)]++;
    get_value *= -1;
  }
  p_values[13] = p_values[0];
  o_values[13] = o_values[0];

  int i = 0;
  int p_flush = 0;
  int o_flush = 0;
  while(i < 4){ // check for flush
    if(p_suits[i] == 5) p_flush = 1;
    if(o_suits[i] == 5) o_flush = 1;
    i++;
  }

  i = 0;
  int p_high = 0;
  int o_high = 0;
  while(i < 14){  // get high card in case of tie
    if(p_values[i]) p_high = i;
    if(o_values[i]) o_high = i;
    i++;
  }
  //printf("high cards: p - %d, o - %d\n", p_high, o_high);

  int p_straight = 1;
  int o_straight = 1;
  // check for straight, low/high ace inclusive
  for(i = p_high; i > 0; i--){
    if(p_values[i-1]) p_straight++;
    if(p_straight == 5) break;
    if(!p_values[i-1]) p_straight = 0;
  }
  for(i = o_high; i > 0; i--){
    if(o_values[i-1]) o_straight++;
    if(o_straight == 5) break;
    if(!o_values[i-1]) o_straight = 0;
  }
  //printf("straight: p - %d, o - %d\n", p_straight, o_straight);
  p_straight = (p_straight == 5) ? 1 : 0;
  o_straight = (o_straight == 5) ? 1 : 0;
  p_values[0] = 0;
  o_values[0] = 0;
  
  int p_score = p_straight * p_flush;
  int o_score = o_straight * o_flush;

  if(p_score || o_score){ // score striaght flush
    printf("straight flush found\n");
    if (p_score == o_score){
      p_score += p_high;
      o_score += o_high;
    };
    if (p_score > o_score) return Win;
    if (p_score < o_score) return Loss;
    if (p_score == o_score) return Tie;
  }

  i = 0;
  int p_4kind = 0;
  int o_4kind = 0;
  int p_3kind = 0;
  int o_3kind = 0;
  int p_pair1 = 0;
  int o_pair1 = 0;
  int p_pair2 = 0;
  int o_pair2 = 0;
  while(i < 14) { // check for sets
    switch (p_values[i]){
      case 2:
      if(!p_pair1) p_pair1 = i;
      else p_pair2 = i;
      break;
      case 3:
      p_3kind = i;
      break;
      case 4:
      p_4kind = i;
      break;
    }
    switch (o_values[i]){
      case 2:
      if(!o_pair1) o_pair1 = i;
      else o_pair2 = i;
      break;
      case 3:
      o_3kind = i;
      break;
      case 4:
      o_4kind = i;
      break;
    }    
    i++;
  }
  p_score = p_4kind;
  o_score = o_4kind;
  if(p_score || o_score){ // score 4 of a kind
  printf("4 of a kind found\n");
    if (p_score == o_score){
      p_score += p_high;
      o_score += o_high;
    };
    if (p_score > o_score) return Win;
    if (p_score < o_score) return Loss;
    if (p_score == o_score) return Tie;
  }

  p_score = p_3kind * (p_pair1 + p_pair2);
  o_score = o_3kind * (o_pair1 + o_pair2);
  if(p_score || o_score){ // score full house
    printf("full house found\n");
    if (p_score == o_score){
      if(p_3kind == o_3kind){
        if(p_pair1 + p_pair2 > o_pair1 + o_pair2) return Win;
        if(p_pair1 + p_pair2 > o_pair1 + o_pair2) return Loss;
        if(p_pair1 + p_pair2 == o_pair1 + o_pair2) return Tie;
      } 
      if(p_3kind > o_3kind) return Win;
      if(p_3kind < o_3kind) return Loss;
    };

    if (p_score > o_score) return Win;
    if (p_score < o_score) return Loss;
  }


  p_score = p_flush;
  o_score = o_flush;
  if(p_score || o_score){ // score flush
    printf("flush found\n");
    if (p_score == o_score){
      p_score += p_high;
      o_score += o_high;
    };
    if (p_score > o_score) return Win;
    if (p_score < o_score) return Loss;
    if (p_score == o_score) return Tie;
  }

  p_score = p_straight;
  o_score = o_straight;
  if(p_score || o_score){ // score straight
    printf("straight found\n");
    if (p_score == o_score){
      p_score += p_high;
      o_score += o_high;
    };
    if (p_score > o_score) return Win;
    if (p_score < o_score) return Loss;
    if (p_score == o_score) return Tie;
  }



  p_score = p_3kind;
  o_score = o_3kind;
  if(p_score || o_score){ // score 3 of a kind
    printf("3 of a kind found\n");
    if (p_score == o_score){
      p_score += p_high;
      o_score += o_high;
    };
    if (p_score > o_score) return Win;
    if (p_score < o_score) return Loss;
    if (p_score == o_score) return Tie;
  }

  p_score = p_pair1 * p_pair2;
  o_score = o_pair1 * o_pair2;
  if(p_score || o_score){ // score 2 pair
    printf("2 pair found\n");
    if(p_score == o_score){
      p_score = (p_pair1 > p_pair2) ? p_pair1 : p_pair2;
      o_score = (o_pair1 > o_pair2) ? o_pair1 : o_pair2;
    }
    if(p_score == o_score){
      p_score = (p_pair1 < p_pair2) ? p_pair1 : p_pair2;
      o_score = (o_pair1 < o_pair2) ? o_pair1 : o_pair2;
    }
    if (p_score > o_score) return Win;
    if (p_score < o_score) return Loss;
    if (p_score == o_score) return Tie;
  }

  p_score = p_pair1;
  o_score = o_pair1;
  if(p_score || o_score){ // score 2 of a kind
    printf("2 of a kind found\n");
    if (p_score == o_score){
      p_score += p_high;
      o_score += o_high;
    };
    if (p_score > o_score) return Win;
    if (p_score < o_score) return Loss;
    if (p_score == o_score) return Tie;
  }

  i = 13;
  printf("high card standoff\n");
  while(i >= 0){
    if(p_values[i] > o_values[i]) return Win;
    if(p_values[i] < o_values[i]) return Loss;
    i--;
  }

  return Tie;
}


int main() {

  printf("%d\n", compare("2H 3H 4H 5H 6H", "KS AS TS QS JS"));
  printf("%d\n", compare("2H 3H 4H 5H 6H", "AS AD AC AH JD"));
  printf("%d\n", compare("AS AH 2H AD AC", "JS JD JC JH 3D"));
  printf("%d\n", compare("2S AH 2H AS AC", "JS JD JC JH AD"));
  printf("%d\n", compare("2S AH 2H AS AC", "2H 3H 5H 6H 7H"));
  printf("%d\n", compare("AS 3S 4S 8S 2S", "2H 3H 5H 6H 7H"));
  
  return 0;
}