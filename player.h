#include<stdlib.h>
#ifndef NAMELEN
#define NAMELEN (10)
extern void error(char*);
typedef struct{
  char name[NAMELEN];
  int energy;
  int doing;
}player;
player * new_player(){
  static int i=1;
  player * p =malloc(sizeof(player));
  p->name[0]='p';
  p->name[1]='0'+i++;
  p->name[2]='\0';
  p->energy=0;
  p->doing=-4;
  return p;
}
void energy_update(player *p){
  if (p->doing==0){
    p->energy++;
    return;
  }
  if (p->doing>0&&p->doing<5){
    p->energy-=p->doing;
    return;
  }
  if (p->doing<0&&p->doing>-3)return;
  if (p->doing==-3){
    p->energy--;
    return;
  }
  error("unknown doing");
}
int check_players(int, int);
int twoplayers(player p1, player p2){
  int p1d=check_players(p2.doing,p1.doing);
  int p2d=check_players(p1.doing,p2.doing);
  if (p1d*p2d)error("error in check 2 player");
  return p2d-p1d;
}
int check_players(int other,int target){
  /*
     0 all good
     1 lower attacking level
     2 attacked while no defense
     3 wrong defense
     4 killed by power
   */
  if (other ==4)
    return 4;
  if (target==0&&other>0){
    return 2;
  }
  if (target>0&&other>0){
    if (target<other)return 1;
  }
  if (target<0&&other>0){
    if (target!=-3){
      if (other+target)return 3;
    }
  }
  return 0;
}
#endif
