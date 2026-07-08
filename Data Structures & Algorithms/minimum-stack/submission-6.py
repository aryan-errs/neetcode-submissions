class MinStack:

    def __init__(self):
        self.st = []

    def push(self, val: int) -> None:
        if not self.st:
            self.st.append((val, val))
            return
        minVal = self.st[-1][1]
        self.st.append((val, min(val, minVal)))

    def pop(self) -> None:
        if self.st:
            self.st.pop()

    def top(self) -> int:
        if self.st:
            return self.st[-1][0]
        return -1

    def getMin(self) -> int:
        if self.st:
            return self.st[-1][1]
        return -1