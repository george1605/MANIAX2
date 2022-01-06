#pragma once
#define true (char)1
#define false (char)0
#define NOP() asm("nop")
#define HALT() asm("hlt")

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef char bool;
typedef long vptr;

char* textbuf = (char*)0xB8000;

int strlen(char* ptr){
  if(ptr == 0) return 0;
  int len = 0;
  while(ptr[len] != 0){
    len++;
  }
  return len;
}

void puts(char* p){
  

}