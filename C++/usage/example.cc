#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

#include "../RandBox.h"

using namespace std;

int main (int argc, char** argv)
{
   // Variables to declare, RandBox takes care of memory allocation
   RandBox *rb;
   char **multpick;
   string red_str = "red";
   string blue_str = "blue";
   vector<char> red(red_str.begin(), red_str.end()); red.push_back('\0');
   vector<char> blue(blue_str.begin(), blue_str.end()); blue.push_back('\0');
   
   // Initialize RandBox
   randbox_init(&rb);
   
   // Add elements to RandBox
   randbox_add(&rb, &*red.begin(), 2);
   randbox_add(&rb, &*blue.begin(), 9);

   // Delete elements from RandBox
   randbox_delete(&rb, &*blue.begin(), 2);
   
   // Displaying probability of selected elements from RandBox
   printf("Red = %f\n", randbox_probability(&rb, &*red.begin()));
   printf("Blue = %f\n\n", randbox_probability(&rb, &*blue.begin()));

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
