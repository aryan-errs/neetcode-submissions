class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        n = len(position)
        vec = []
        for i in range(n):
            vec.append((position[i], speed[i]))
        vec.sort(reverse=True)
        stack = []
        for i in range(n):
            x,y = vec[i]
            time = (target-x)/y
            print(time)
            if len(stack) == 0 or time > stack[len(stack)-1]:
                stack.append(time)
        print(stack)
        return len(stack)
        