#define EXTMEM  0x100000      
#define PHYSTOP 0xE000000           
#define DEVSPACE 0xFE000000
  
#define KERNBASE 0x80000000       
#define KERNLINK (KERNBASE+EXTMEM) 

static inline int v2p(void *a) { return ((int) (a))  - KERNBASE; }
static inline void *p2v(uint a) { return (void *) ((a) + KERNBASE); }

struct mempage {
  void* phys;
  int size;
};
