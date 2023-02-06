package com.rlj.strings;

import java.util.Arrays;
import java.util.Scanner;

public class RomanToInteger {
	public static int RomanToInt(String s) {
		int sum = 0, num = 0, prev = 0;

		for (int i = s.length() - 1; i >= 0; i--) {
			switch (s.charAt(i)) {
				case 'I' -> num = 1;
				case 'V' -> num = 5;
				case 'X' -> num = 10;
				case 'L' -> num = 50;
				case 'C' -> num = 100;
				case 'D' -> num = 500;
				case 'M' -> num = 1000;

			}
			if (prev > num)
				sum -= num;
			else
				sum += num;
			prev = num;
		}

		return sum;
	}

	public static void main(String ...args) {
		Scanner scan = new Scanner(System.in);
		while (scan.hasNextLine()) {
			System.out.println(RomanToInt(scan.nextLine()));
		}
		scan.close();
	}
}
