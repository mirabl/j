class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        int infty = 100000;
        Arrays.fill(dp, infty);
        dp[0] = 0;
        for (int c: coins) {
            for (int i = c; i < amount + 1; i++) {
                dp[i] = Math.min(dp[i], 1 + dp[i - c]);
            }
        }
        return dp[amount] != infty ? dp[amount] : -1;
    }
}
