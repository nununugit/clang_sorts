
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 100000
int main{

int i,test;     //要らない
clock_t start,end;
  
  /* 0 〜 10000 の乱数を生成・出力 */
  srand((unsigned int)time(NULL)); // 現在時刻の情報で初期化
  for(i=0;i<NUM;i++){
    test[i]=(rand()%NUM)+1;
  }

  start = clock();
    //処理を入れる
  end = clock();

    //処理後
  printf("%.2f秒かかりました\n",(double)(end-start)/CLOCKS_PER_SEC);

  return 0 ;
}