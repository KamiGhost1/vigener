#include "main.h"

void testParam(int C, char **V){
  if(C==1){
    printf("hello. its program for Vigener Encode/Decode\nuse -h for help\n\ncreated kamighost1\n\nEnjoy\n");
    exit(0);
  }
  if(C==2){
    if(!strcmp(V[1],"-h")){
      printf("its help\n");
    }
  }

}
