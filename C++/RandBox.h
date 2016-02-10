#ifndef _RANDBOX_
#define _RANDBOX_

#include <string>
#include <vector>

using namespace std;
using Element = pair<string, int>;
using Elements = vector<Element>;
using Itor = Elements::iterator;

/**
 * RANDBOX: C++ Version
 *
 * Created by isayyuhh on 2/9/2016
 */

class RandBox
{
   private:
   
      /**
       * Vector of element pairs
       */
      Elements elements;

      /**
       * Helper function to check if RandBox is empty
       *
       * @return If RandBox is empty
       */
      bool is_empty ();

      /**
       * Helper function to find specific element in RandBox
       *
       * @param query: String containing name to search
       * @return Iterator pointing to current element
       */
      Itor find (string query);
      
   public:
   
      /**
       * Default constructor
       */
      RandBox();

      /**
       * Returns number of elements in RandBox
       *
       * @return Integer containing amount of elements in RandBox
       */
      int size ();

      /**
       * Adds one or more elements to the RandBox
       *
       * @param name: String containing new element to be added
       * @param amount: Amount of elements to be added
       * @return
       */
      void add (string name, int amount);

      /**
       * Deletes specified element from RandBox
       *
       * @param name: Name of element to delete
       * @param amount: Amount of elements to be added
       * @return
       */
      void del (string name, int amount);

      /**
       * Deletes all elements from RandBox
       *
       * @return
       */
      void del_all ();

      /**
       * Returns probability of specified element
       *
       * @param name: Name of element to find probability of
       * @return Float containing probability of element
       */
      float probability (string name);

      /**
       * Chooses random element from RandBox
       *
       * @return Element to be chosen from RandBox
       */
      string pick ();

      /**
       * Chooses multiple random elements from RandBox
       *
       * @param amount: Amount of elements to be picked
       * @return vector of random elements from RandBox
       */
      vector<string> mult_pick (int amount);
};
#endif
