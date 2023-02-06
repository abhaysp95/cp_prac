package quty

import (
	"fmt"
	"io"
	"rlj_cp/util/input"
	"strconv"

	// "strconv"
	"strings"
)

type TString struct{
	input string
};

type TStrings struct {
	inputs []string
}

type TStrPair struct {
	str1 string
	str2 string
}

// @param1: Reader interface
//
// @param2: delimeter string (give char only)
func (t *TString)ReverseWords(reader io.Reader, delim string) {
	inputs := input.ReadStrings(reader);

	for _, input := range inputs {
		t.input = input;
		fmt.Println(t.reverse_words("."));
	}
}

// @param1: Reader interface
func (t *TString)LargestOddNumber(reader io.Reader) {
	inputs := input.ReadStrings(reader);

	for _, input := range inputs {
		t.input = input;
		fmt.Println(t.largest_odd_number());
	}
}

// @param1: Reader interface
func (t *TStrings)LargestCommonPrefix(reader io.Reader) {
	t.inputs = input.ReadArrayStrings(reader);
	fmt.Println(t.largest_common_prefix())
}

func (t *TStrPair)IsomorphicStrings(reader io.Reader) {
	pair := input.ReadStringPair(reader);
	t.str1 = pair[0]
	t.str2 = pair[1]
	fmt.Println(t.isomorphic_strings())
}

func (t *TStrPair)RotateString(reader io.Reader) {
	pair := input.ReadStringPair(reader);
	t.str1 = pair[0]
	t.str2 = pair[1]
	fmt.Println(t.rotate_string())
}

// Solution

func (t *TString)reverse_words(delim string) string {
	words := strings.Split(t.input, delim);

	for i, j := 0, len(words) - 1; i < j; i, j = i + 1, j - 1 {
		words[i], words[j] = words[j], words[i];
	}

	return strings.Join(words, delim)
}

func (t *TString)largest_odd_number() string {
	/* str := ""
	for i := range t.input {
		str = t.input[:len(t.input) - i]
		if num, err := strconv.ParseInt(str, 10, 0); err == nil {
			if num % 2 != 0 {
				return str
			}
		}
	} */
	for i := len(t.input) - 1; i >= 0; i-- {
		/* if num, err := strconv.Atoi(string(t.input[i])); err == nil {
			if num % 2 != 0 {
				return t.input[:i + 1]
			}
		} */
		if (t.input[i] - 48) % 2 != 0 {
			return t.input[:i + 1]
		}
	}

	return ""
}

// vertical scanning
func (t *TStrings)largest_common_prefix() string {
	if nil == t.inputs || 0 == len(t.inputs) {
		return ""
	}
	var count int
	for count = 0; count < len(t.inputs[0]); count = count + 1 {
		var char byte;
		char = t.inputs[0][count]
		for sidx := 1; sidx < len(t.inputs); sidx = sidx + 1 {
			if count == len(t.inputs[sidx]) || char != t.inputs[sidx][count] {
				return t.inputs[0][:count]
			}
		}
	}

	return t.inputs[0]
}

/* func (t *TStrPair)isomorphic_strings() bool {
	if len(t.str1) != len(t.str2) {
		return false
	}

	population := make([]int, 26)
	for _, c := range t.str1 {
		population[c - 97]++;
	}

	// i is for population, j is for t.str2
	var count int
	for i, j := 0, 0; j < len(t.str2); j++ {
		if j < len(t.str2) - 1 && t.str2[j] == t.str2[j + 1] {
			count++
		} else {
			count++
			// shift i to first non-zero
			for population[i] == 0 {
				i++
			}
			if count != population[i] {
				return false  // order broken
			}
			count = 0
			i++
		}
	}

	return true
} */

// not correct (will correct later)
func (t *TStrPair)isomorphic_strings() bool {
	fmt.Println(t.str1)
	fmt.Println(t.str2)
	fmt.Println(isomorphic_transform_strings(t.str1))
	fmt.Println(isomorphic_transform_strings(t.str2))
	return len(t.str1) == len(t.str2) &&
		isomorphic_transform_strings(t.str1) == isomorphic_transform_strings(t.str2)
}

func isomorphic_transform_strings(str string) string {
	map1 := make(map[rune]int, len(str))
	builder := strings.Builder{}
	for i, c := range str {
		if _, ok := map1[c]; !ok {
			map1[c] = i
		}
		builder.WriteString(strconv.Itoa(map1[c]))
	}

	return builder.String()
}

func (t *TStrPair)rotate_string() bool {
	compound := t.str1 + t.str1
	return strings.Contains(compound, t.str2)
}
