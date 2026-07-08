func checkSubarraySum(nums []int, k int) bool {
	mp := map[int]int{}
	sum := 0
	mp[0] = -1
	for i, num := range nums {
		sum += num
		if val, ok := mp[sum % k]; ok {
			if i - val >= 2 {
				return true
			}
		} else {
			mp[sum % k] = i
		}
	}
	return false
}
