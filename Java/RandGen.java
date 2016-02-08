import java.util.*;

public class RandGen {
   private final static int HUNDRED = 100;
   private final static int INIT = 1;

   private int size = 0;
   private HashMap<String, Integer> map;

   public RandGen () {
      this.map = new HashMap<>();
   }

   public RandGen (String elem) {
      this.map = new HashMap<>();
      Integer init = new Integer(INIT);
      this.map.put(elem, init);
      this.size++;
   }

   public RandGen (List<String> list) {
      this.map = new HashMap<>();
      for (String elem: list) {
         Integer check = this.map.get(elem);
         if (check == null) {
            Integer init = new Integer(INIT);
            this.map.put(elem, init);
         }
         else {
            check += 1;
         }
         this.size++;
      }
   }
   
   public void add (String newElem) {
      if (this.map.containsKey(newElem)) {
         Integer newInt = new Integer(this.map.get(newElem).intValue() + 1);
         this.map.put(newElem, newInt);
      }
      else {
         Integer init = new Integer(INIT);
         this.map.put(newElem, init);
      }
      this.size++;
   }
   
   public void delete (String elem) {
      if (this.map.containsKey(elem)) {
         this.map.remove(elem);
         this.size--;
      }
   }
   
   public float checkChance (String elem) {
      float percent = 0;
      if (this.map.containsKey(elem)) {
         percent = ((float) this.map.get(elem) * 100) / ((float) HUNDRED);
      }
      return percent;
   }

   public String pickRand () {
      Random rand = new Random();
      int choice = rand.nextInt(this.size) + 1;

      Set<Map.Entry<String, Integer>> set = map.entrySet();
      for (Map.Entry<String, Integer> elem: set) {
         choice -= elem.getValue().intValue();
         if (choice <= 0) {
            return elem.getKey();
         }
      }
      return "ERROR";
   }
}
