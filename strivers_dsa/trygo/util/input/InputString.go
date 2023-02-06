package input

import (
	"bufio"
	"io"
	"strings"
)

func ReadStrings(reader io.Reader) []string {
	scanner := bufio.NewScanner(reader);
	var strings []string;
	for scanner.Scan() {
		strings = append(strings, scanner.Text())
	}

	return strings
}

func ReadArrayStrings(reader io.Reader) []string {
	scanner := bufio.NewScanner(reader);
	scanner.Scan()
	inputArr := scanner.Text()

	inputArr = strings.TrimLeft(inputArr, "[")
	inputArr = strings.TrimRight(inputArr, "]")

	inputs := strings.Split(inputArr, ",")

	return inputs
}

func ReadStringPair(reader io.Reader) []string {
	scanner := bufio.NewScanner(reader);
	pair := make([]string, 0, 2)
	for i := 0; i < cap(pair); i++ {
		scanner.Scan()
		pair = append(pair, scanner.Text())
	}

	return pair
}
