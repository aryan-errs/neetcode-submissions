class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;

        HashMap<Character, Integer> hashMap = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char c1 = s.charAt(i);
            char c2 = t.charAt(i);

            hashMap.put(c1, hashMap.getOrDefault(c1, 0) + 1);
            hashMap.put(c2, hashMap.getOrDefault(c2, 0) - 1);
        }

        for (int count : hashMap.values()) {
            if (count != 0) return false;
        }

        return true;
    }
}
