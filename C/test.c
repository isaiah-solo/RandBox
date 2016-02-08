#include <stdlib.h>
#include <stdio.h>

#include "RandBox.h"

int main (char** argv, int argc) {
   RandBox *rb = (RandBox *) malloc(sizeof(RandBox));
   char *test_text = "hello";
   char *other_test_text = "bruh";
   char *random = malloc(sizeof(char) * 100);
   int test = 0;
   int *test_size = malloc(sizeof(int));
   *test_size = 0;

   test += init_randbox(rb);
   test += add_randbox_elem(rb, test_text, 5);
   test += add_randbox_elem(rb, other_test_text, 1);

   size_randbox(rb, test_size);

   test += pick_randbox_elem(rb, random);

   if (test > 0) printf("1\n");

   printf("%s\n", random);
   return 0;
}
