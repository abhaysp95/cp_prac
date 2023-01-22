package quty

import (
	"fmt"
	"io"
	"rlj_cp/util/input"
	// "strconv"
	"strings"
)

type TString struct{
	input string
};

type TStrings struct {
	inputs []string
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

func (t *TStrings)largest_common_prefix() string {
	breaked := false
	var char byte
	var count int
	for count = 0; ; count = count + 1 {
		if len(t.inputs[0]) <= count {
			break
		}
		char = t.inputs[0][count]  // get from the first string
		for _, str := range t.inputs {
			if len(str) <= count || char != str[count] {
				breaked = true
				break
			}
		}
		if breaked {
			break
		}
	}

	return t.inputs[0][:count]
}
