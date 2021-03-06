package io.github.isaiah_solo;

import java.util.*;

/**
 * RandBox: Java Library
 *
 * Created by isaiah on 2/7/2016
 */
public class RandBox {

   /**
    * Constant Declarations
    */
   private final static int INIT = 1;
   private final static int ZERO = 0;
   private final static int INCREMENT = 1;
   private final static int HUNDRED = 100;
   private final static String EMPTY = "";

   /**
    * HashMap containing elements in RandBox
    */
   private HashMap<Object, Integer> map;

   /**
    * Default class constructor
    */
   public RandBox () {
      this.map = new HashMap<>();
   }

   /**
    * Class constructor specifying array of elements to add
    *
    * @param list List of elements to add
    */
   public RandBox (Object[] array) {
      // Initialize new HashMap
      this.map = new HashMap<>();

      // Loop through array elements
      for (Object elem: array) {
         // If element not found in HashMap
         if (this.map.get(elem) == null) {
            // Add to HashMap
            Integer init = new Integer(INIT);
            this.map.put(elem, init);
         }

         // If element already in HashMap
         else {
            // Increment amount of element in HashMap
            int prevInt = this.map.get(elem).intValue();
            int newInt = prevInt + INCREMENT;
            this.map.put(elem, new Integer(newInt));
         }
      }
   }

   /**
    * Class constructor specifying list of elements to add
    *
    * @param list List of elements to add
    */
   public RandBox (List<Object> list) {
      // Initialize new HashMap
      this.map = new HashMap<>();

      // Loop through list elements
      for (Object elem: list) {
         // If element not found in HashMap
         if (this.map.get(elem) == null) {
            // Add to HashMap
            Integer init = new Integer(INIT);
            this.map.put(elem, init);
         }

         // If element already in HashMap
         else {
            // Increment amount of element in HashMap
            int prevInt = this.map.get(elem).intValue();
            int newInt = prevInt + INCREMENT;
            this.map.put(elem, new Integer(newInt));
         }
      }
   }

   /**
    * Returns number of elements in RandBox
    *
    * @return Integer containing amount of elements in RandBox
    */
   public int size () {
      int size = ZERO;

      // Get all values in RandBox
      Integer[] values = this.map.values().toArray(new Integer[ZERO]);

      // Loop through all values
      for (Integer value: values) {
         // For each value, add to size
         size += value.intValue();
      }
      return size;
   }

   /**
    * Adds one or more elements to the RandBox
    *
    * @param newElem New element to be added
    * @param amount Amount of elements to be added
    */
   public void add (Object newElem, int amount) {
      // If invalid amount
      if (amount < 1) return;

      // If element already in RandBox
      if (this.map.containsKey(newElem)) {
         // Increment amount of element in RandBox
         int prevInt = this.map.get(newElem).intValue();
         int newInt = prevInt + amount;
         this.map.put(newElem, new Integer(newInt));
      }

      // If element not in RandBox
      else {
         // Insert into RandBox
         this.map.put(newElem, new Integer(amount));
      }
   }
   
   /**
    * Deletes specified element from RandBox
    *
    * @param elem: Element to be deleted
    * @param amount: Amount of elements to be deleted
    */
   public void delete (Object elem, int amount) {
      // If element is not in RandBox
      if (! this.map.containsKey(elem)) return;

      int prevInt = this.map.get(elem).intValue();
      int newInt = prevInt - amount;

      // If amount exceeds amount of element in RandBox
      if (prevInt < amount) return;

      // Else if amount is equal to amount of element in RandBox
      else if (prevInt == amount) this.map.remove(elem);

      // Else if amount is less than amount of element in RandBox
      else this.map.put(elem, new Integer(newInt));
   }

   /**
    * Deletes all elements from RandBox
    */
   public void deleteAll () {
      // Clear all in RandBox
      this.map.clear();
   }

   /**
    * Returns probability of specified element
    *
    * @param elem: Element to check probability of
    * @return Float containing probability of element
    */
   public float probability (Object elem) {
      // Set initial probability to zero
      float probability = ZERO;

      // If element exists in RandBox
      if (this.map.containsKey(elem)) {
         // Find probability of element
         probability = ((float) this.map.get(elem).intValue() * HUNDRED) /
                       ((float) this.size());
      }
      return probability;
   }

   /**
    * Chooses a random element from RandBox
    *
    * @return Randomly picked element
    */
   public Object pick () {
      // Initialize chosen element variable to empty String
      Object chosenElem = EMPTY;

      // New Random object
      Random rand = new Random();

      // Choose random integer
      int choice = rand.nextInt(this.size()) + INIT;

      // Loop through each element
      Set<Map.Entry<Object, Integer>> set = map.entrySet();
      for (Map.Entry<Object, Integer> elem: set) {
         int elemValue = elem.getValue().intValue();

         // Subtract from random integer as RandBox is iterated
         choice -= elemValue;

         // If random integer becomes zero, return current element
         if (choice <= ZERO) {
            chosenElem = elem.getKey();
            break;
         }
      }
      return chosenElem;
   }

   /**
    * Chooses multiple random elements from RandBox
    *
    * @param amount: Amount of random elements to be picked
    * @return List containing all randomly picked elements
    */
   public List<Object> multPick (int amount) {
      // Create initial list of random integers
      List<Object> choiceList = new ArrayList<>();

      // If invalid amount
      if (amount < 1) return choiceList;

      // Pick random integers for amount specified
      for (int i = ZERO; i < amount; i++) {
         // Add random integer to list
         choiceList.add(this.pick());
      }
      return choiceList;
   }
}
