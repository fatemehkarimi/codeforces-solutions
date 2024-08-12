// https://codeforces.com/problemset/problem/236/A
// A. Boy or Girl

package main

import "fmt"

func main() {
	characterSet := map[rune]bool{}
	var name string
	fmt.Scan(&name)

	for _, c := range name {
		characterSet[c] = true
	}

	if len := len(characterSet); len%2 == 0 {
		fmt.Println("CHAT WITH HER!")
	} else {
		fmt.Println("IGNORE HIM!")
	}
}

