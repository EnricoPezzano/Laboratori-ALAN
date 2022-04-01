package lab03_11_25;

/*
 * invariant owner!=null && id>=0 && balance>=limit && (acc1.id==acc2.id)==(acc1==acc2)
 */

public class CreditAccount {
	private static long nextId;
	public static final int default_limit = 0; // in cents

	private int limit; // in cents
	private int balance; // in cents
	public final Person owner;
	public final long id;

	// private auxiliary static methods for validation and identifier generation

	private static Person requireNonNull(Person p) {
		if (p == null)
			throw new NullPointerException();
		return p;
	}

	private static int requirePositive(int amount) {
		if (amount <= 0)
			throw new IllegalArgumentException();
		return amount;
	}

	private static void requireBalanceAboveLimit(int balance, int limit) {
		if (balance < limit)
			throw new IllegalArgumentException();
	}

	private static long nextId() {
		if (CreditAccount.nextId < 0)
			throw new RuntimeException("No more available ids");
		return CreditAccount.nextId++;
	}

	// constructors

	public CreditAccount(int limit, int balance, Person owner) {
		this.balance = CreditAccount.requirePositive(balance);
		CreditAccount.requireBalanceAboveLimit(balance, limit);
		this.limit = limit;
		this.owner = CreditAccount.requireNonNull(owner);
		this.id = CreditAccount.nextId();
	}

	public CreditAccount(int balance, Person owner) {
		this(CreditAccount.default_limit, balance, owner);
	}

	// static factory methods

	public static CreditAccount newOfLimitBalanceOwner(int limit, int balance, Person owner) {
		return new CreditAccount(limit, balance, owner);
	}

	public static CreditAccount newOfBalanceOwner(int balance, Person owner) {
		return new CreditAccount(balance, owner);
	}

	// instance methods

	public int deposit(int amount) { // amount in cents
		return this.balance += CreditAccount.requirePositive(amount);
	}

	public int withdraw(int amount) { // amount in cents		
		int newBalance = this.balance - CreditAccount.requirePositive(amount);
		CreditAccount.requireBalanceAboveLimit(newBalance, this.limit);
		return this.balance = newBalance;
	}

	public int getBalance() {
		return this.balance;
	}

	public int getLimit() {
		return this.limit;
	}

	public void setLimit(int limit) { // setter method
		CreditAccount.requireBalanceAboveLimit(this.balance, limit);
		this.limit = limit;
	}

}
