import java.util.*;
import randbox.*;

public class example {
   public static void main (String[] args) {
      // Variables to declare 
      String red = new String("red");
      String blue = new String("blue");
      String green = new String("green");
      String purple = new String("purple");
      String[] array = {blue, green, purple};
      int g = 0, r = 0, b = 0, p = 0;
      
      // Initialize new Randbox using an array of elements
      RandBox rb = new RandBox(array);
      
      // Add elements to RandBox
      rb.add(red, 5);
      
      // Delete elements from RandBox
      rb.delete(red, 2);

      // Displaying probability of selected elements from RandBox
      System.out.println("red = " + String.valueOf(
                         rb.probability(red)));
      System.out.println("blue = " + String.valueOf(
                         rb.probability(blue)) + "\n");
      
      // Displaying size of RandBox
      System.out.println("size = " + String.valueOf(
                         rb.size()) + "\n");
      
      // Pick random element from RandBox
      System.out.println("random 1 string:");
      System.out.println((String) rb.pick() + "\n");
      
      // Pick multiple random elements from RandBox
      List<Object> list = rb.multPick(20);
      
      for (Object elem: list) {
         if (((String) elem).equals("red")) r++;
         if (((String) elem).equals("blue")) b++;
         if (((String) elem).equals("green")) g++;
         if (((String) elem).equals("purple")) p++;
      }
      
      System.out.println("random 20 strings:");
      System.out.println("red: " + String.valueOf(r));
      System.out.println("blue: " + String.valueOf(b));
      System.out.println("green: " + String.valueOf(g));
      System.out.println("purple: " + String.valueOf(p));
   }
}
