// https://codeforces.com/problemset/problem/1542/B
// B. Plus and Multiply

package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func main() {
	var t int
	in = bufio.NewReader(os.Stdin)
	fmt.Fscan(in, &t)

	for range t {
		var n, a, b int64
		fmt.Fscan(in, &n)
		fmt.Fscan(in, &a)
		fmt.Fscan(in, &b)

		found := false
		c := int64(1)

		for c <= n {

			if (n-c)%b == 0 {
				found = true
				break
			}

			if a == 1 {
				break
			}
			c *= a
		}

		if found {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

