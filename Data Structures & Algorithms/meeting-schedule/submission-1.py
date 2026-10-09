"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        arr = []
        for interval in intervals:
            arr.append((interval.start,1))
            arr.append((interval.end,-1))
        arr.sort()
        cnt = 0
        for val in arr:
            cnt += val[1]
            if cnt > 1:
                return False
        print(cnt)
        return cnt == 0