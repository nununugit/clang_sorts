
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 100000
int main (){
    int test[NUM];
    int tmp,count;
    int i , j , s , t ;
 
 
 clock_t start,end;
  /* 0 〜 10000 の乱数を生成・出力 */
  srand((unsigned int)time(NULL)); // 現在時刻の情報で初期化
  for(i=0;i<NUM;i++){
    test[i]=(rand()%NUM)+1;
  }
  /* 乱数の作成
  end=clock();
  printf("%.2f秒かかりました\n",(double)(end-start)/CLOCKS_PER_SEC);
  */

  start = clock();
    for(s=0 ; s<NUM-1 ; s++){
        for(t=s+1;t<NUM;t++){
            if(test[t]>test[s]){
                tmp = test[t];
                test[t] = test[s];
                test[s] = tmp;
            }
        }
    }
  end = clock();
    
    for(j=0 ; j<NUM ; j++){
        printf("%d th is %d \n", j+1 , test[j]);
    }

  printf("%.2f秒かかりました\n",(double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}