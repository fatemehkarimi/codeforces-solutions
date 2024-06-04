// https://codeforces.com/problemset/problem/282/A
// Bit++

package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	var result int
	for i := 0; i < n; i++ {
		var command string
		fmt.Scan(&command)

		operation := command[0]
		if operation == 'X' {
			operation = command[1]
		}

		if operation == '+' {
			result += 1
		} else if operation == '-' {
			result -= 1
		}
	}

	fmt.Println(result)
}

