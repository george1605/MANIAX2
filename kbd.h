#pragma once
#include "intr.h"
#include "io.h"
char lastchr = 0;

void kbd_handler(struct regs* r)
{
  unsigned char scancode;
  scancode = inportb(0x60);

  if (scancode & 0x80)
  {
  }
  else
  {
    if(scancode == 0x27) return;
    lastchr = scancode;
  }
}
