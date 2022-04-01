
// import javax.swing.text.StyledEditorKit.BoldAction; l'ha messa visual studio??
// invariant: 
// name!=null && surname!=null && socialSN>=0 && spouse!=this &&
// (p1.spouse==p2) == (p2.spouse==p1) && (p1==p2) == (p1.socialSN==p2.socialSN)

public class Person{
    public final String name; //valore obbligatorio e non modificabile (?)
    public final String surname;
    private final static String validator = "[A-Z][a-z]+( [A-Z][a-z]+)*"; //static perchè è utilizzato solo nella classe Person
    public final long socialSN; // deve essere una variabile di campo e non di oggetto 
    public Person spouse;

    // costruttore 
    public Person(String name, String surname, long socialSN){
        this.name = Person.auxNameValidator(name);
        this.surname = Person.auxNameValidator(surname);
        this.socialSN = Person.auxSocialSN_Validator(socialSN);
        this.spouse = null;
    }

    public boolean isSingle(){
        return (this.spouse == null);
    }

// decidere sull'opportunità che join e divorce siano metodi di oggetto o di classe.

    public void join(Person p1, Person p2){
        if(p1.socialSN!=p2.socialSN && p1.isSingle() && p2.isSingle()){
            p1.spouse = p2;
            p2.spouse = p1;
        }
        else
            throw new IllegalArgumentException(); //cosa fa crea precisamente "IllegalArgumentException"?
    }

    public void divorce(Person p1, Person p2){
        if(p1==p2.spouse && p2==p1.spouse){
            p1.spouse = null;
            p2.spouse = null;
        }
        else
            throw new IllegalArgumentException("errore: p1 e p2 non sono coniugi!");
    }  

// Definire metodi di classe private ausiliari per validare le pre-condizioni dei metodi pubblici e assicurare che gli invarianti vengano rispettati.

    private static String auxNameValidator(String name){
        if(name.matches(validator))
            return name;
        throw new IllegalArgumentException(name + "non è un nome valido >:(");
    }

    private static long auxSocialSN_Validator(long socialSN){ //mi sa che non serve il validatore per il codice fiscale...
        if(socialSN >= 0)
            return socialSN;
        throw new IllegalArgumentException("inserisci un codice fiscale valido!");
    }

    private static boolean auxDifferentReferences(Object a, Object b){
        if(a == b)
            throw new IllegalArgumentException();
        return true;
    }

    private static boolean auxPersonValidator(Person p1, Person p2){
        if((p1.spouse==p2) == (p2.spouse==p1) && (p1==p2) == (p1.socialSN==p2.socialSN))
            return true;
        throw new IllegalArgumentException();
    }
}

// public class HelloWorld {
//     public static void main(String[] args) {
//         assert "Hello world".length() == 11;
//         // System.out.println("hello");
//     }
// }