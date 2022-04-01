public class Person {
	private final String name;
	private final String surname;
	private final long socialSN;
	private Person spouse;
	
	private void matchRegex(String name, String surname){
		assert name.matches("[A-Z][a-z]+( [A-Z][a-z]+)*");
		assert surname.matches("[A-Z][a-z]+( [A-Z][a-z]+)*");

		/*if (!this.name.matches("[A-Z][a-z]+( [A-Z][a-z]+)*") )
			throw new IllegalArgumentException("Nome non coforme alla regex");

		if (!this.surname.matches("[A-Z][a-z]+( [A-Z][a-z]+)*") )
			throw new IllegalArgumentException("Nome non coforme alla regex");
			*/
	}
	
	private void checksocialSN(long socialSN){
		assert socialSN>0;
		/*if (this.socialSN <0) 
			throw new IllegalArgumentException("SocialSN negativo");
			*/
	}

	private void requireValideSocialSN(Person p1, Person p2){
		if(p1.socialSN == p2.socialSN)
			p1=p2;
	}

	public String getName(){
		return this.name;
	}

	public String getSurname(){
		return this.surname;
	}

	public Person getSpouse(){
		/*if(!this.spouse==null)
			return spouse;
		else return null;*/
		return(this.spouse);
	}

	public boolean isSingle(){
		if(this.spouse == null)
			return true;
		else return false;
	}

	public static void join(Person p1, Person p2){
		if(p1.socialSN == p2.socialSN)
			throw new IllegalArgumentException("P1 e P2 sono la stessa persona");

		if (p1.isSingle()==false || p2.isSingle()==false )
			throw new IllegalArgumentException("Can't marry twice");

		p1.spouse = p2;
		p2.spouse = p1;
	}

	public static void divorce(Person p1, Person p2){
		if (!(p1.spouse == p2 && p2.spouse==p1))
			throw new IllegalArgumentException("Non sono sposati");
		p1.spouse = null;
		p2.spouse = null;
	}


	public Person(String name, String surname, long socialSN){
		checksocialSN(socialSN);
		matchRegex(name, surname);
		this.name = name;
		this.surname = surname;
		this.socialSN = socialSN;
		this.spouse = null;
	}


	public Person(String name, String surname, long socialSN, Person spouse){
		this(name,surname,socialSN);
		checksocialSN(socialSN);
		matchRegex(name, surname);
		this.spouse = spouse;
	}

}











