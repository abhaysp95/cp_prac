package main

import (
	"fmt"
	"os"
	"rlj_cp/quty"
)

func main() {
	var tstring quty.TString;
	fmt.Println("--------------");

	/** Strings: Reverse words */
	// tstring.Reverse_words(os.Stdin, ".");
	/** Strings: longest odd in string */
	tstring.Largest_odd_number(os.Stdin);
}
