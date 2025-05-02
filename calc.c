#include <stdio.h>

int main() {
  
  int varX;
  int varY;
  int result;
  char OPt;
  printf("Creating a CLI calculator\n");

  printf("Please start by typing a simple calcul: ");

  scanf("%d", &varX);

  printf("Please type an operator:  ");

  scanf("%s", &OPt);

  printf("Please type the next number");

  scanf("%d", &varY);
  
  switch (OPt) {
    case '*':
      result = varX * varY;
      printf("%d", result);
      break;

    case '+':
      result = varX + varY;
      printf("%d", result);
      break;

    case '-':
      result = varX - varY;
      printf("%d", result);
      break;
    
    case '/': 
      result = varX / varY;
      printf("%d", result);
      break;
  }


  return 0;

}
