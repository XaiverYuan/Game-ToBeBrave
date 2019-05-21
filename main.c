#include<stdio.h>
#include"graph.h"
#include"ai.c"
int main(){
  welcome();
  getchar();
  player *p1=new_player();
  player *p2=new_player();
  int end=0;
  while(!end){
    p1->doing=ask(*p1,*p2);
    p2->doing=ai_doing(p1->energy,p2->energy);
    energy_update(p1);
    energy_update(p2);
    end=twoplayers(*p1,*p2);
  }
  print_player_doing(*p1);
  print_player_doing(*p2);
  getchar();
  endgame(end);
}

