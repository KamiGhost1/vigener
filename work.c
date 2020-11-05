#include "main.h"

void testParam(int C, char **V){
  if(C==1){
    printf("hello. its program for Vigener Encode/Decode\nuse -h for help\n\ncreated kamighost1\n\nEnjoy\n");
    exit(0);
  }
  if(C==2){
    if(!strcmp(V[1],"-h")){
      printf("\n\tEncryption:\n\n$ ./exec -e <input file> -o <output file> -k <key>\n");
      printf("\n\tDecryption:\n\n$ ./exec -d <input file> -o <output file> -k <key>\n");
      exit(0);
    }
  }
  if(C==7){
      if(!strcmp(V[1],"-e") && !strcmp(V[3],"-o") && !strcmp(V[5],"-k")){
          char *log;
          log = encrypt(V[2],V[4],V[6]);
          printf("result: %s\n",log);
          exit(0);
      }
      if(!strcmp(V[1],"-d") && !strcmp(V[3],"-o") && !strcmp(V[5],"-k")){
          char *log;
          log = decrypt(V[2],V[4],V[6]);
          printf("result: %s\n",log);
          exit(0);
      }
  }
  printf("use `-h`\n");
  exit(0);
}
char *encrypt(char *in, char *out, char *key){
    FILE *i, *o;
    i = fopen(in,"r");
    char *test;
    int inC,outC,kC;
    int j =0;
    if(!i){
        printf("File input not found\n");
        exit(1);
    }
    if(!key){
        printf("key not found. \nplease enter key -k <key>\n");
        exit(2);
    }
    o = fopen(out,"w");
    test = (char*)malloc(1);
    while ((inC = fgetc(i)) != EOF){
        kC = key[j%strlen(key)];
        outC = inC+kC;
        fputc(outC,o);
        test = (char*)realloc(test,sizeof(char)*(j+1));
        test[j]=outC;
        j++;
    }
    fclose(i);
    fclose(o);
    printf("its end\n");
    return test;
}
char *decrypt(char *in, char *out, char *key){
    FILE *i, *o;
    i = fopen(in,"r");
    char *test;
    int inC,outC,kC;
    int j =0;
    if(!i){
        printf("File input not found\n");
        exit(1);
    }
    if(!key){
        printf("key not found. \nplease enter key -k <key>\n");
        exit(2);
    }
    o = fopen(out,"w");
    test = (char*)malloc(1);
    while (EOF != (inC = fgetc(i))){
        kC = key[j%strlen(key)];
        outC = inC-kC;
        fputc(outC,o);
        test = (char*)realloc(test,sizeof(char)*(j+1));
        test[j]=outC;
        j++;
    }
    fclose(i);
    fclose(o);
    return test;
}
