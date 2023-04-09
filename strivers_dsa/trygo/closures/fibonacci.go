package closures

import (
	"fmt"
	"strconv"
	"strings"
)

func fibonacci() func() int {
	counter := 0
	first := 0
	last := 0

	return func() int {
		var res int
		if 0 == counter {
			res = 0
		} else if 1 == counter {
			res = 1
			last = res
		} else {
			res = first + last
			first = last
			last = res
		}

		counter += 1
		return res
	}
}

// Prints the fibonacci sequence of given length
//
// NOTE: results are stored in int, hence too big length will overflow
func FibonacceSequence(count int) {
	f := fibonacci()  // returns a closure
	res := make([]string, 0)
	for i := 0; i < count; i++ {
		res = append(res, strconv.Itoa(f()))
	}
	fmt.Println(strings.Join(res, " "))
}
