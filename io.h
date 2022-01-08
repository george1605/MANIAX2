#pragma once
#include "lib.c"

void outb(uint16_t port, uint8_t val)
{
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

void outw(uint16_t port, uint16_t val)
{
    asm volatile("outw %w0, %w1" : : "a" (val), "Nd" (port));
}

void outl(uint16_t port, uint32_t val)
{
    asm volatile("outl %0, %w1" : : "a" (val), "Nd" (port));
}

uint8_t inb(uint16_t port)
{
    uint8_t data;
    asm volatile("inb %w1, %b0" : "=a" (data) : "Nd" (port));
    return data;
}

uint16_t inw(uint16_t port)
{
    uint16_t data;
    asm volatile("inw %w1, %w0" : "=a" (data) : "Nd" (port));
    return data;
}

uint32_t inl(uint16_t port)
{
    uint32_t data;
    asm volatile("inl %w1, %0" : "=a" (data) : "Nd" (port));
    return data;
}

#define inportb(x) inb(x)
#define outportb(x,y) outb(x,y)
#define CRT_PORT 0x3D5
#define KBD_PORT 0x60

struct device {
    int ports[4];
    char(*getc)(struct device*);
    void(*putc)(char*, struct device*);
    void(*hnd)(struct regs*, struct device*);
};

char dev_getc(struct device* u)
{
    if(u == 0) return 0;
    return inportb(u->ports[0]);
}