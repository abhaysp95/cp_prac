package input;

import (
	"bufio"
	"io"
)

func ReadStrings(reader io.Reader) []string {
	scanner := bufio.NewScanner(reader);
	var strings []string;
	for scanner.Scan() {
		strings = append(strings, scanner.Text())
	}

	return strings
}
