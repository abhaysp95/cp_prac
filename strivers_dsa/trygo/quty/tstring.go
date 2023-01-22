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

// @param1: Reader interface
//
// @param2: delimeter string (give char only)
func (t *TString)Reverse_words(reader io.Reader, delim string) {
	inputs := input.ReadStrings(reader);
	var tstring TString;

	for _, input := range inputs {
		tstring.input = input;
		fmt.Println(tstring.reverse_words_solution("."));
	}
}

// @param1: Reader interface
func (t *TString)Largest_odd_number(reader io.Reader) {
	inputs := input.ReadStrings(reader);
	var tstring TString;

	for _, input := range inputs {
		tstring.input = input;
		fmt.Println(tstring.largest_odd_number_solution());
	}
}

// Solution

func (t *TString)reverse_words_solution(delim string) string {
	words := strings.Split(t.input, delim);

	for i, j := 0, len(words) - 1; i < j; i, j = i + 1, j - 1 {
		words[i], words[j] = words[j], words[i];
	}

	return strings.Join(words, delim)
}

func (t *TString)largest_odd_number_solution() string {
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
