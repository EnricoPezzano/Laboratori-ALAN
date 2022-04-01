public class Rectangle {
	   public static final int defaultSize = 1; // final class variable can be public
	   private int width = Rectangle.defaultSize;
	   private int height = Rectangle.defaultSize;

	   private static void checkSize(int size) { // static validation method
	      if (size <= 0)
	         throw new IllegalArgumentException();
	   }
	   public Rectangle(int width, int height) {
	       Rectangle.checkSize(width);
	       Rectangle.checkSize(height);
	       this.width = width;
	       this.height = height;
	   }
	   // static factory method
	   public static Rectangle ofWidthHeight(int width,int height) {
	       return new Rectangle(width, height);
	   }
	}
