#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 60000
/* 値を入れ替える関数 */
void swap (int *x, int *y) {
  int tmp;    // 値を一時保存する変数

  tmp = *x;
  *x = *y;
  *y = tmp;
}

/***
* pivotを決め、
* 全データをpivotを境目に振り分け、
* pivotの添え字を返す
***/
int partition (int array[], int left, int right) {
  int i, j, pivot;
  i = left;
  j = right + 1;
  pivot = left;   // 先頭要素をpivotとする

  do {
    do { i++; } while (array[i] < array[pivot]);
    do { j--; } while (array[pivot] < array[j]);
    // pivotより小さいものを左へ、大きいものを右へ
    if (i < j) { swap(&array[i], &array[j]); }
  } while (i < j);

  swap(&array[pivot], &array[j]);   //pivotを更新

  return j;
}

/* クイックソート */
void quick_sort (int array[], int left, int right) {
  int pivot;

  if (left < right) {
    pivot = partition(array, left, right);
    quick_sort(array, left, pivot-1);   // pivotを境に再帰的にクイックソート
    quick_sort(array, pivot+1, right);
  }
}

int main (void) {
  int array[NUM];
  int i;

clock_t start,end;
  
  /* 0 〜 10000 の乱数を生成・出力 */
  srand((unsigned int)time(NULL)); // 現在時刻の情報で初期化
  for(i=0;i<NUM;i++){
    array[i]=(rand()%NUM)+1;
  }

  start = clock();

  quick_sort(array, 0, NUM);

 end = clock();

  printf("After sort: ");
    for (i = 0; i < NUM; i++) {
    printf("%d ", array[i]); 
    }
  printf("\n");
    //処理後
  printf("%.2f秒かかりました\n",(double)(end-start)/CLOCKS_PER_SEC);


  return 0;
}