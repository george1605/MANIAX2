#include "io.h"
#include "buf.h"

struct fsnode {
  int id;
  int flags;
  char* name;
  struct fsnode* parent;
};

struct fsinfo {
  struct fsnode* root;
  int dno; // drive number
};