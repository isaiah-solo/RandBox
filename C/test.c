#include <stdlib.h>

#include "RandBox.h"

int main (char** argv, int argc) {
   RandBox *rb = (RandBox *) malloc(sizeof(RandBox));
   char *test_text = "hello\n";

   init_randbox(rb);
   add_randbox_elem(rb, test_text, 1);
   return 0;
}
