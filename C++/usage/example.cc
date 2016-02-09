#include <stdlib.h>
#include <stdio.h>

#include "../RandBox.h"

int main (int argc, char** argv)
{
   // Variables to declare, RandBox takes care of memory allocation
   RandBox *rb;
   char **multpick;
   
   // Initialize RandBox
   randbox_init(&rb);
   
   // Add elements to RandBox
   randbox_add(&rb, "red", 2);
   randbox_add(&rb, "blue", 9);

   // Delete elements from RandBox
   randbox_delete(&rb, "blue", 2);
   
   // Displaying probability of selected elements from RandBox
   printf("Red = %f\n", randbox_probability(&rb, "red"));
   printf("Blue = %f\n\n", randbox_probability(&rb, "blue"));

   // Displaying size of RandBox
   printf("Size = %d\n\n", randbox_size(&rb));
   
   // Random pick from RandBox
   printf("Random 1 string:\n");

   printf("%s\n\n", randbox_pick(&rb));

   // Multiple random picks from RandBox
   printf("Random 10 strings:\n");
  
   randbox_mult_pick(&rb, &multpick, 10);
   
   for (int i; i < 10; i++) {
      printf("%s\n", multpick[i]);
   }

   // Delete all elements from RandBox
   randbox_delete_all(&rb);

   // Finally, free RandBox
   free(rb);

   return 0;
}
