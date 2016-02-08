#include <stdlib.h>
#include <stdio.h>

#include "RandBox.h"

int main (char** argv, int argc) {
   RandBox *rb = (RandBox *) malloc(sizeof(RandBox));
   char *test_text = "hello";
   char *other_test_text = "bruh";
   char **random = malloc(sizeof(char*) * 10);
   for (int i = 0; i < 10; i++) {
      random[i] = malloc(sizeof(char) * 100);
   }
   int test = 0;

   test += init_randbox(rb);
   test += add_randbox_elem(rb, test_text, 5);
   test += add_randbox_elem(rb, other_test_text, 1);
   test += pick_randbox_elem_mult(rb, random, 10);
   for (int i = 0; i < 10; i++) {
      printf("%s\n", random[i]);
   }
   delete_randbox_all(rb);
   //free(random);
   return 0;
}
