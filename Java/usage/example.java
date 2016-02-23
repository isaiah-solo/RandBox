import java.util.*;
import randbox.*;

public class example {
   public static void main (String[] args) {
      // Variables to declare 
      Object[] array = {(Object) "blue", (Object) "green", (Object) "purple"};
      Object redString = (Object) "red";
      int green = 0, red = 0, blue = 0, purple = 0;
      
      // Initialize new Randbox using an array of elements
      RandBox rb = new RandBox(array);
      
      // Add elements to RandBox
      rb.add(redString, 5);
      
      // Delete elements from RandBox
      rb.delete(redString, 2);

      // Displaying probability of selected elements from RandBox
      System.out.println("Red = " + String.valueOf(
                         rb.probability("red")));
      System.out.println("Blue = " + String.valueOf(
                         rb.probability("blue")) + "\n");
      
      // Displaying size of RandBox
      System.out.println("Size = " + String.valueOf(
                         rb.size()) + "\n");
      
      // Pick random element from RandBox
      System.out.println("Random 1 string:");
      System.out.println(rb.pick() + "\n");
      
      // Pick multiple random elements from RandBox
      List<Object> list = rb.multPick(20);
      
      for (Object elem: list) {
         if (((String) elem).equals("red")) red++;
         if (((String) elem).equals("blue")) blue++;
         if (((String) elem).equals("green")) green++;
         if (((String) elem).equals("purple")) purple++;
      }
      
      System.out.println("Random 20 strings:");
      System.out.println("red: " + String.valueOf(red));
      System.out.println("blue: " + String.valueOf(blue));
      System.out.println("green: " + String.valueOf(green));
      System.out.println("purple: " + String.valueOf(purple));
   }
}
