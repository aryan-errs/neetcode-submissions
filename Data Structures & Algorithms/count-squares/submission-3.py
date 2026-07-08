class CountSquares:

    def __init__(self):
        self.mp = {}

    def add(self, point: List[int]) -> None:
        x,y = point
        self.mp[(x,y)] = self.mp.get((x,y), 0) + 1;

    def count(self, point: List[int]) -> int:
        ans = 0
        qx, qy = point
        for point in self.mp.keys():
            x, y = point
            if x != qx and y != qy and (x, qy) in self.mp and (qx, y) in self.mp:
                ans += self.mp[(x,qy)] * self.mp[(qx,y)] * self.mp[(x,y)]
        return ans
