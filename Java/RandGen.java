import java.util.*;

public class RandGen {
   private final static float HUNDRED = 100.0;
   private final static float INIT = 1.0;
   private HashMap<String, float> map;

   public RandGen () {
      this.map = new HashMap<>();
   }

   public RandGen (List<String> list) {
      this.map = new HashMap<>();
      for (String str: list) {
         float check = this.map.get(str);
         if (check == null) {
            float init = INIT;
            this.map.put(str, init);
         }
         else {
            check += 1;
         }
      }
   }
   
   
   
   
   
}
