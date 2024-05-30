// https://codeforces.com/problemset/problem/71/A
// A. Way Too Long Words

package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		var word string
		fmt.Scan(&word)

		if len(word) <= 10 {
			fmt.Println(word)
			continue
		}

		result := string(word[0]) + strconv.Itoa(len(word)-2) + string(word[len(word)-1])
		fmt.Println(result)
	}
}
