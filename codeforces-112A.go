// https://codeforces.com/problemset/problem/112/A
// A. Petya and Strings

package main

import (
	"fmt"
	"strings"
)

func main() {
	var str1 string
	var str2 string

	fmt.Scan(&str1, &str2)

	str1 = strings.ToLower(str1)
	str2 = strings.ToLower(str2)

	if str1 == str2 {
		fmt.Println(0)
	} else if str1 < str2 {
		fmt.Println(-1)
	} else {
		fmt.Println(1)
	}
}

