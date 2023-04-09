package lists

import (
	"fmt"
	"golang.org/x/exp/constraints"
)

func reverse[T any](s []T) {
	l := len(s)
	for i := 0; i < l/2; i++ {
		s[i], s[l-i-1] = s[l-i-1], s[i]
	}
}

func forEach[T any](s []T, f func(ele T, i int, s []T)) {
	for i, ele := range s {
		f(ele, i, s)
	}
}

// for map, key type must always satisfy comparable constraint
func keys[K comparable, V any](m map[K]V) []K {
	key := make([]K, len(m))

	i := 0
	for k := range m {
		key[i] = k
		i++
	}

	return key
}

type MyStruct[T any] struct {
	inner T
}

// no new type parameter is allowed in struct methods
func (m *MyStruct[T]) Get() T {
	return m.inner
}

func (m *MyStruct[T]) Set(val T) {
	m.inner = val
}

func ListExecutor() {
	l := []int{1, 2, 3, 4, 5}
	reverse(l)
	fmt.Println(l)

	fmt.Println("finalMin: ", finalMin(10, 20))
}

// type parameter in generic types (generic types can be nested with other types)
type Entries[K, V any] struct {
	Key   K
	Value V
}

func entriesMapToStruct[K comparable, V any](m map[K]V) []*Entries[K, V] {
	entries := make([]*Entries[K, V], len(m))

	i := 0
	for k, v := range m {
		newEntry := new(Entries[K, V])
		newEntry.Key = k
		newEntry.Value = v
		entries[i] = newEntry
		i += 1
	}

	return entries
}

// Go generics are only allowed to perform specific operations listed in an
// interface, this interface is known as constraint

// predefined types in constraints
type Number interface {
	int | int8 | int16 | int32 | int64 | float32 | float64 // resulting interface allows common operations in all union types
}

func Min[T Number](x, y T) T {
	if x < y {
		return x
	}
	return y
}


// type approxiMation

// any type with given underlying type will be supported by this interface
type Number1 interface {
	~int | ~int8 | ~int16 | ~int32 | ~int64 | ~float32 | ~float64
}

type Point int

func Min1[T Number1](x, y T) T {
	if x < y {
		return x
	}
	return y
}

/* func main() {
	x, y := Point(5), Point(2)
	fmt.Println(Min(x, y))
} */

// all predefined types support approx. type (~ operator only works for constraints)
func Min2[T ~int | ~float32 | ~float64](x, y T) T {
	if x < y {
		return x
	}
	return y
}

// Nesting constraints
type Integer interface {
	~int | ~int8 | ~int16 | ~int32 | ~int64
}

type Float interface {
	~float32 | ~float64
}

type Number3 interface {
	Integer | Float
}

func Min3[T Number3](x, y T) T {
	if x < y {
		return x
	}
	return y
}

// there's also constraints package
func finalMin[T constraints.Ordered](x, y T) T {
	if x < y {
		return x
	}
	return y
}

