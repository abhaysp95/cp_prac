package lists

import "fmt"

type Node[T Number] struct {
	next *Node[T]
	val T
}

func (n *Node[T]) add_node(num T) {

	if nil == n {
		fmt.Println("if")
		new_node := new(Node[T])
		new_node.val = num
		new_node.next = nil
		n = new_node
		return
	}

	fmt.Println("add node", num)


	new_node := new(Node[T])
	new_node.val = num
	fmt.Printf("new_node %v, %[1]T\n", new_node)
	fmt.Printf("n %v, %[1]T\n", n)
	new_node.next = n
	n = new_node
	fmt.Printf("new_node %v, %[1]T\n", new_node)
	fmt.Printf("n %v, %[1]T\n", n)
	fmt.Println("-------------")
}

func (n *Node[T]) print() {
	if nil == n {
		return
	}

	fmt.Println("print node")

	tn := n
	for nil != tn {
		fmt.Println(tn.val)
		tn = tn.next
	}
}

func ListExecutor() {
	var node Node[int]

	fmt.Printf("%v, %[1]T\n", node)

	for i := 1; i <= 5; i++ {
		node.add_node(i)
	}

	node.print()
}
