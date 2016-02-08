public class Main {
   public static void main (String[] args) {
      RandGen rand = new RandGen("red");
      rand.add("red");
      rand.add("red");
      rand.add("blue");
      rand.add("green");
      rand.add("purple");

      System.out.println(rand.pickRand());
   }
}
