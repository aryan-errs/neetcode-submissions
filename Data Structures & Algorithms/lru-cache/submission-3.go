type Node struct {
    key int
    val int
    left *Node
    right *Node
}

type LRUCache struct {
    size int
    mp   map[int]*Node
    mru  *Node
    lru  *Node
}


func Constructor(capacity int) LRUCache {
    cache := LRUCache{
		size: capacity,
		mp:   make(map[int]*Node),
	}
    cache.size = capacity
    cache.mru = &Node{key:0,val:0}
    cache.lru = &Node{key:0,val:0}
    cache.mru.left = cache.lru
    cache.lru.right = cache.mru
    return cache
}

func (this *LRUCache) Get(key int) int {
    i, ok := this.mp[key]
    if ok {
        val := i.val
        this.Remove(i)
        delete(this.mp, key)
        node := this.Add(key, val)
        this.mp[key] = node
        return i.val
    }
    return -1
}


func (this *LRUCache) Put(key int, value int)  {
	if node, ok := this.mp[key]; ok {
        this.Remove(node)
        delete(this.mp, key)
    }

    if len(this.mp) >= this.size {
        lruNode := this.lru.right
        this.Remove(lruNode)
        delete(this.mp, lruNode.key)
    }

    node := this.Add(key, value)
    this.mp[key] = node
}

func (this *LRUCache) Remove(node *Node) {
	node.left.right = node.right
	node.right.left = node.left
}

func (this *LRUCache) Add(key int, val int) *Node {
	node := &Node{key:key, val:val}
	this.mru.left.right = node
	node.left = this.mru.left
	node.right = this.mru
	this.mru.left = node
	return node
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */