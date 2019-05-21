#include"player.h"
#include<sys/timeb.h>
#include<stdio.h>
int ai_initialized=0;
int data[5][5][8];
void ai_initialize(){
  if(ai_initialized)return;
  FILE *fp=fopen("ai/normal","r");
  if(!fp)error("error in read in ai file");
  int prob[5][5][8];
  for(int i=0;i<5;i++){
    for (int j=0;j<5;j++){
      fscanf(fp,"%*d;%*d;");
      int sum=0;
      for (int k=0;k<8;k++){
        fscanf(fp,"%d,",&prob[i][j][k]);
        sum+=prob[i][j][k];
      }
      data[i][j][0]=prob[i][j][0]*100/sum;
      for(int k=1;k<7;k++){
        data[i][j][k]=prob[i][j][k]*100/sum+data[i][j][k-1];
      }
      data[i][j][7]=100;
      fscanf(fp,"\n");
    }
  }
}
void _debug_print_ai(){
  ai_initialize();
  for (int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      printf("%d,%d:  ",i,j);
      for (int k=0;k<8;k++){
        printf("%3d  ",data[i][j][k]);
      }
      printf("\n");
    }
  }
  fflush(stdout);
}
int ai_doing(int eother, int etarget){
  if (etarget>=4)return 4;
  if (eother>=4)eother=4;
  ai_initialize();
  struct timeb u_t;
  ftime(&u_t);
  int rand=u_t.millitm%100+1;
  for(int i=0;i<8;i++){
    if(data[eother][etarget][i]>rand){
      return i-3;
    }
  }
//  error("AI WRONG!");
  return 0;
}
