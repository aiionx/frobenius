
// Sebastian Böcker & Zsuzsanna Lipták

import java.util.Arrays;

public class FrobeniusNums {
    public static void main(String[] args) {
        int[] mcNug = [4, 6, 9, 20];
        System.out.println(frobenius(mcNug));
    }

    static int frobenius(int[] nums) {
        int[] ns = new int[nums[0]];
        Arrays.fill(ns, -1);
        ns[0] = 0;
        for (int i = 1; i < nums.length; i++) {
            int d = gcd(nums[0], nums[i]);
            for (int r = 0; r < d; r++) {
                int n = -1;
                if (r == 0)
                    n = 0;
                else {
                    int q = r;
                    while (q < nums[0]) {
                        if (ns[q] != -1 && (ns[q] < n || n == -1))
                            n = ns[q];
                        q += d;
                    }
                }
                if (n != -1)
                    for (int j = 0; j < nums[0] / d; j++) {
                        n += nums[i];
                        int p = n % nums[0];
                        if (ns[p] != -1 && (ns[p] < n || n == -1))
                            n = ns[p];
                        ns[p] = n;
                    }
            }
        }
        int max = 0;
        for (int i = 0; i < nums[0]; i++)
            if (ns[i] == -1 || ns[i] > max)
                max = ns[i];
        if (max == -1) return -1;
        return max - nums[0];
    }

    static int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
}
