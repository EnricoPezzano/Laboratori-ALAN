public class CreditAccount{
	private int limit; //obblig, modificabile e può essere negativo
	private int balance; //obblig, modificabile e non minore di limit
	public final Person owner; //obbligatorio e non modificabile.
	public final long id; //obblig, non modificabile, non può essere negativo

	private static long next_id;

	private static long getNext_id(){
		return CreditAccount.next_id++;
	}

	public static final int default_limit = 0; //deve essere definito il dato default_limit, non modificabile, ma accessibile all’esterno della classe, che stabilisce che il limite di giacenza predefinito e` pari a 0

	public int getLimit(){
		return this.limit;
	}
	public  int getBalance(){
		return this.balance;
	}

	public Person getOwner(){
		return this.owner;
	}

	public long getId(){
		return this.id;
	}

	public int deposit(int amount){
		if(amount <0)
			throw new IllegalArgumentException("can't deposit negative amount");
		this.balance += amount;
		return this.balance/100;
	} 

	public int withdraw(int amount){
		if(amount <0)
			throw new IllegalArgumentException("can't deposit negative amount");
		int nuovo_balance = this.balance;
		nuovo_balance -=amount;
		if (nuovo_balance<limit)
			throw new IllegalArgumentException("Non puoi prelevare quella somma");
		else 
			this.balance = nuovo_balance;
		return this.balance/100; 
	}

	public void setLimit(int limit){
		if (this.balance<limit) {
			throw new IllegalArgumentException("Non puoi");
		} else this.limit = limit;
	}
	
	public CreditAccount(int limit, int balance, Person owner, long id){
		if (limit < 0)
			throw new IllegalArgumentException("limit can't be negative");
		if(balance<limit)
			throw new IllegalArgumentException("Sorry bro, you're poor as fuck");
		if(id<0)
			throw new IllegalArgumentException("IllegalArgumentException");

		this.limit = limit;
		this.balance = balance;
		this.owner = owner;
		this.id = id;
	}

	//static factory method
	/*
	1) Constructors don't have meaningful names, so they are always restricted to the standard naming convention imposed by the language.
		Static factory methods can have meaningful names, hence explicitly conveying what they do.

	2) Static factory methods can return the same type that implements the method(s), a subtype, and also primitives,
		so they offer a more flexible range of returning types.

	3) Static factory methods can encapsulate all the logic required for pre-constructing fully initialized instances, so they can be used
		for moving this additional logic out of constructors. This prevents constructors from performing further tasks, others than just initializing fields

	4) Static factory methods can be controlled-instanced methods, with the Singleton pattern being the most glaring example of this feature
	*/

	static  CreditAccount newOfLimitBalanceOwner(int limit, int balance, Person owner){
		if (balance < 0)
			throw new IllegalArgumentException("balance can't be negative, moron");
		long new_id = getNext_id();
		return new CreditAccount(limit, balance, owner,new_id);
	}

	static  CreditAccount newOfBalanceOwner(int limit, int balance, Person owner){
		if (balance < 0)
			throw new IllegalArgumentException("balance can't be negative, moron");
		long new_id = getNext_id();
		return new CreditAccount(default_limit, balance, owner, new_id);
	}

}