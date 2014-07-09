import java.math.BigInteger;

public class BitwiseReverseTest{
	public BitwiseReverseTest() {}
	
	private boolean compareExp(String input, String expect) {
		BitwiseReverse br = new BitwiseReverse(input);
		String reverse = br.getReverse();
		if (reverse.toUpperCase().equals(expect)) {
			System.out.println("The input " + input + " and the result " + reverse + " match.");
			return true;
		} else {
			System.out.println("For input " + input + " the expcted result is " + expect + " but we got " + reverse);
			return false;
		}
	}
	
	public boolean testBR() {
		boolean ret = true;
		ret &= compareExp("0", "0000000000000000");
		ret &= compareExp("FFFFFFFF00000000", "00000000FFFFFFFF");
		ret &= compareExp("1", "8000000000000000");
		ret &= compareExp("0F0F0F0F0F0F0F0F", "F0F0F0F0F0F0F0F0");
		return ret;
	}
}