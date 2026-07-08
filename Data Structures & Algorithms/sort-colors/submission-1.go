func sortColors(nums []int) {
    i, j, k := 0, 0, len(nums)-1
	for j <= k {
		if nums[j] == 0 {
			temp := nums[i]
			nums[i] = nums[j]
			nums[j] = temp
			i += 1;
			if i-1 == j {
				j += 1
			}
		} else if nums[j] == 2 {
			temp := nums[k]
			nums[k] = nums[j]
			nums[j] = temp
			k -= 1
		} else {
			j += 1
		}
	}
}
