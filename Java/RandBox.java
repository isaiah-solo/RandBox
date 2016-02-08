import java.util.*;

/**
 * RANDBOX: Java Version
 *
 * Created by isayyuhh on 2/7/2016
 */
public class RandBox {

   /**
    * Maximum percentage constant
    */
   private final static int MAX = 100;

   /**
    * Minimum percentage constant
    */
   private final static int MIN = 1;

   /**
    * HashMap containing elements in RandBox
    */
   private HashMap<String, Integer> map;

   /**
    * Int containing size of RandBox
    */
   private int size = 0;

   /**
    * Default class constructor
    */
   public RandBox () {
      this.map = new HashMap<>();
   }

   /**
    * Class constructor specifying list of elements to add
    *
    * @param list: List of elements to add
    */
   public RandBox (List<String> list) {
      this.map = new HashMap<>();
      for (String elem: list) {
         Integer check = this.map.get(elem);
         if (check == null) {
            Integer init = new Integer(MIN);
            this.map.put(elem, init);
         }
         else {
            check += 1;
         }
         this.size++;
      }
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
      this.size += amount;
   }
   
   /**
    * Deletes specified element from RandBox
    *
    * Deletes nothing if element does not exist
    *
    * @param elem: String containing element to be deleted
    * @return
    */
   public void delete (String elem) {
      if (this.map.containsKey(elem)) {
         this.map.remove(elem);
         this.size--;
      }
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
    * Returns number of elements in RandBox
    *
    * @return Size of RandBox
    */
   public int size() {
      return this.size;
   }

   /**
    * Returns probability of specified element
    *
    * @param elem: String of element to check probability of
    * @return Float containing probability of element
    * @return Nothing if element doesnt exist
    */
   public float chanceOf (String elem) {
      float percent = MIN;
      if (this.map.containsKey(elem)) {
         percent = ((float) this.map.get(elem) * 100) / ((float) MAX);
      }
      return percent;
   }

   /**
    * Chooses a random element from RandBox
    *
    * @return String of randomly picked element
    */
   public String pickRand () {
      String chosenElem = "";

      Random rand = new Random();
      int choice = rand.nextInt(this.size) + 1;

      Set<Map.Entry<String, Integer>> set = map.entrySet();
      for (Map.Entry<String, Integer> elem: set) {
         int elemValue = elem.getValue().intValue();
         choice -= elemValue;
         if (choice <= 0) {
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
   public List<String> pickMultRand (int amount) {
      List<String> choiceList = new ArrayList<>();
      for (int i = 0; i < amount; i++) {
         choiceList.add(this.pickRand());
      }
      return choiceList;
   }
}
