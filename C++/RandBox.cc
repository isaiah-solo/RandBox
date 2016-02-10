#include "RandBox.h"

using namespace std;

/**
 * RANDBOX: C++ Version
 *
 * Created by isayyuhh on 2/9/2016
 */

RandBox::RandBox(): elements{} {}

/**
 * Helper function to check if RandBox is empty
 * 
 * @return If RandBox is empty
 */
bool RandBox::is_empty ()
{
   return this->elements.empty();
}

/**
 * Helper function to find specific element in RandBox
 *
 * @param query: String containing name to search
 * @return Iterator pointing to current element
 */
Itor RandBox::find (string query)
{
   auto itor = this->elements.begin();

   // Loop through RandBox
   for (; itor != this->elements.end(); ++itor)
   {
      // If element found
      if (query.compare(itor->first) == 0) break;
   }
   return itor;
}

/**
 * Returns number of elements in RandBox
 *
 * @return Integer containing amount of elements in RandBox
 */
int RandBox::size ()
{
   int size = 0;

   // Loop through RandBox
   for (auto itor = this->elements.begin(); itor != this->elements.end();
        ++itor)
   {
      // Add amount of each element
      size += itor->second;
   }
   return size;
}

/**
 * Adds one or more elements to the RandBox
 *
 * @param name: String containing new element to be added
 * @param amount: Amount of elements to be added
 * @return
 */
void RandBox::add (string name, int amount)
{
   // If amount given or name given are invalid
   if (amount < 1 || name.empty()) return;

   // Create RandBox element
   Element temp(name, amount);
   
   // Find element
   auto itor = this->find(name);

   // If element not found
   if (itor == this->elements.end()) this->elements.push_back(temp);

   // Else if element found
   else itor->second += amount;
}

/**
 * Deletes specified element from RandBox
 *
 * @param name: Name of element to delete
 * @param amount: Amount of elements to be deleted
 * @return
 */
void RandBox::del (string name, int amount)
{
   // If RandBox is empty, or amount given or name given are invalid
   if (this->is_empty() || amount < 1 || name.empty()) return;

   // Find element
   auto itor = this->find(name);

   // If element not found
   if (itor == this->elements.end()) return;

   // If amount to delete exceeds amount of element
   if (amount > itor->second) return;

   // Else if amount to delete is equal to amount of element
   else if (amount == itor->second) this->elements.erase(itor);

   // Else if amount to delete is less than amount of element
   else itor->second -= amount;
}

/**
 * Deletes all elements from RandBox
 *
 * @return
 */
void RandBox::del_all ()
{
   this->elements.clear();
}

/**
 * Returns probability of specified element
 *
 * @param name: Name of element to find probability of
 * @return Float containing probability of element
 */
float RandBox::probability (string name)
{
   // If RandBox is empty
   if (this->is_empty()) return 0;

   float probability = 0;

   // Find element
   auto itor = this->find(name);

   // If element found
   if (itor != this->elements.end())
   {
      // Find probability
      probability = ((float)((itor->second) * 100)) /
                    ((float) this->size());
   }
   return probability;
}

/**
 * Static variable that tells if rand() is initialized
 */
static bool init_rand = false;

/**
 * Chooses random element from RandBox
 *
 * @return Element to be chosen from RandBox
 */
string RandBox::pick ()
{
   string failed = "FAILED";
   
   // If RandBox is empty
   if (this->is_empty()) return failed;

   // If rand() in not initialized
   if (! init_rand)
   {
      // Initialize rand()
      srand((unsigned int) time(NULL));

      // Set initialized rand() boolean to true
      init_rand = true;
   }

   // Choose random integer
   int choice = rand() % this->size() + 1;

   // Loop through RandBox until element is picked
   for (auto itor = this->elements.begin(); itor != this->elements.end();
        ++itor)
   {
      // Subtract from random number
      choice -= itor->second;

      // If random number becomes zero, return chosen element
      if (choice <= 0) return itor->first;
   }
   return failed;
}

/**
 * Chooses multiple random elements from RandBox
 *
 * @param amount: Amount of elements to be picked
 * @return vector of random elements from RandBox
 */
vector<string> RandBox::mult_pick (int amount)
{
   vector<string> choice_list;

   // Loop through pick function 
   for (int i = 0; i < amount; i++) choice_list.push_back(this->pick());
   return choice_list;
}
