package com.rlj.strings;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.stream.Collectors;

public class SortCharactersByFrequency
{
	/* public static String frequencySort(String s)
	{
		Map<Character, Integer> freq = new HashMap<>();
		for (char ch: s.toCharArray()) {
			freq.put(ch, freq.getOrDefault(ch, 0) + 1);
		}

		List<Map.Entry<Character, Integer>> chars = freq.entrySet()
			.stream().sorted(Map.Entry.<Character, Integer>comparingByValue().reversed())
			// .map(e -> e.getKey())
			.collect(Collectors.toList());

		StringBuilder res = new StringBuilder();
		chars.forEach(e ->
				{
					for (int i = 0; i < e.getValue(); i++) {
						res.append(e.getKey());
					}
				});


		return res.toString();
	} */

	public static String frequencySort(String s)
	{
		class Pair {
			char ch;
			int freq;

			Pair(char ch) {
				this.ch = ch;
				this.freq = 0;
			}
		}

		Pair[] pairs = new Pair[123];
		for (int i = 0; i < 123; i++) {
			pairs[i] = new Pair((char)i);
		}

		for (char ch: s.toCharArray()) {
			pairs[ch].freq += 1;
		}

		Arrays.sort(pairs, (p1, p2) -> p2.freq - p1.freq);

		StringBuilder builder = new StringBuilder();
		for (Pair p: pairs) {
			while(p.freq-- > 0) {
				builder.append(p.ch);
			}
		}

		return builder.toString();
	}

	public static void main(String ...args) {
		System.out.println("From SortCharactersByFrequency");
		Scanner scan = new Scanner(System.in);
		try {
			while (scan.hasNext()) {
				System.out.println(SortCharactersByFrequency.frequencySort(scan.nextLine()));
			}
		} finally {
			scan.close();
		}
	}
}
