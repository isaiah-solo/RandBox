#include "RandBox.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _RandBox {
   Element *first;
   int size;
};

struct _Element {
   char *name;
   int amount;
   Element *next;
};

/**
 * Helper function to find specific element in RandBox
 *
 * @param curr: Reference to current element
 * @param query: String containing name to search
 */
static int find_element(Element *curr, char *query) {
   while (curr->next != NULL) {
      if (strcmp(curr->name, query) == 0) {
         break;
      }
      curr = curr->next;
   }
   if (strcmp(curr->name, query) == 0) {
      return 0;
   }
   return 1;
}

/**
 * Initializes values in RandBox
 *
 * @param rb: Reference to RandBox
 */
int init_randbox (RandBox* rb) {
   rb->size = 0;
   return 0;
}

/**
 * Adds one or more elements to the RandBox
 *
 * @param rb: Reference to RandBox
 * @param new_name: String containing new element to be added
 * @param new_amount: amount of elements to be added
 */
int add_randbox_elem (RandBox *rb, char *new_name, int new_amount)
{
   // If amount given is invalid
   if (new_amount < 1) return 1;

   // Create current element pointer
   Element *curr = rb->first;

   // If RandBox is Empty
   if (curr == NULL)
   {
      // Create first RandBox element
      curr = (Element *) malloc(sizeof(Element));
      curr->name = new_name;
      curr->amount = new_amount;
   }

   // If RandBox is not empty
   else
   {
      // Search for element in RandBox
      int result = find_element(curr, new_name);

      // If element not found
      if (result == 1)
      {
         // Append new element to end of RandBox
         curr->next = (Element *) malloc(sizeof(Element));
         curr->next->name = new_name;
         curr->next->amount = new_amount;
      }

      // If element found
      else
      {
         curr->amount += new_amount;
      }
   }
   return 0;
}
