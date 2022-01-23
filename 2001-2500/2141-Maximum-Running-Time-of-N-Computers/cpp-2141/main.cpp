/// Source : https://leetcode.com/problems/maximum-running-time-of-n-computers/
/// Author : liuyubobobo
/// Time   : 2022-01-15

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn + nlog(sum/n))
/// Space Complexity: O(1)
class Solution {

public:
    long long maxRunTime(int n, vector<int>& batteries) {

        long long l = 1, r = accumulate(batteries.begin(), batteries.end(), 0ll) / n;
        sort(batteries.begin(), batteries.end(), greater<int>());
        while(l < r){
            long long mid = (l + r + 1) / 2;
            if(ok(n, batteries, mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }

private:
    bool ok(int n, const vector<int>& v, long long t){

        int cnt = 0, i;
        for(i = 0; i < n; i ++){
            if(v[i] >= t) cnt ++;
            else break;
        }

        long long cur = 0;
        for(; i < v.size(); i ++){
            cur += v[i];
            if(cur >= t) cnt ++, cur -= t;
        }
        return cnt >= n;
    }
};


int main() {

    vector<int> battery1 = {3, 3, 3};
    cout << Solution().maxRunTime(2, battery1) << endl;
    // 4

    vector<int> battery2 = {1, 1, 1, 1};
    cout << Solution().maxRunTime(2, battery2) << endl;
    // 2

    vector<int> battery3 = {6251,4133,9898,1536,5475,6340,7430,4413,2558,3941,6934,7326,7948,7736,1408,5752,836,4511,7684,3939,1376,2305,2090,8419,3813,4430,890,4120,3415,9706,879,158,2239,5462,5773,5285,5540,305,2211,691,4335,5912,3542,5229,996,2609,2173,87,5683,2946,1456,9590,3625,1807,6909,1328,1548,8182,1690,7440,8310,8502,320,2654,2254,1306,7696,7187,3977,3270,2989,1629,5725,7937,5317,9763,9238,3712,1925,2,1463,6309,4997,7786,1811,7579,3290,8355,63,5010,3574,5364,748,1877,106,1735,7809,5060,9677,4831,1524,9663,6557,9399,5976,801,8800,4297,9636,4828,3972,6946,6170,9984,5710,3318,4156,7838,6856,2866,5900,4623,5228,8063,2514,9149,3509,4033,854,2884,7160,8195,1936,8134,4277,9442,5263,555,5515,2341,2820,3095,2974,7648,9116,6886,8545,4055,2398,2425,4861,2114,9280,5045,3678,6569,7948,1912,7856,6831,4286,1645,9654,5552,880,1864,6386,6616,3961,7427,8649,2323,8084,7334,8256,6187,2244,9738,6869,5888,3862,886,1419,2067,15,428,4732,2098,7710,5586,1972,5388,5171,9239,4810,2461,3639,8120,5296,9522,3475,5703,2358,1957,9823,6561,3690,1856,8202,1343,1868,5851,3177,7036,4901,4891,4640,5927,7610,9204,3538,7508,411,3814,7545,7094,6841,3125,2884,2205,8271,9920,2322,20,8850,1747,3317,2873,558,7201,6688,9097,9399,2096,5846,9502,5028,2907,1667,4049,5810,5850,4628,4511,2415,1194,6477,9198,6645,1281,3920,7117,3301,1892,4402,8180,2915,3548,211,5855,2190,6552,5992,7280,1291,4064,6139,9585,6729,3481,5274,2498,9484,3486,863,1913,2921,4733,544,62,5139,4408,6174,9175,1119,7858,6215,2901,4862,4020,7371,2778,3086,6559,9187,7591,6007,8762,3577,8984,6653,4975,3939,1385,4076,6350,3248,3102,8331,194,9552,409,1527,6387,8477,5410,3223,1168,6578,4004,3442,1767,5979,8644,4893,8495,5152,5450,2221,7171,8308,6288,8536,5671,6642,6999,4134,5572,3639,884,9915,7104,8288,994,9765,9467,627,2549,2237,713,9487,9727,569,5755,2975,5248,894,3083,7820,7696,4780,952,9787,6791,1939,682,2917,6001,1781,2712,5098,2002,5641,9202,7651,4817,7685,3900,8720,7808,8628,2196,4155,3357,7890,1361,7537,6157,7107,2972,5548,2297,9888,6257,2596,9319,850,2181,2284,6877,9344,1177,2238,5140,6476,6289,2673,3266,5291,3098,541,81,8251,8235,8118,8717,2289,4159,2926,478,9137,3921,2591,669,8164,6245,5742,6076,3839,4243,4656,2448,1168,4481,3734,2909,4499,1479,4204,3693,5440,2921,4044,9615,7430,2716,7520,3354,3683,6058,4212,4940,5645,5101,9339,2422,3201,813,2753,8796,5485,1080,4433,3875,831,33,1689,6643,5753,7352,1670,2525,3606,34,5768,5256,531,427,4931,8174,8413,6014,3464,3793,6932,3943,7916,3954,1452,4165,4047,2844,9685,6882,9535,4995,7836,5296,1140,2403,7723,4388,4791,4967,3788,3694,9258,370,7174,8340,9182,7522,7852,242,1429,5904,7794,7736,2421,3885,819,3136,8815,5737,2043,6398,9528,9011,5056,7761,6120,9561,6053,8264,1648,4598,3448,2563,4717,9078,5032,1163,7788,2227,4478,4172};
    cout << Solution().maxRunTime(13, battery3) << endl;
    // 207113

    vector<int> battery4 = {10, 10, 3, 5};
    cout << Solution().maxRunTime(3, battery4) << endl;
    // 8

    return 0;
}