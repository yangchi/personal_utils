import java.math.BigInteger;
import java.util.ArrayList;

public class BitwiseReverse {
	private static final int radix = 16;
	private BigInteger input;
	private BigInteger reverse;
	private byte[] lookupTable = new byte[256];
	
	public BitwiseReverse() {
		input = new BigInteger("0");
		reverse = new BigInteger("0");
	}
	public BitwiseReverse(String input) {
		if (input.length() > 16)
			input = input.substring(0, 16);
		this.input = new BigInteger(input, radix);
		reverse = new BigInteger("0");
		lookupReverse();
	}
	
	private void lookupReverse() {
		byte[] bytes = input.toByteArray();
		int start = 0;
		if (bytes.length > 1 && bytes[0] == 0 && bytes[1] != 0)
			start = 1;
		byte[] paddedbytes = new byte[9];
		for(int index = start; index < bytes.length; index++) {
			int real_pos = 8 - bytes.length + index;
			int unsigned_byte = 0xFF & bytes[index];
			if (lookupTable[unsigned_byte] == 0 && bytes[index] != 0) {
				lookupTable[unsigned_byte] = calculateReverse(bytes[index]);	
			}
			paddedbytes[8 - 1 - real_pos + 1] = lookupTable[unsigned_byte];
		}
		reverse = new BigInteger(paddedbytes);
	}
	
	private byte calculateReverse(byte bits) {
		byte ret = bits;
		ret = (byte)((ret & 0b11110000) >> 4 | (ret & 0b00001111) << 4);
		ret = (byte)((ret & 0b11001100) >> 2 | (ret & 0b00110011) << 2);
		ret = (byte)((ret & 0b10101010) >> 1 | (ret & 0b01010101) << 1);
		return ret;
	}
	
	private String padString(String str) {
		while (str.length() < 16) {
			str = "0" + str;
		}
		return str;
	}
	public String getReverse() {
		String ret = reverse.toString(radix);
		return padString(ret);
	}
	public String getInput() {
		String ret = input.toString(radix);
		return padString(ret);
	}
	public static void main(String args[]) {
		BitwiseReverseTest testCase = new BitwiseReverseTest();
		if(testCase.testBR()) {
			System.out.println("Passed");
		} else {
			System.out.println("Failed");
		}
	}
}
