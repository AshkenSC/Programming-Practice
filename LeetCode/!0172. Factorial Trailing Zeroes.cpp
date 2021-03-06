/*
0172. Factorial Trailing Zeroes

给定一个整数n，返回其阶乘n!的末尾0的个数。要求在对数级时间复杂度完成。

思路:
1）因数里有多少个0，取决于其因数里有多少个10；
2）而对10=2*5，因此可以进一步考察质因数里有多少个2和5，而10的个数取决于2和5当中较少的那个；
3）再进一步思考，我们考察的是n的阶乘，因此因数由n, n-1, n-2, ..., 2, 1构成。这些数当中，每隔一个就会出现一个偶数，也就会出现一个因数2；而5的倍数则每5个数才出现一次。
4）因此可以得到结论：n！的质因数里，5的个数一定不多于2的个数。问题转化为，求质因数分解后有多少个5；
5）只需要考察从n到1中，末位为5和0的数，他们的质因数所含有的5的个数之和。
6）进一步分析，每个5个数，会出现一个5的倍数；但每个25，又会出现25的倍数，也就是每25个数要额外加一个因数5；以此类推，每125也要额外加一个因数5……
7）因此，问题转化为，求n/5 + n/25 + n/125 + ...
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int zeroCount = 0;
        while (n > 0) {
            zeroCount += n / 5;
            n = n / 5;
        }
        return zeroCount;
    }
};