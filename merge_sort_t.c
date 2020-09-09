#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 60000

/* マージソート */
void merge_sort (int array[], int left, int right) {
    int i, j, k, mid;
    int work[NUM]; // 作業用配列
    if (left < right) {
        mid = (left + right)/2; // 真ん中
        merge_sort(array, left, mid); // 左を整列
        merge_sort(array, mid+1, right); // 右を整列
        for (i = mid; i >= left; i--) { work[i] = array[i]; } // 左半分
        for (j = mid+1; j <= right; j++) {
        work[right-(j-(mid+1))] = array[j]; // 右半分を逆順
    }
        i = left;
        j = right;

        for (k = left; k <= right; k++) {
        if (work[i] < work[j]) { array[k] = work[i++]; }
        else { array[k] = work[j--]; }
        }
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
    merge_sort(array, 0,NUM);
 end = clock();
    printf("After sort: ");
    for (i = 0; i < NUM; i++) { printf("%d ", array[i]); }
    printf("\n");

  printf("%.2f秒かかりました\n",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}