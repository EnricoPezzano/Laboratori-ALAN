public class Item {
	private static long nextSN; // next unused serial number
	private int price; // in cents
	public final long serialNumber;

	private static long getNextSN() {
		if (Item.nextSN < 0)
			throw new RuntimeException("No more serial numbers!");
		return Item.nextSN++;
	}

	public Item(int price) {
		if (price < 0)
			throw new IllegalArgumentException();
		this.price = price;
		this.serialNumber = Item.getNextSN();
	}

	public int getPrice() {
		return this.price;
	}

}
