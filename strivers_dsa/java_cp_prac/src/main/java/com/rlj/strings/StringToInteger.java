package com.rlj.strings;

import java.util.Scanner;

public class StringToInteger {

	public static void main(String ...args) {
		Scanner scan = new Scanner(System.in);
		while (scan.hasNextLine()) {
			System.out.println(myAtoi(scan.nextLine()));
		}
		scan.close();
		// myAtoi(null);
	}

	public static int myAtoi(String s) {
		int idx = 0, sign = 0, res = 0;
		if (s.length() == 0) return 0;

		while (idx < s.length() && s.charAt(idx) == ' ')
			idx++;
		if (idx < s.length()) {
			if (s.charAt(idx) == '-') {
				sign = -1;
				idx++;
			} else if (s.charAt(idx) == '+') {
				idx++;
			}
		}

		while (idx < s.length() && Character.isDigit(s.charAt(idx))) {
			// 2^31 = 2147483648, so 2^31 - 1 = 2147483647
			if (res > Integer.MAX_VALUE / 10 || (res == Integer.MAX_VALUE / 10 && s.charAt(idx) - '0' > 7)) {
				return sign == 0 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
			}

			res = res * 10 + (s.charAt(idx) - '0');
			idx++;
		}

		return sign == 0 ? res : 0 - res;
	}

	// a little heavy approach and doesn't do digit clamping (for 32 bits only)
	public static int myAtoiHeavy(String s) {
		s = s.trim();

		switch (s.charAt(0)) {
			case '-' -> {
				// do the thing for negative here
				String number = s.substring(1).split("[^0-9]+")[0];  // potential problem in case no number is there in string
				int num = Integer.parseInt(number);

				// take 2's compliment
				int res = 0;
				for (int i = 31; i >= 0; i--) {
					if ((num & (1 << i)) == 0) {  // because first we've to get compliment number
						res |= (1 << i);
					}  // else the bit is already off
				}
				return res + 1;  // 2's compliment complete
			}
			default -> {  // use this case for positive
				if (Character.isDigit(s.charAt(0))) {
					String number = s.split("[^0-9]+")[0];  // potential problem in case no number is there in string
					return Integer.parseInt(number);
				}
				return 0;
			}
		}

		// return Integer.parseInt(s);
	}

	private int simpleTest(String s) {
		int num = -42, mask = 1;

		for (int i = 31; i >= 0; i--) {
			System.out.print((num & (mask << i)) != 0 ? 1 : 0);
		}
		System.out.println();

		num = 42;
		for (int i = 31; i >= 0; i--) {
			System.out.print((num & (mask << i)) != 0 ? 1 : 0);
		}
		System.out.println();

		for (int i = 31; i >= 0; i--) {
			System.out.print((num & (mask << i)));
		}
		System.out.println();
		return 0;
	}

}
