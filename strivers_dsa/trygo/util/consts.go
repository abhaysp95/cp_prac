package util

const (
	MaxUint = ^uint(0)
	MinUint = uint(0)
	MaxInt = int(MaxUint >> 1)
	MinInt = -MaxInt - 1
)
