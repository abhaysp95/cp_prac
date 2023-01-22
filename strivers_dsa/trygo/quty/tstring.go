package quty

import (
	"fmt"
	"io"
	"rlj_cp/util/input"
	"strings"
)

type TString struct{
	input string
};

func (t *TString)Reverse_words(reader io.Reader, delim string) {
	inputs := input.ReadStrings(reader);
	var tstring TString;

	for _, input := range inputs {
		tstring.input = input;
		fmt.Println(tstring.reverse_words_solution("."));
	}
}

func (t *TString)reverse_words_solution(delim string) string {
	words := strings.Split(t.input, delim);

	for i, j := 0, len(words) - 1; i < j; i, j = i + 1, j - 1 {
		words[i], words[j] = words[j], words[i];
	}

	return strings.Join(words, delim)
}
