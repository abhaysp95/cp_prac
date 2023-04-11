package main

import (
	"rlj_cp/concurrency"
)

func main() {
	/* var tstrings quty.TStrPair;
	tstrings.RotateString(os.Stdin) */

	/* scanner := bufio.NewScanner(os.Stdin)
	fmt.Print("Enter fib. seq. len: ")
	for scanner.Scan() {
		text, _ := strconv.Atoi(scanner.Text())
		closures.FibonacceSequence(text)
	} */


	concurrency.TreeExecutor()
}
