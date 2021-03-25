#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int FuzzMe(char *Data, long DataSize) {
  if(DataSize > 3 && Data[0] == 'F' && Data[1] == 'U' && Data[2] == 'Z' && Data[3] == 'Z')
      return 1; // :-<
  return 0;
}

int main(int argc,char* argv[]){
   FILE *fp=fopen(argv[1],"r");  //Read a file given by the user
   fseek(fp, 0, SEEK_END);
   long fsize = ftell(fp);
   fseek(fp, 0, SEEK_SET);
   
   char *data = malloc(fsize+1);
   fread(data, 1, fsize, fp);
   fclose(fp);
   int status = FuzzMe(data,fsize);
   
   if(status) abort(); // Catch the predefined code.
   printf("Success!");
   return 0;
}
