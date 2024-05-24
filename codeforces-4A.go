// https://codeforces.com/problemset/problem/4/A
// A. Watermelon

package main

import "fmt"

func main() {
	var i int
	fmt.Scan(&i)
	if i == 2 {
		fmt.Println("NO")
		return
	}
	if i%2 == 0 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

