#include <stdio.h>

void change(int *x, int y) {

    printf("%d", *x);
    printf("%d\n", y);

    *x = 9;
    printf("%d", *x);
    printf("%d\n", y);

    y = 5;
    printf("%d", *x);
    printf("%d\n", y);

}

int main() { 
  int a = 8;
  int b = 3;
  change(&b, a);
  printf("%d\n", b); //como foi alterado o valor da memoria a variavel b foi alterada
  printf("%d", a); //como foi  alterado o valor da variavel local o valor de a permanece intacto

    return 0;
}