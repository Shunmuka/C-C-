#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int four_kind = 0;
int full_house = 0;
int trips = 0;
int two_pair = 0;
int one_pair = 0;
int ace_high = 0;

typedef struct card {
  int pip;
} card;


void merge(int a[], int l, int m, int r){
  int left_length = m - l + 1;
  int right_length = r - m;

  int temp_left[left_length];
  int temp_right[right_length];
  
  for (int i = 0; i < left_length; i++){
    temp_left[i] = a[l + i];
  }

  for (int i = 0; i < right_length; i++){
    temp_right[i] = a[m + 1 + i];
  }

  for (int i = 0, j = 0, k = l; k <= r; k++){
    if ((i < left_length) && (j >= right_length || temp_left[i] <= temp_right[j]))
      a[k] = temp_left[i++];
    else 
      a[k] = temp_right[j++];
  }
}

void merge_sort(int a[], int l, int r){
  if (l < r){
    int m = (l + r) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);

    merge(a, l, m, r);
  }
}

void shuffle_deck(int deck[]){
  for (int i = 51; i > 0; i --){
    int j = rand() % (i + 1); 
    int temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
}

card* random_hand (card hand[]){
  static int deck[52];
  int initialized = 0;

  if (!initialized){
    for (int i = 0; i < 52; i++){
      deck[i] = i;
    }
    initialized = 1;
  }
  
  shuffle_deck(deck);

  for (int i = 0; i < 7; i++){
    hand[i].pip = deck[i] % 13;
  }

  return hand;
}


void total_hands (const card hand[]){

  int count [13] = {0};

  for (int i = 0; i < 7; i++){
      count[hand[i].pip]++;
  }

  merge_sort(count, 0, 12);

  if (count[12] == 4)
      four_kind++;
  else if (count[12] == 3 && count[11] >= 2)
      full_house++;
  else if (count[12] == 3)
      trips++;
  else if (count[12] == 2 && count[11] == 2)
      two_pair++;
  else if (count[12] == 2)
      one_pair++;
  else
      ace_high++;
}


int main(void)
{
  
  card hand [7];
  srand(time(NULL));
  
  for (int i = 0; i < 1000000; i++){
      random_hand(hand);
      total_hands(hand);
  }

  printf("Probability of Four of a Kind is %lf\n", four_kind / 1000000.0);
  printf("Probability of Full House is %lf\n", full_house / 1000000.0);
  printf("Probability of Three of a Kind is %lf\n", trips / 1000000.0);
  printf("Probability of Two Pair is %lf\n", two_pair / 1000000.0);
  printf("Probability of One Pair is %lf\n", one_pair / 1000000.0);
  printf("Probability of No Pair is %lf\n", ace_high / 1000000.0);

  return 0;
}

