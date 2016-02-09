import java.util.*;

public class example {
   public static void main (String[] args) {
      // Variables to declare 
      String[] array = {"blue", "green", "purple"};
      int green = 0, red = 0, blue = 0, purple = 0;
      
      // Initialize new Randbox using an array of elements
      RandBox rb = new RandBox(array);
      
      // Add elements to RandBox
      rb.add("red", 5);
      
      // Delete elements from RandBox
      rb.delete("red", 2);

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
      List<String> list = rb.pickMult(20);
      
      for (String elem: list) {
         if (elem.equals("red")) red++;
         if (elem.equals("blue")) blue++;
         if (elem.equals("green")) green++;
         if (elem.equals("purple")) purple++;
      }
      
      System.out.println("Random 20 strings:");
      System.out.println("red: " + String.valueOf(red));
      System.out.println("blue: " + String.valueOf(blue));
      System.out.println("green: " + String.valueOf(green));
      System.out.println("purple: " + String.valueOf(purple));
   }
}
