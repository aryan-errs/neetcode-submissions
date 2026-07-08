func subarraySum(nums []int, k int) int {
	mp := make(map[int]int)
	mp[0] = 1
	sum := 0
	cnt := 0
	for _, num := range nums {
		sum += num
		if val, ok := mp[sum-k]; ok {
			cnt += val
		}
		mp[sum] += 1
	}
	return cnt
}
