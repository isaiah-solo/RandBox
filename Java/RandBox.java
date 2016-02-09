package randbox;

import java.util.*;

/**
 * RANDBOX: Java Version
 *
 * Created by isayyuhh on 2/7/2016
 */
public class RandBox {

   /**
    * Constants
    */
   private final static int INIT = 1;
   private final static int ZERO = 0;
   private final static int INCREMENT = 1;
   private final static int HUNDRED = 100;
   private final static String EMPTY = "";

   /**
    * HashMap containing elements in RandBox
    */
   private HashMap<String, Integer> map;

   /**
    * Default class constructor
    */
   public RandBox () {
      this.map = new HashMap<>();
   }

   /**
    * Class constructor specifying array of elements to add
    *
    * @param list: List of elements to add
    */
   public RandBox (String[] array) {
      this.map = new HashMap<>();
      for (String elem: array) {
         if (this.map.get(elem) == null) {
            Integer init = new Integer(INIT);
            this.map.put(elem, init);
         }
         else {
            int prevInt = this.map.get(elem).intValue();
            int newInt = prevInt + INCREMENT;
            this.map.put(elem, new Integer(newInt));
         }
      }
   }

   /**
    * Class constructor specifying list of elements to add
    *
    * @param list: List of elements to add
    */
   public RandBox (List<String> list) {
      this.map = new HashMap<>();
      for (String elem: list) {
         if (this.map.get(elem) == null) {
            Integer init = new Integer(INIT);
            this.map.put(elem, init);
         }
         else {
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
      Integer[] values = this.map.values().toArray(new Integer[ZERO]);

      for (Integer value: values) {
         size += value.intValue();
      }

      return size;
   }

   /**
    * Adds one or more elements to the RandBox
    *
    * @param newElem: String containing new element to be added
    * @param amount: amount of 'newElem' to be added
    * @return
    */
   public void add (String newElem, int amount) {
      if (amount < 1) return;
      if (this.map.containsKey(newElem)) {
         int prevInt = this.map.get(newElem).intValue();
         int newInt = prevInt + amount;
         this.map.put(newElem, new Integer(newInt));
      }
      else {
         this.map.put(newElem, new Integer(amount));
      }
   }
   
   /**
    * Deletes specified element from RandBox
    *
    * @param elem: String containing element to be deleted
    * @param amount: amount of 'newElem' to be deleted
    * @return
    */
   public void delete (String elem, int amount) {
      if (! this.map.containsKey(elem)) return;

      int prevInt = this.map.get(elem).intValue();
      int newInt = prevInt - amount;

      if (prevInt < amount) return;
      else if (prevInt < amount) this.map.remove(elem);
      else this.map.put(elem, new Integer(newInt));
   }

   /**
    * Deletes all elements from RandBox
    *
    * @return
    */
   public void deleteAll () {
      this.map.clear();
   }

   /**
    * Returns probability of specified element
    *
    * @param elem: String of element to check probability of
    * @return Float containing probability of element
    * @return Nothing if element doesnt exist
    */
   public float probability (String elem) {
      float probability = ZERO;

      if (this.map.containsKey(elem)) {
         probability = ((float) this.map.get(elem).intValue() * HUNDRED) /
                       ((float) this.size());
      }
      return probability;
   }

   /**
    * Chooses a random element from RandBox
    *
    * @return String of randomly picked element
    */
   public String pick () {
      String chosenElem = EMPTY;
      Random rand = new Random();

      int choice = rand.nextInt(this.size()) + INCREMENT;

      Set<Map.Entry<String, Integer>> set = map.entrySet();
      for (Map.Entry<String, Integer> elem: set) {
         int elemValue = elem.getValue().intValue();
         choice -= elemValue;
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
    * @return List containing Strings of all randomly picked elements
    */
   public List<String> pickMult (int amount) {
      List<String> choiceList = new ArrayList<>();
      for (int i = ZERO; i < amount; i++) {
         choiceList.add(this.pick());
      }
      return choiceList;
   }
}
