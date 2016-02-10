#include <iostream>
#include <string>
#include <vector>

#include "../RandBox.h"

using namespace std;

int main (int argc, char** argv)
{
   // Variables to declare, RandBox takes care of memory allocation
   RandBox rb;
   string red("red");
   string blue("blue");
   
   // Add elements to RandBox
   rb.add(red, 2);
   rb.add(blue, 9);

   // Delete elements from RandBox
   rb.del(blue, 2);
   
   // Displaying probability of selected elements from RandBox
   cout << "Red = " << rb.probability(red) << endl;
   cout << "Blue = " << rb.probability(blue) << endl << endl;

   // Displaying size of RandBox
   cout << "Size = " << rb.size() << endl << endl;
   
   // Random pick from RandBox
   cout << "Random 1 string:" << endl;

   cout << rb.pick() << endl << endl;

   // Multiple random picks from RandBox
   cout << "Random 10 strings:" << endl;
  
   auto multpick = rb.mult_pick(10);
   
   for (auto itor = multpick.begin(); itor != multpick.end(); ++itor) {
      cout << *itor << endl;
   }

   // Delete all elements from RandBox
   rb.del_all();

   return 0;
}
