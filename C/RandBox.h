#ifndef _RANDBOX_
#define _RANDBOX_

typedef struct RandBox {
   Element *first;
   int size;
} RandBox;

typedef struct Element {
   char *name;
   int amount;
   Element *next;
} Element;

int add_randbox_elem (RandBox *rb, char *new_name, int new_amount);

#endif
