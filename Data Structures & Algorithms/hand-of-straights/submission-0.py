class Solution:
    def isNStraightHand(self, hand: List[int], gs: int) -> bool:
        n = len(hand)
        if n % gs != 0:
            return False
        hand.sort()
        mp = {}
        for num in hand:
            mp[num] = 1 + mp.get(num, 0)
        for num in hand:
            reqFreq = mp[num]
            mp[num] = 0
            if reqFreq == 0:
                continue
            for i in range(num+1, num + gs):
                if i not in mp or mp[i] < reqFreq:
                    return False
                mp[i] -= reqFreq
            # print(mp)
        return True
            