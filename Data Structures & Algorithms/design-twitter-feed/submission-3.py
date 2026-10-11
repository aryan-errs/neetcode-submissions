class Twitter:

    def __init__(self):
        self.followMap = {}
        self.tweetMap = {}
        self.count = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        if not userId in self.tweetMap:
            self.tweetMap[userId] = []
        self.tweetMap[userId].append((self.count, tweetId))
        self.count += 1
    

    def getNewsFeed(self, userId: int) -> List[int]:
        pq = []
        if userId in self.tweetMap:
            for it in self.tweetMap[userId]:
                heapq.heappush_max(pq,it)
        if userId in self.followMap:
            for follower in self.followMap[userId]:
                for it in self.tweetMap[follower]:
                    heapq.heappush_max(pq,it)
        res = []
        for i in range(10):
            if not pq:
                break
            cnt, tweet = heapq.heappop_max(pq)
            res.append(tweet)
        return res

    def follow(self, followerId: int, followeeId: int) -> None:
        if not followerId in self.followMap:
            self.followMap[followerId] = []
        if followeeId in self.followMap[followerId]:
            return
        self.followMap[followerId].append(followeeId)


    def unfollow(self, followerId: int, followeeId: int) -> None:
        if not followerId in self.followMap:
            return
        if followeeId not in self.followMap[followerId]:
            return
        self.followMap[followerId].remove(followeeId)
