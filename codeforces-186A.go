// https://codeforces.com/problemset/problem/186/A
// A. Comparing Strings

package main

import (
	"fmt"
	"sort"
)

func sort_rune(str []rune) {
	sort.Slice(str, func(i, j int) bool {
		return str[i] < str[j]
	})
}

func main() {
	var (
		str1 string
		str2 string
	)

	fmt.Scan(&str1, &str2)

	if len(str1) != len(str2) {
		fmt.Println("NO")
		return
	}

	tmp1 := []rune(str1)
	tmp2 := []rune(str2)

	diff := 0
	for idx := range tmp1 {
		if tmp1[idx] != tmp2[idx] {
			diff += 1
		}
	}

	sort_rune(tmp1)
	sort_rune(tmp2)

	for idx := range tmp1 {
		if tmp1[idx] != tmp2[idx] {
			fmt.Println("NO")
			return
		}
	}

	if diff == 2 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

