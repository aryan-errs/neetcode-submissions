class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        st = []
        result = [-1] * n
        for i in range(n):
            while st and temperatures[st[-1]] < temperatures[i]:
                result[st[-1]] = i - st[-1]
                st.pop()
            if not st or temperatures[st[-1]] >= temperatures[i]:
                st.append(i)    
        for i in range(n):
            if result[i] == -1:
                result[i] = 0
        return result    