public class test {
   public static void main (String[] args) {
      RandBox rand = new RandBox();
      rand.add("red", 3);
      rand.add("blue", 1);
      rand.add("green", 1);
      rand.add("purple", 1);

      System.out.println(rand.pickRand());
   }
}
