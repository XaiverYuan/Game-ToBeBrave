#include<stdio.h>
#include<stdlib.h>
#include"player.h"
#define MAXLEN (40)
#define WORDS (14)
char words[WORDS][MAXLEN];
FILE *ferr;
int initialized = 0;
void graph_initialize();
void error(char *s){
  if (ferr){
    fprintf(ferr,"ERROR!%s\n",s);
  }
}
//debug function
void _debug_show_words(){
  graph_initialize();
  for(int i=0;i<WORDS;i++){
    printf("%s\n",words[i]);
  }
}
void graph_initialize(){
  if (initialized) return;
  ferr = fopen("error.sys","a");
  if (!ferr) {
    printf("ERROR!");
    fflush(stdout);
  }
  FILE *fp = fopen("language/Chinese","r");
  if (!fp){
    printf("ERROR in open language file!");
    fflush(stdout);
  }
  for(int i=0;i<WORDS;i++){
    int temp = fscanf(fp,"%[^\n]\n\n",words[i]);
    if (temp!=1){
      error("error in scan in language file");
    }
  }
  initialized = 1;
}
void print(int i){
  graph_initialize();
  system("clear");
  printf("%s\n",words[i]);
  fflush(stdout);
}
void welcome(){
  print(0);
}
void win(){
  print(1);
}
void lose(){
  print(2);
}
void print_player_doing(player p){
  printf("%s%s\n",p.name,words[10+p.doing]);
}
int ask(player p1, player p2){
  graph_initialize();
  system("clear");
  printf("%s\n",words[3]);
  printf("%4d%4d\n",p1.energy,p2.energy);
  print_player_doing(p1);
  print_player_doing(p2);
  printf("%s\n",words[5]);
  int out;
  scanf("%d",&out);
  return out;
}

