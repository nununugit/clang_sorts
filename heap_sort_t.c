#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 60000

/* 値を入れ替える関数 */
void swap (int *x, int *y) {
  int temp;    // 値を一時保存する変数

  temp = *x;
  *x = *y;
  *y = temp;
}

/* pushdouwn操作 */
void down_heap (int array[], int first, int last) {
  int parent = first;   // 親
  int child = 2*parent;   // 左の子
  while (child <= last) {
    if ((child < last) && (array[child] < array[child+1])) {
       child++;   // 右の子の方が大きいとき、右の子を比較対象に設定
    }
    if (array[child] <= array[parent]) { break; }   // ヒープ済み
    swap(&array[child], &array[parent]);
    parent = child;
    child = 2* parent;
  }
}

/* ヒープソート */
void heap_sort (int array[], int array_size) {
  int i;

  for (i = array_size/2; i >= 1; i--) {
    down_heap(array, i, array_size);   // 全体をヒープ化
  }
  for (i = array_size; i >= 2; i--) {
    swap(&array[1], &array[i]);   // 最大のものを最後に
    down_heap(array, 1, i-1);   // ヒープ再構築
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

  heap_sort(array, 10);
end = clock();

  printf("After sort: ");
  for (i = NUM; i >1 ; i--) { printf("%d ", array[i]); }
  printf("\n");

    //処理後
  printf("%.2f秒かかりました\n",(double)(end-start)/CLOCKS_PER_SEC);
  return 0;
}