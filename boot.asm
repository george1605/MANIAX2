; this is my bootloader
; i know i use 2 types of asm
; but that's because i have gcc ( I don't want to write Makefiles, just linker scripts )
global bmain

pushargs:
  push eax
  push ebx
  push ecx
  push eflags

popargs:
  pop eflags
  pop ecx
  pop ebx
  pop eax

bmain:
 sti
 jmp kmain
