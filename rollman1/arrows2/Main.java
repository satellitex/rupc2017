import java.util.Scanner;
import java.lang.Math;

public class Main {
    public static void main(String[] args) {
	Scanner in = new Scanner(System.in);
	double x = 0, y = 0;
	for (int i = 0; i < 2; i++) {
	    double th = in.nextDouble();
	    x += Math.cos(Math.toRadians(th));
	    y += Math.sin(Math.toRadians(th));
	}
	System.out.println(Math.toDegrees(Math.atan2(y, x)));
    }
}
