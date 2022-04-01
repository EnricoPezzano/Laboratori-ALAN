public class AnotherTimerClass {

	private int seconds;// invariant: 0<=seconds<=59
	private int minutes;// invariant: 0<=minutes<=60 && (minutes<60 || seconds==0)

	public boolean isRunning() {
		return this.seconds > 0 || this.minutes > 0;
	}

	public int getTime() {
		return this.seconds + 60 * this.minutes;
	}

	public void tick() {
		if (this.seconds > 0)
			this.seconds--;
		else if (this.minutes > 0) {
			this.minutes--;
			this.seconds = 59;
		}
	}

	public int reset(int minutes) {
		if (minutes < 0 || minutes > 60)
			throw new IllegalArgumentException();
		int prevTime = this.getTime();
		this.minutes = minutes;
		this.seconds = 0;
		return prevTime;
	}

}
