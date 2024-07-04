// https://codeforces.com/problemset/problem/339/A
// A. Helpful Maths

package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var math string
	fmt.Scan(&math)

	numbers := []int{}
	for _, char := range math {
		if strings.ContainsRune("123", char) {
			num, _ := strconv.Atoi(string(char))
			numbers = append(numbers, num)
		}
	}

	sort.Ints(numbers)
	for i := 0; i < len(numbers); i += 1 {
		fmt.Print(numbers[i])
		if i != len(numbers)-1 {
			fmt.Print("+")
		}
	}

	fmt.Print("\n")
}

