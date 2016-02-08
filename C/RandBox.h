#ifndef _RANDBOX_
#define _RANDBOX_

typedef struct _RandBox RandBox;
typedef struct _Element Element;

struct _RandBox {
   Element *first;
   int size;
};

struct _Element {
   char *name;
   int amount;
   Element *next;
};

int init_randbox (RandBox *rb); 
int add_randbox_elem (RandBox *rb, char *new_name, int new_amount);
int pick_randbox_elem (RandBox *rb, char *elem);
int size_randbox (RandBox *rb, int *size);
int pick_randbox_elem_mult (RandBox *rb, char** choice_list, int amount);

#endif
