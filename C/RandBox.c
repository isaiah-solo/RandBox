#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include "RandBox.h"

/**
 * RANDBOX: C Version
 *
 * Created by isayyuhh on 2/7/2016
 */

/**
 * Struct containing RandBox contents
 */
struct _RandBox
{
   Element *first;
};

/**
* Struct containing RandBox elements
*/
struct _Element
{
   char *name;
   int amount;
   Element *next;
   Element *prev;
};

/**
 * Helper function to check if RandBox is empty
 * 
 * @param rb: Reference to RandBox
 * @return If RandBox is empty
 */
static bool randbox_is_empty (RandBox **rb)
{
   return (*rb)->first == NULL;
}

/**
 * Helper function to find specific element in RandBox
 *
 * @param curr: Reference to current element
 * @param query: String containing name to search
 * @return If element found or not found
 */
static bool randbox_find (Element **curr, char *query)
{
   // Loop through RandBox
   for (; *curr != NULL; *curr = (*curr)->next)
   {
      // If element found
      if (strcmp((*curr)->name, query) == 0) return true;
   }
   return false;
}

/**
 * Initializes values in RandBox
 *
 * @param rb: Reference to RandBox
 * @return
 */
void randbox_init (RandBox **rb)
{
   // Initialize memory
   *rb = (RandBox *) malloc(sizeof(RandBox));
   (*rb)->first = NULL;
}

/**
 * Returns number of elements in RandBox
 *
 * @param rb: Reference to RandBox
 * @return Integer containing amount of elements in RandBox
 */
int randbox_size (RandBox **rb)
{
   int size = 0;

   // Loop through RandBox
   for (Element *curr = (*rb)->first; curr != NULL; curr = curr->next)
   {
      // Add amount of each element
      size += curr->amount;
   }
   return size;
}

/**
 * Adds one or more elements to the RandBox
 *
 * @param rb: Reference to RandBox
 * @param name: String containing new element to be added
 * @param amount: Amount of elements to be added
 * @return
 */
void randbox_add (RandBox **rb, char *name, int amount)
{
   // If amount given or name given are invalid
   if (amount < 1 || name == NULL) return;

   // Create RandBox element
   Element *temp = (Element *) malloc(sizeof(Element));
   temp->name = malloc(sizeof(char) * 100);
   strcpy(temp->name, name);
   temp->amount = amount;
   temp->next = NULL;
   temp->prev = NULL;
   
   // Point to first element
   Element *curr = (*rb)->first;

   // If element not found
   if (! randbox_find(&curr, name))
   {
      // Append new element to beginning
      if (! randbox_is_empty(rb)) (*rb)->first->prev = temp;
      temp->next = (*rb)->first;
      (*rb)->first = temp;
   }

   // Else if element found
   else curr->amount += amount;
}

/**
 * Deletes specified element from RandBox
 *
 * @param rb: Reference to RandBox
 * @param name: Name of element to delete
 * @param amount: Amount of elements to be deleted
 * @return
 */
void randbox_delete (RandBox **rb, char *name, int amount)
{
   // If RandBox is empty, or amount given or name given are invalid
   if (randbox_is_empty(rb) || amount < 1 || name == NULL) return;

   // Point to first element
   Element *curr = (*rb)->first;

   // If element not found
   if (! randbox_find(&curr, name)) return;

   // If amount to delete exceeds amount of element
   if (amount > curr->amount) return;

   // Else if amount to delete is equal to amount of element
   else if (amount == curr->amount)
   {
      // Connect current pointer's previous and next
      if (curr->next != NULL) curr->next->prev = curr->prev;
      if (curr->prev != NULL) curr->prev->next = curr->next;
      else (*rb)->first = curr->next;

      // Free allocated memory
      free(curr);
   }

   // Else if amount to delete is less than amount of element
   else curr->amount -= amount;
}

/**
 * Deletes all elements from RandBox
 *
 * @param rb: Reference to RandBox
 * @return
 */
void randbox_delete_all (RandBox **rb)
{
   // If RandBox is empty
   if (randbox_is_empty(rb)) return;

   // Point to first element
   Element *curr = (*rb)->first;

   // Loop through each element
   while (curr != NULL) {
      // Create temporary pointer
      Element *temp = curr;

      // Iterate current
      curr = curr->next;

      // Free temporary pointer
      randbox_delete(rb, temp->name, temp->amount);
   }
}

/**
 * Returns probability of specified element
 *
 * @param rb: Reference to RandBox
 * @param name: Name of element to find probability of
 * @return Float containing probability of element
 */
float randbox_probability (RandBox **rb, char *name)
{
   // If RandBox is empty
   if (randbox_is_empty(rb)) return 0;

   float probability = 0;

   // Point to first element
   Element *curr = (*rb)->first;

   // If element not found
   if (! randbox_find(&curr, name)) return 0;

   // Find probability
   probability = ((float)((curr->amount) * 100)) / ((float) randbox_size(rb));
   return probability;
}

/**
 * Static variable that tells if rand() is initialized
 */
static bool init_rand = false;

/**
 * Chooses random element from RandBox
 *
 * @param rb: Reference to RandBox
 * @return Element to be chosen from RandBox
 */
char *randbox_pick (RandBox **rb)
{
   // If RandBox is empty
   if (randbox_is_empty(rb)) return "FAILED";

   // If rand() in not initialized
   if (! init_rand)
   {
      // Initialize rand()
      srand((unsigned int) time(NULL));

      // Set initialized rand() boolean to true
      init_rand = true;
   }

   // Choose random integer
   int choice = rand() % randbox_size(rb) + 1;

   // Loop through RandBox until element is picked
   for (Element *curr = (*rb)->first; curr != NULL; curr = curr->next)
   {
      // Subtract from random number
      choice -= curr->amount;

      // If random number becomes zero, return chosen element
      if (choice <= 0) return curr->name;
   }
   return "FAILED";
}

/**
 * Chooses multiple random elements from RandBox
 *
 * @param rb: Reference to RandBox
 * @param choice_list: Reference to array of elements chosen from RandBox
 * @param amount: Amount of elements to be picked
 * @return
 */
void randbox_mult_pick (RandBox **rb, char ***choice_list, int amount)
{
   *choice_list = malloc(sizeof(char*) * amount);

   // Loop through pick function 
   for (int i = 0; i < amount; i++)
   {
      (*choice_list)[i] = malloc(sizeof(char) * 100);
      strcpy((*choice_list)[i], randbox_pick(rb));
   }
}
