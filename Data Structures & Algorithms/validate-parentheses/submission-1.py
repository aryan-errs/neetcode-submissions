class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        for c in s:
            if c == '[' or c == '{' or c == '(':
                st.append(c)
                continue
            if not st:
                return False
            top = st.pop()
            if (c == ']' and top != '[' or c == '}' and top != '{' or c == ')' and top != '('):
                return False
        if st:
            return False
        return True