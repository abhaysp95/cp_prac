package concurrency

import (
	"fmt"
	"math/rand"
)

type Tree struct {
	Left  *Tree
	Value int
	Right *Tree
}

func New(k int) *Tree {
	var t *Tree

	for _, v := range rand.Perm(10) {
		t = insert(t, (1+v)*k)
	}

	return t
}

func insert(t *Tree, v int) *Tree {
	if t == nil {
		return &Tree{nil, v, nil}
	}

	if v < t.Value {
		t.Left = insert(t.Left, v)
	} else {
		t.Right = insert(t.Right, v)
	}

	return t
}

func Walk(t *Tree, ch chan int) {
	walkRecursively(t, ch)
	close(ch)
}

func walkRecursively(t *Tree, ch chan int) {
	if nil == t {
		return
	}

	walkRecursively(t.Left, ch)
	ch <- t.Value
	walkRecursively(t.Right, ch)
}

func Same(t1, t2 *Tree) bool {
	ch1 := make(chan int)
	go Walk(t1, ch1)
	ch2 := make(chan int)
	go Walk(t2, ch2)

	for n := range ch1 {
		if n != <-ch2 {
			return false
		}
	}

	return true
}

func TreeExecutor() {
	tree := New(10)
	ch := make(chan int)

	go Walk(tree, ch)

	for v := range ch {
		fmt.Println(v)
	}

	fmt.Println(Same(New(10), New(10))) // true
	fmt.Println(Same(New(10), New(20))) // false
}

// I think concurrency is not helping here, it's just to show how to do it
