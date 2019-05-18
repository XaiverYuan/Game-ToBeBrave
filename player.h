#define NAMELEN (10)
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
