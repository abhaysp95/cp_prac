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
