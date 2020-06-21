public class HelloWorld {

  public static void main(String[] args) {

    Greetings greetingsInstance = n -> System.out.println("Hello World " + n);
    greet(greetingsInstance, "Itachi");
  }

  private static void greet(Greetings greetingsInstance, String name) {
    greetingsInstance.sayHello(name);
  }
}