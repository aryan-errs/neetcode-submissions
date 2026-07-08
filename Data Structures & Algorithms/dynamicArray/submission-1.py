class DynamicArray:
    
    def __init__(self, capacity: int):
        self.cap = capacity
        self.cnt = 0
        self.arr = []

    def get(self, i: int) -> int:
        return self.arr[i]

    def set(self, i: int, n: int) -> None:
        self.arr[i] = n

    def pushback(self, n: int) -> None:
        if self.cnt == self.cap:
            self.resize()
        self.cnt += 1
        self.arr.append(n)

    def popback(self) -> int:
        self.cnt -= 1
        return self.arr.pop()

    def resize(self) -> None:
        self.cap = self.cap * 2

    def getSize(self) -> int:
        return self.cnt
    
    def getCapacity(self) -> int:
        return self.cap