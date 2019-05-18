#include<stdio.h>
#include"graph.h"
int main(){
  welcome();
  getchar();
  player *p1=new_player();
  player *p2=new_player();
  p1->doing=ask(*p1,*p2);
  win();
}
