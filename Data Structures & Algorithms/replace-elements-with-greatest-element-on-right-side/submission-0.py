class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        currGreat = -1
        for i in range(len(arr)-1, -1, -1):
            og = arr[i]
            arr[i] = currGreat
            currGreat = max(currGreat, og)
        return arr