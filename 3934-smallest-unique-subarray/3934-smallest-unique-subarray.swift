class Solution {
    func smallestUniqueSubarray(_ nums: [Int]) -> Int {
        let n = nums.count
        let base: Int64 = 233
        let mod1: Int64 = 998244353
        let mod2: Int64 = 1000000007

        var p1 = [Int64](repeating: 1, count: n + 1)
        var p2 = [Int64](repeating: 1, count: n + 1)
        var h1 = [Int64](repeating: 0, count: n + 1)
        var h2 = [Int64](repeating: 0, count: n + 1)

        for i in 0..<n {
            p1[i + 1] = p1[i] * base % mod1
            p2[i + 1] = p2[i] * base % mod2

            h1[i + 1] = (h1[i] * base + Int64(nums[i])) % mod1
            h2[i + 1] = (h2[i] * base + Int64(nums[i])) % mod2
        }

        func check(_ len: Int) -> Bool {
            var freq = [UInt64: Int]()

            for i in 0...(n - len) {
                let a = (h1[i + len] - h1[i] * p1[len] % mod1 + mod1) % mod1
                let b = (h2[i + len] - h2[i] * p2[len] % mod2 + mod2) % mod2

                let key = (UInt64(a) << 32) | UInt64(b)
                freq[key, default: 0] += 1
            }

            return freq.values.contains(1)
        }

        var left = 1
        var right = n

        while left < right {
            let mid = left + (right - left) / 2

            if check(mid) {
                right = mid
            } else {
                left = mid + 1
            }
        }

        return left
    }
}


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna