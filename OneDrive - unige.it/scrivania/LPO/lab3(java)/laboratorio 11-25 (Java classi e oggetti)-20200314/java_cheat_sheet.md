**final (variabili)**: variabile NON modificabile. Posso crearla vuota (`final int max;`) per riempirla successivamente nel main (magari da input user).

**final (metodi)**: una volta creata una funzione final in una classe, non può esistere un'altra funzione (anche non final) con lo stesso nome in una seconda classe che estende la prima. 

**final (class)**: non può essere estesa da altre. 

**static (metodi)**: la funzione appartiene alla CLASSE e non al singolo oggetto. Può essere usato ovunque nel codice SENZA CREARE UN OGGETTO della stessa. Non usa 'this'.

**static (variabili)**: la variabile può essere usata ovunque nel programma, come i define del c (o le macro). Sono comuni per tutte le istanze. PUO' ESSERE MODIFICATA.

**static (class)**: posso creare classi static solo all'interno di altre classi (nestedClass) e i metodi public della nestedClass potranno usare solo variabili (membri) static della classe padre. 

**static final** : variabile condivisa in tutto il codice e non modificabile. 

**public** : posso accedere alla funzione SOLO DA UN OGGETTO della classe;

​	ESEMPIO: 

```java
public class MyClass {
  // Static method
  static void myStaticMethod() {
    System.out.println("Static methods can be called without creating objects");
  }

  // Public method
  public void myPublicMethod() {
    System.out.println("Public methods must be called by creating objects");
  }

  // Main method
  public static void main(String[] args) {
    myStaticMethod(); // Call the static method
    // myPublicMethod(); This would compile an error

    MyClass myObj = new MyClass(); // Create an object of MyClass
    myObj.myPublicMethod(); // Call the public method on the object
  }
}
```



**private (variabile)** : lo vedo solo all'interno del programma 

**default method in interface**: si usano nelle interfaccie per creare una funzione 'statica', che non può essere definita successivamente e usabile dalle classi che implementato l'interfaccia. Possono essere sovrascritti (overridden) da metodo con lo stesso nome definiti nella classe. 

**static method in interface**: come il defaul ma non può essere overridden da una funzione omonima.

**private method in interface**: funzione che posso usare solamente all'interno dell'interfaccia. Classi che implementano quest'ultima non potranno usare le funzioni private. 

​	ESEMPIO:

```java
interface MyInterfaceInJava9 {
   default void method1() {
	//calling private method
	printLines();
	System.out.println("This is method1");
   }
   default void method2() {
	//calling private method
	printLines();
	System.out.println("This is method2");
   }
   private void printLines() {
	System.out.println("Starting method");
	System.out.println("Doing someting");
   }
}
public class JavaExample implements MyInterfaceInJava9{
   public static void main(String args[]) {
	JavaExample je = new JavaExample();
	je.method1();
	je.method2();
   }
}

Output:
Starting method
Doing someting
This is method1
Starting method
Doing someting
This is method2
```

**implements**: serve ad implementare un' INTERFACCIA;

**extend**: seve ad estendere una CLASSE;

**classe vs interfaccia**: nelle interfaccie non puoi implementare metodi (ma puoi dichiararli);

**package**: A package is a namespace that organizes a set of related classes and interfaces. Conceptually you can think of packages as being similar to different folders on your computer. You might keep HTML pages in one folder, images in another, and scripts or applications in yet another. Because software written in the Java programming language can be composed of hundreds or *thousands* of individual classes, it makes sense to keep things organized by placing related classes and interfaces into packages.