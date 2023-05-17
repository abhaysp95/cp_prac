test = (a) => {
	let num = a.pop()
	if (a.indexOf(num) != -1) {
		a = a.filter(_ => _ != num)
		return test(a)
	}
	return num
}

console.log(test([3, 4, 3, 2, 1, 4, 8, 1, 9, 6, 3]))
