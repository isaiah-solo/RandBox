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
static int find_element(Element *curr, char *query)
{
   while (curr->next != NULL)
   {
      if (strcmp(curr->name, query) == 0) break;
      curr = curr->next;
   }
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
      int result = find_element(curr, new_name);

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
 * Returns number of elements in RandBox
 *
 * @param rb: Reference to RandBox
 * @param size: Integer containing amount of elements in RandBox
 * @return Success or failure
 */
int size_randbox (RandBox *rb, int *size)
{
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
   if (! init_rand)
   {
      srand((unsigned int) time(NULL));
      init_rand = true;
   }
   int choice = rand() % rb->size + 1;
   Element *curr = rb->first;
   while (curr != NULL)
   {
      choice -= curr->amount;
      if (choice <= 0)
      {
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
   for (int i = 0; i < amount; i++) result += pick_randbox_elem(rb, choice_list[i]);
   return result;
}
