#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include "RandBox.h"

/**
 * Helper function to find specific element in RandBox
 *
 * @param curr: Reference to current element
 * @param query: String containing name to search
 * @return If element found or not found
 */
static int find_elem(Element *curr, char *query)
{
   // Loop through RandBox
   while (curr->next != NULL)
   {
      // If element found
      if (strcmp(curr->name, query) == 0) break;
      curr = curr->next;
   }

   // If current element or last element matches query
   if (strcmp(curr->name, query) == 0) return 0;
   return 1;
}

/**
 * Initializes values in RandBox
 *
 * @param rb: Reference to RandBox
 * @return Success or failure
 */
int init_randbox (RandBox *rb)
{
   // Set initial size to zero
   rb->size = 0;
   return 0;
}

/**
 * Adds one or more elements to the RandBox
 *
 * @param rb: Reference to RandBox
 * @param new_name: String containing new element to be added
 * @param new_amount: amount of elements to be added
 * @return Success or failure
 */
int add_randbox_elem (RandBox *rb, char *new_name, int new_amount)
{
   // If amount given is invalid
   if (new_amount < 1) return 1;

   // If RandBox is Empty
   if (rb->first == NULL)
   {
      // Create first RandBox element
      Element *curr = (Element *) malloc(sizeof(Element));
      curr->name = new_name;
      curr->amount = new_amount;

      // Point first to current
      rb->first = curr;
   }

   // If RandBox is not empty
   else
   {
      // Point to first element
      Element *curr = rb->first;

      // Search for element in RandBox
      int result = find_elem(curr, new_name);

      // If element not found
      if (result == 1)
      {
         // Append new element to end of RandBox
         Element *temp = (Element *) malloc(sizeof(Element));
         temp->name = new_name;
         temp->amount = new_amount;
         curr->next = temp;
      }

      // If element found
      else curr->amount += new_amount;
   }

   // Increase size
   rb->size += new_amount;
   return 0;
}

/**
 * Deletes specified element from RandBox
 *
 * @param rb: Reference to RandBox
 * @param name: Name of element to delete
 * @return Success or failure
 */
int delete_randbox_elem (RandBox *rb, char *name) {
   // If RandBox is empty
   if (rb->first == NULL || rb->size == 0) return 1;

   // Point to first element
   Element *curr = rb->first;

   // Search for element in RandBox
   int result = find_elem(curr, name);

   // If element not found
   if (result == 1) return result;

   // If element found
   else
   {
      // If current is not pointing to the first element
      if (curr != rb->first)
      {
         // Attach current's previous with next
         Element *prev = rb->first;
         Element *next = curr->next;
         while (prev->next != curr) prev = prev->next;
         prev->next = next;
      }

      // If current is pointing to the first element
      else rb->first = rb->first->next;
   }

   // Free allocated memory
   free(curr->name);
   free(curr);
   return 0;
}

/**
 * Deletes all elements from RandBox
 *
 * @param rb: Reference to RandBox
 * @return Success or failure
 */
int delete_randbox_all (RandBox *rb) {
   // If RandBox is empty
   if (rb->first == NULL) return 1;

   // Point to first element
   Element *curr = rb->first;

   // Loop through each element
   while (curr != NULL) {
      // Create temporary pointer
      Element *temp = curr;

      // Delete the first element as it goes along
      curr = curr->next;
      free(temp);
   }
   return 0;
}

/**
 * Returns number of elements in RandBox
 *
 * @param rb: Reference to RandBox
 * @param size: Integer containing amount of elements in RandBox
 * @return Success or failure
 */
int size_randbox (RandBox *rb, int *size)
{
   // Copy size of RandBox to reference integer
   *size = rb->size;
   return 0;
}

/**
 * Static variable that tells if rand() is initialized
 */
static bool init_rand = false;

/**
 * Chooses random element from RandBox
 *
 * @param rb: Reference to RandBox
 * @param elem: Element to be chosen from RandBox
 * @return Success or failure
 */
int pick_randbox_elem (RandBox *rb, char *elem)
{
   // If rand() in not initialized
   if (! init_rand)
   {
      // Initialize rand()
      srand((unsigned int) time(NULL));

      // Set initialized rand() boolean to true
      init_rand = true;
   }

   // Choose random integer
   int choice = rand() % rb->size + 1;

   // Point to first element
   Element *curr = rb->first;

   // Loop through RandBox until element is picked
   while (curr != NULL)
   {
      // Subtract from random number
      choice -= curr->amount;

      // If random number becomes zero
      if (choice <= 0)
      {
         // Copy element to reference string
         strcpy(elem, curr->name);
         return 0;
      }
      curr = curr->next;
   }
   return 1;
}

/**
 * Chooses multiple random elements from RandBox
 *
 * @param rb: Reference to RandBox
 * @param choice_list: Array of elements chosen from RandBox
 * @param amount: Amount of elements to be picked
 * @return Success or failure
 */
int pick_randbox_elem_mult (RandBox *rb, char** choice_list, int amount)
{
   int result = 0;

   // Loop through pick function 
   for (int i = 0; i < amount; i++) result += pick_randbox_elem(rb, choice_list[i]);
   return result;
}
