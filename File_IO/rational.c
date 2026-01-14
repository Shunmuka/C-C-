#include <stdio.h>
#include <stdlib.h>


typedef struct rational{
  long int num;
  long int denom;
} rational;

rational add(rational a, rational b){
  
  return {(a.num * b.denom + b.num * a.denom), (a.denom * b.denom)};
}

rational subtract(rational a, rational b){
  return {(a.num * b.denom - b.num * a.denom), (a.denom * b.denom)};
}

rational multiply(rational a, rational b){
  return {(a.num * b.num), (a.denom * b.denom)};
}

rational divide(rational a, rational b){
  return {(a.num * b.denom), (a.denom * b.num)};
}

void file_to_array(FILE* fptr, rational rationals[]){
  int count = 0;

  while((fscanf(fptr, "%ld %ld", &rationals[count].num, &rationals[count].denom)) == 2){
    count++;
  }
}

rational average(rational arr[], int size){
  rational sum = {0, 1};
  for (int i = 0; i < size; i++){
    sum = add(sum, arr[i]); 

  }
  sum = divide(sum, {size, 1});
  return sum;
}

int main(int argc, char *argv[]){
  FILE *ifp;
  int size;
  
  if (argc != 2){
    fprintf(stderr, "Please input executable file along with the input file");
    exit(1);
  }

  ifp = fopen(argv[1], "r");
  fscanf(ifp, "%d", &size);
  rational rationals[size];

  file_to_array(ifp, rationals);

  printf("\nThe items in the file are: \n\n");
  for (int i = 0; i < size; i++){
    printf("%ld/%ld\n", rationals[i].num, rationals[i].denom);
  }


  rational avg = average(rationals, size);

  printf("\nThe average of the rational numbers in the file is: %ld/%ld\n", avg.num, avg.denom);

  fclose(ifp);

  return 0;

}

