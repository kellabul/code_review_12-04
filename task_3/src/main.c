#include <stdio.h>
#include <stdlib.h>

typedef struct Human {
  char name[20];
  char surname[20];
  int height;

} Human;

int ReadNumber() {
  int number = 0;
  int result = scanf("%d", &number);
  if (result == 0) {
    printf("n/a");
    exit(1);
  }
  return number;
}

Human ReadInput() {
  Human human;
  scanf("%s", human.name);
  scanf("%s", human.surname);
  human.height = ReadNumber();
  return human;
}

int CheckHeight(Human human, int height) {
  int result = 0;
  if (human.height >= height) {
    printf("%s %s", human.name, human.surname);
    result++;
  }
  return result;
}

int main() {
  int amount = ReadNumber();
  scanf("%d", &amount);
  Human people[amount];
  for (int i = 0; i < amount; ++i) {
    people[i] = ReadInput();
  }
  int required_height = 0;

  scanf("%d", &required_height);
  int amount_of_output = 0;
  int buffer = 0;

  for (int i = 0; i < amount; ++i) {
    amount_of_output += CheckHeight(people[i], required_height);
    if (amount_of_output > buffer && i != amount - 1) {
      printf(",");
      buffer = amount_of_output;
    }
  }

  if (amount_of_output == 0) {
    printf("Nothing");
  }

  return 0;
}