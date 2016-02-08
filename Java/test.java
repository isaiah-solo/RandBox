import java.util.*;

public class test {
   public static void main (String[] args) {
      RandBox rand = new RandBox();
      rand.add("red", 3);
      rand.add("blue", 1);
      rand.add("green", 1);
      rand.add("purple", 1);

      int green = 0, red = 0, blue = 0, purple = 0;

      List<String> list = rand.pickMultRand(20);
      for (String elem: list) {
         if (elem.equals("red")) red++;
         if (elem.equals("blue")) blue++;
         if (elem.equals("green")) green++;
         if (elem.equals("purple")) purple++;
      }
      System.out.println("red: " + String.valueOf(red) + "\n" +
                         "blue: " + String.valueOf(blue) + "\n" +
                         "green: " + String.valueOf(green) + "\n" +
                         "purple: " + String.valueOf(purple) + "\n");
   }
}
