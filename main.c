#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct TREE_NODE {
  struct TREE_NODE* right;
  struct TREE_NODE* left;
  struct TREE_NODE* parent;
  int value;
} TREE_NODE;
const int MAX_DEPTH = 3;
static int _rand(){return rand()%20;}
void _rand_tree (TREE_NODE**, int, int);
TREE_NODE *parent = NULL;
int main() {
  srand(time(NULL));

  TREE_NODE* array;
  TREE_NODE* node = NULL;

  _rand_tree(&node, MAX_DEPTH, 0);

  printf("%s\n", "test");
}
void _rand_tree (TREE_NODE** node, int depth,int  level)
{
  if(parent == NULL) {
    TREE_NODE *child = (TREE_NODE*)malloc(sizeof(TREE_NODE));
    child->value = _rand();
    parent = child;
    _rand_tree(&child->left, depth, level + 1);
  }
  if(level >= depth) {
    return;
  } else {
    if(*node == NULL) {

      TREE_NODE *child = (TREE_NODE*)malloc(sizeof(TREE_NODE));
      child->value = _rand();

      printf("%s%d\n", "eklenen deger:", child->value);

      child->left = child->right = NULL;

      *node = child;

      _rand_tree(&child->left, depth, level + 1);
      _rand_tree(&child->right, depth, level + 1);

    }
  }
}

