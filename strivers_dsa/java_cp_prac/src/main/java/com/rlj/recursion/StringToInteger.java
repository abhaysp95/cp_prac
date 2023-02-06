package com.rlj.recursion;

import java.util.Scanner;

public class StringToInteger {

	public static void main(String ...args) {
		Scanner scan = new Scanner(System.in);
		while (scan.hasNextLine()) {
			String s = scan.nextLine();
			int res = 0;
			printNum(s, 0);
			System.out.println(res);
		}
		scan.close();
	}

	public static int printNum(String s, int idx) {
		if (idx == s.length()) {
			return 0;
		}

		return (s.charAt(idx) - '0') * 10 + printNum(s, idx + 1);
	}

}
