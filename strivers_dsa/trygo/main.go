package main

import (
	/* "os"
	"rlj_cp/quty" */
	"bufio"
	"fmt"
	"os"
	"rlj_cp/closures"
	"strconv"
)

func main() {
	/* var tstrings quty.TStrPair;
	tstrings.RotateString(os.Stdin) */

	scanner := bufio.NewScanner(os.Stdin)
	fmt.Print("Enter fib. seq. len: ")
	for scanner.Scan() {
		text, _ := strconv.Atoi(scanner.Text())
		closures.FibonacceSequence(text)
	}
}
