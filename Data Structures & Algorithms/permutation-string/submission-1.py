class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        m1 = {}
        m2 = {}
        for c in s1:
            m1[c] = 1 + m1.get(c, 0)
        need = len(s1)
        curr = 0
        i = j = 0
        while j < len(s2):
            m2[s2[j]] = 1 + m2.get(s2[j], 0)
            if s2[j] in m1 and m2[s2[j]] <= m1[s2[j]]:
                curr += 1
            if curr == need:
                return True
            print(curr)
            j += 1
            if j - i + 1 > len(s1):
                m2[s2[i]] -= 1
                if s2[i] in m1 and m2[s2[i]] < m1[s2[i]]:
                    curr -= 1
                i += 1
        return need == 0
