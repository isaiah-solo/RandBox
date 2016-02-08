#ifndef _RANDBOX_
#define _RANDBOX_

typedef struct _RandBox RandBox;
typedef struct _Element Element;

int init_randbox (RandBox *rb); 
int add_randbox_elem (RandBox *rb, char *new_name, int new_amount);

#endif
