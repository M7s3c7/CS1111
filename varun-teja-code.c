#include <stdio.h>


char str[27];
int num;

void sort_char_arr(int *n, char arr[]) {
  for (int i = 0; i < *n; i++) {
    for (int j = 0; j < (*n - 1); j++) {
      if (arr[j] > arr[j + 1]) {
        char tmp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = tmp;
      }
    }
  }
}

void print_all_string_len_k(int p, int k, int num, char brr[]) {
  int i;
  if (p == k) {
    for (int j = 0; j < p; j++) {
      printf("%c", brr[j]);
    }
    printf("\n");
    
    return;
  }

  for (i = 0; i < num; i++) {
    brr[p] = str[i];
    print_all_string_len_k(p + 1, k, num, brr);
  }
}

int main() {
  int k, num;
  char brr[27];
  scanf("%d\n", &num);


  for (int i = 0; i < num; i++) {
    scanf("%c\n", &str[i]);
  }

  scanf("%d", &k);

  sort_char_arr(&num, str);

  print_all_string_len_k(0, k, num, brr);
  return 0;
}