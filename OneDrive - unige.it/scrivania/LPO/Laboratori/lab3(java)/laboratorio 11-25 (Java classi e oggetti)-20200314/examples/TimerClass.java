public class TimerClass {
	// private instance variables
	private int time; // in seconds, invariant: 0 <= time <= 3600

	// public instance methods
	public boolean isRunning() { // "this" is the target object of the method
		return this.time > 0;
	}

	public int getTime() { // "this" is the target object of the method
		return this.time;
	}

	public void tick() { // "this" is the target object of the method
		if (this.time > 0)
			this.time--;
	}

	public int reset(int minutes) { // "this" is the target object of the method
		if (minutes < 0 || minutes > 60)
			throw new IllegalArgumentException();
		int prevTime = this.time;
		this.time = minutes * 60;
		return prevTime;
	}
}
