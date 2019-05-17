#include<stdio.h>
#include<stdlib.h>
#define MAXLEN (40)
#define WORDS (10)
char words[WORDS][MAXLEN];
FILE *ferr;
int initialized = 0;
void initialize();
void error(char *s){
  if (ferr){
    fprintf(ferr,"ERROR!%s\n",s);
  }
}
//debug function
void _debug_show_words(){
  initialize();
  for(int i=0;i<WORDS;i++){
    printf("%s\n",words[i]);
  }
}
void initialize(){
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
void welcome(){
  initialize();
  system("clear");
  printf("%s\n",words[0]);
}
