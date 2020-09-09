#include<stdio.h>
#include<stdlib.h> 
#include <time.h>
#define NUM 6000000

/* 値を入れ替える関数 */
void swap (int *x, int *y) {
  int tmp;    // 値を一時保存する変数

  tmp = *x;
  *x = *y;
  *y = tmp;
}

/* シェルソート */
void shell_sort (int a[], int a_size) {
  int i, j, h;

  for (h = 1; h <= a_size/9; h = 3*h + 1);   // 間隔hを決める
  for ( ; h > 0; h /= 3) {   // hを狭めていく
    /* 以下、挿入ソートとほぼ同じ */
    for (i = h; i < a_size; i++) {
      j = i;
      while ((j > h - 1) && (a[j-h] > a[j])) {
        swap(&a[j-h], &a[j]);
        j -= h;
      }
    }
  }
}

int main (void) {
  int a[NUM];
  int i;
  int ransu;

 clock_t start,end;
  /* 0 〜 10000 の乱数を生成・出力 */
  srand((unsigned int)time(NULL)); // 現在時刻の情報で初期化
  for(i=0;i<NUM;i++){
    a[i]=(rand()%NUM)+1;
  }
  
  start = clock();

  shell_sort(a, NUM);

  end = clock();

  printf("After sort: ");

  for (i = 0; i < NUM; i++) { printf("%d %d \n",i, a[i]); }
  printf("\n");

  printf("%.2f秒かかりました\n",(double)(end-start)/CLOCKS_PER_SEC);

  return 0;
}