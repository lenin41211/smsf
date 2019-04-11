#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
extern "C"{ 
//                                                                                                                                                                                
// int                                                                                                                                                                            
int int_sqrt(int x) {
  return sqrt(x);
}

//                                                                                                                                                                                
// string                                                                                                                                                                         
char* chars_hello(char* src) {
  return strcat( "Hello ", src );
}


//                                                                                                                                                                                
// pointer                                                                                                                                                                        

typedef struct {
  char* name;
} Hello;

Hello* new_hello(char *name, int length) {
  Hello *obj = (Hello*)calloc(1, sizeof(Hello));
  obj->name = (char*)calloc(1, sizeof(char)*(length+1));
  for(int i=0;i<length;i++) {
    obj->name[i] = name[i];
  }
  return obj;
}

char* hello_getName(Hello* obj) {
  //Hello* obj; 
  return obj->name;
}

void free_hello(Hello* obj) {
  if(obj == NULL) {
    return;
  }
  free(obj->name);
  free(obj);
}
}