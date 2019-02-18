import com.tinkerforge.IPConnection;
import com.tinkerforge.BrickletRGBLEDV2;

public class ExampleSimple {
	private static final String HOST = "localhost";
	private static final int PORT = 4223;

	// Change XYZ to the UID of your RGB LED Bricklet 2.0
	private static final String UID = "XYZ";

	// Note: To make the example code cleaner we do not handle exceptions. Exceptions
	//       you might normally want to catch are described in the documentation
	public static void main(String args[]) throws Exception {
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletRGBLEDV2 rl = new BrickletRGBLEDV2(UID, ipcon); // Create device object

		ipcon.connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Set light blue color
		rl.setRGBValue(0, 170, 234);

		System.out.println("Press key to exit"); System.in.read();
		ipcon.disconnect();
	}
}
