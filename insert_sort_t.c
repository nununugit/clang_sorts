#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 60000
/* 値を入れ替える関数 */
void swap (int *x, int *y) {
  int tmp; 
  tmp = *x;
  *x = *y;
  *y = tmp;
}

/* 挿入ソート */
void insertion_sort (int array[], int array_size) {
  int i, j;

  for (i = 1; i < array_size; i++) {   // 先頭から順にソート
    j = i;
    while ((j > 0) && (array[j-1] < array[j])) {   //昇順の場合はarrayのところの大小を逆に
      swap(&array[j-1], &array[j]);   // 整列されていない要素を交換
      j--;
    }
  }
}

int main (void) {
  int i;
  
  srand((unsigned int)time(NULL)); // 現在時刻の情報で初期化

  clock_t start,end;
  int array[NUM];

  /* 0 〜 10000 の乱数を生成・出力 */
  for(i=0;i<NUM;i++){
    array[i]=(rand()%NUM)+1;
  }

  start = clock();

  insertion_sort(array, NUM);
  
  end= clock();

  printf("After sort: ");
  for (i = 0; i < NUM; i++) { printf("%d %d \n", i ,array[i]); }

  printf("%.2f秒かかりました\n",(double)(end-start)/CLOCKS_PER_SEC);

  return 0;
}