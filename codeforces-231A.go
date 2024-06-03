// https://codeforces.com/problemset/problem/231/A
// A. Team

package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	var totalCount int = 0
	for i := 0; i < n; i++ {
		var x int
		var y int
		var z int

		fmt.Scan(&x, &y, &z)
		var result int = 0
		if x == 1 {
			result += 1
		}
		if y == 1 {
			result += 1
		}
		if z == 1 {
			result += 1
		}

		if result >= 2 {
			totalCount += 1
		}
	}

	fmt.Println(totalCount)
}

