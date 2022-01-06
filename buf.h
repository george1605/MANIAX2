#pragma once
#include "lib.c"
#define STDIN 0
#define STDOUT 1

struct buf {
  int flags;
  long blockno;
  char data[512];
};

struct vbuf {
  int fd;
  char* data;
  int size;
} iobufs[16];

void vbinit(){
  iobufs[0].data = textbuf;
}