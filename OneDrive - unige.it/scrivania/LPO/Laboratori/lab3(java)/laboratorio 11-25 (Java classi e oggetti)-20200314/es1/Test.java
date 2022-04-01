
public class Test{
	public static void main(String[] args){
		Person p1 = new Person("Matteo", "Dominoni", 1);
		Person p2 = new Person ("Aa", "Bb", 2);
		assert p1.isSingle();
		assert p2.isSingle();

		Person.join(p1,p2);
		assert !p1.isSingle();
		assert !p2.isSingle();

		String name_p1 = p1.getName();
		String surname_p1 = p1.getSurname();

		String name_p2 = p2.getName();
		String surname_p2 = p2.getSurname();


		System.out.println("Name p1: " + name_p1);
		System.out.println("Surname p1: " + surname_p1);

		System.out.println("Name p2: "+name_p2);
		System.out.println("Surname p2: "+surname_p2);

		Person p3 = new Person("Bojack", "Horseman", 3);

		String name_p3 = p3.getName();
		String surname_p3 = p3.getSurname();

		System.out.println("Name p3: "+name_p3);
		System.out.println("Surname p3: "+surname_p3);

		CreditAccount c1 = new CreditAccount(10, 100, p1, 1);
		c1.deposit(200);
		assert c1.getBalance() == 300;
		c1.withdraw(100);
		assert c1.getBalance() == 200;
		c1.setLimit(20);
		assert c1.getLimit() == 10;
		assert c1.getOwner() == p1;

		CreditAccount c2 = CreditAccount.newOfBalanceOwner(20, 500, p2);
		int balance_c1 = c1.getBalance();
		int balance_c2 = c2.getBalance();

		System.out.println("Balance c1: "+balance_c1);
		System.out.println("Balance p2: "+balance_c2);
		//assert c2.getLimit() == 0;
	}
}
