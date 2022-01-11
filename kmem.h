#define EXTMEM  0x100000      
#define PHYSTOP 0xE000000           
#define DEVSPACE 0xFE000000
  
#define KERNBASE 0x80000000       
#define KERNLINK (KERNBASE+EXTMEM) 
#define PAGE_ALLIGN(x) if(x % 4096 > 0){ \
                         x -= (x % 4096); \
                         x += 4096; \
                       }

static inline int v2p(void *a) { return ((int) (a))  - KERNBASE; }
static inline void *p2v(uint a) { return (void *) ((a) + KERNBASE); }
int* sbrk = p2v(1);

struct mempage {
  void* phys;
  int size;
};

void* pgalloc(int bytes){ // allocates 4K pages
  void* u = sbrk;
  sbrk = u + PAGE_ALLIGN(bytes) + 2;
  *u = 0xdeadbeef;
  *(sbrk-1) = 0;
  return (u+1);
}