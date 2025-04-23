#include <stdio.h>

int main() {
  int opt;
  char test[10];

  printf("Type 1 to procede\n");
  scanf("%d", &opt);

  if (opt == 1) {
    printf("You choosed to proceed!");
  }
  else { 
    printf("Invalid input!\n");
  }

  printf("Please input something, I'm a test..."); //If user prints more then 9 characters = buffer overflow
  scanf("%s", &test);
  printf("You typed: %s\n", test);


  return 0;

}
