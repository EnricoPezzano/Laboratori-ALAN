// invarianti:
// (balance >= limit) && (id >= 0) && (c1==c2) == (c1.id==c2.id)

public class CreditAccount
{
    //here-------------------------------

    // devono essere private per non essere accessibili dalle altre classi
    public int limit;
    public int balance;
    public final Person owner;
    public long id; // deve essere una variabile di campo e non di oggetto 
    private static final int default_limit = 0;

// Definire i costruttori più opportuni che ne garantiscano la validità.

    // costruttori
    public CreditAccount(int limit, int balance, Person owner){
        this.limit = limit;
        this.balance = balance;
        this.owner = owner;
    }
    public CreditAccount(int balance, Person owner){

        this.balance = balance;
        this.owner = owner;
    }

// decidere sull'opportunità che deposit, withdraw, setLimit, newOfLimitBalanceOwner e newOfLimitBalanceOwner siano metodi di oggetto o di classe.

    // instance methods
    public int deposit(int amount)
    {
        if(amount <= 0)
            throw new IllegalArgumentException();
        else
            this.balance = this.balance + amount;
        return this.balance;
    }
    public int withdraw(int amount)
    {
        if(amount<=0 || (this.balance - amount < this.limit))
            throw new IllegalArgumentException();
        else
            this.balance = this.balance - amount;
        return this.balance;
    }
    public void setLimit(int limit)
    {
        if(this.balance<limit)
            throw new IllegalArgumentException();
        else
            this.limit=limit;
    }
    
    // metodi di classe
    public static CreditAccount newOfLimitBalanceOwner(int limit, int balance, Person owner){
        if(balance < 0)
            throw new IllegalArgumentException();
        CreditAccount c1 = new CreditAccount(limit, balance, owner);
        return c1;
    }

    public static CreditAccount newOfBalanceOwner(int balance, Person owner){
        if(balance < 0)
            throw new IllegalArgumentException();
        CreditAccount c1 = new CreditAccount(default_limit, balance, owner);
        return c1;
    }

    // metodi di classe private aux per validare le -->pre-condizioni dei metodi pubblici<-- e assicurare che gli invarianti vengano rispettati.
    private static int auxBalanceValidator(int balance, int limit){
        if(balance < limit)
            throw new IllegalArgumentException();
        return balance;
    }    

    private static int auxIdValidator(int id){
        if(id < 0)
            throw new IllegalArgumentException();
        return id;
    }

    private static boolean auxAccountValidator(CreditAccount c1, CreditAccount c2){
        if((c1 == c2) == (c1.id==c2.id))
            return true;
        throw new IllegalArgumentException();
    }
}
// Scrivere una semplice classe Test per verificare la classe CreditAccount con il costrutto assert.