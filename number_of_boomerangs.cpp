/*
https://leetcode.com/problems/number-of-boomerangs/
447. Number of Boomerangs   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 8453
Total Submissions: 20063
Difficulty: Easy
Contributors: alexander54
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:
Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
alias a='g++ -std=c++11 -g -Wall number_of_boomerangs.cpp && ./a.out'
*/
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int distance(pair<int, int>& p, pair<int, int>& q) {
	return (p.first - q.first) * (p.first - q.first) + (p.second - q.second) * (p.second - q.second);
}

int numberOfBoomerangsN3(const vector<pair<int, int>>& points) {
	int n = (int)points.size();
	int count = 0;
	for (int i = 0; i < n; ++i) {
		pair<int, int> pI = points[i];
		for (int j = 0; j < n; ++j) {
			if (j == i) {
				continue;
			}
			pair<int, int> pJ = points[j];
			int distIJ = distance(pI, pJ);
			for (int k = 0; k < n; ++k) {
				if (k == j || k == i) {
					continue;
				}
				pair<int, int> pK = points[k];
				int distIK = distance(pI, pK);
				if (distIJ == distIK) {
					count++;
				}
			}
		}
	}
	return count;
}

int numberOfBoomerangs(const vector<pair<int, int>>& points) {
	int n = (int)points.size();
	int count = 0;
	for (int i = 0; i < n; ++i) {
		pair<int, int> pI = points[i];
		unordered_map<int, int> H;
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				continue;
			}
			pair<int, int> pJ = points[j];
			int distIJ = distance(pI, pJ);
			if (H.count(distIJ) == 0) {
				H[distIJ] = 0;
			}
			H[distIJ]++;
		}
		for (unordered_map<int, int>::iterator it = H.begin();
			 it != H.end(); ++it) {
			count += it->second * (it->second - 1);
		}
	}
	return count;
}


int main() {
	// vector<pair<int, int> > v{pair<int, int>(1, 0), pair<int, int>(0, 0), pair<int, int>(2, 0)};
	// vector<pair<int, int> > v{pair<int, int>(-5, 0), pair<int, int>(2, 0), pair<int, int>(7, 0)};
vector<pair<int, int> > v{pair<int,int>(3327,-549), pair<int,int>(9196,-8118), pair<int,int>(7610,-9506), pair<int,int>(5098,8392), pair<int,int>(8582,7953), pair<int,int>(1053,5802), pair<int,int>(3847,2652), pair<int,int>(7654,8355), pair<int,int>(1614,-9409), pair<int,int>(9986,5538), pair<int,int>(4660,2944), pair<int,int>(4528,-9512), pair<int,int>(7483,-1455), pair<int,int>(3422,-3966), pair<int,int>(2037,-4456), pair<int,int>(5107,-4635), pair<int,int>(4996,655), pair<int,int>(7247,2606), pair<int,int>(1149,8697), pair<int,int>(7350,6083), pair<int,int>(3002,8403), pair<int,int>(8238,6850), pair<int,int>(1055,5892), pair<int,int>(5205,9021), pair<int,int>(2835,5191), pair<int,int>(911,-2505), pair<int,int>(4488,-4561), pair<int,int>(7983,-1677), pair<int,int>(336,-2243), pair<int,int>(4358,-1274), pair<int,int>(3302,9465), pair<int,int>(4091,-5350), pair<int,int>(120,7690), pair<int,int>(3608,7622), pair<int,int>(6388,-9042), pair<int,int>(57,-610), pair<int,int>(9361,8295), pair<int,int>(6240,-3232), pair<int,int>(540,7797), pair<int,int>(2141,-6625), pair<int,int>(9341,3053), pair<int,int>(7223,3829), pair<int,int>(4844,1558), pair<int,int>(2152,-8467), pair<int,int>(9316,6510), pair<int,int>(259,-1030), pair<int,int>(2327,-5650), pair<int,int>(9972,8800), pair<int,int>(2040,-6420), pair<int,int>(2774,4780), pair<int,int>(4538,-7169), pair<int,int>(4171,-6101), pair<int,int>(7479,-3237), pair<int,int>(7019,-1981), pair<int,int>(4561,-4488), pair<int,int>(7746,254), pair<int,int>(4917,4969), pair<int,int>(4083,-238), pair<int,int>(6528,-7413), pair<int,int>(1295,-7804), pair<int,int>(5450,-8446), pair<int,int>(1166,-5871), pair<int,int>(2256,-8862), pair<int,int>(2929,-5704), pair<int,int>(4718,2055), pair<int,int>(5429,-4392), pair<int,int>(4887,9600), pair<int,int>(9507,-1282), pair<int,int>(2715,2878), pair<int,int>(6737,-6372), pair<int,int>(8390,-9165), pair<int,int>(3882,3308), pair<int,int>(5805,4317), pair<int,int>(9422,8685), pair<int,int>(3257,-2931), pair<int,int>(881,-1293), pair<int,int>(8623,-1601), pair<int,int>(2836,879), pair<int,int>(5889,2118), pair<int,int>(1527,607), pair<int,int>(4173,-3044), pair<int,int>(6215,5412), pair<int,int>(2908,-7926), pair<int,int>(4130,-8024), pair<int,int>(1304,7219), pair<int,int>(1956,-3954), pair<int,int>(8055,5839), pair<int,int>(5706,212), pair<int,int>(6508,5128), pair<int,int>(8897,9765), pair<int,int>(2197,-3870), pair<int,int>(8472,-2828), pair<int,int>(4529,7661), pair<int,int>(4403,-9582), pair<int,int>(6131,-7717), pair<int,int>(7377,-3344), pair<int,int>(5591,9944), pair<int,int>(2069,-5148), pair<int,int>(8370,-7449), pair<int,int>(6828,-3974), pair<int,int>(6123,-1216), pair<int,int>(2072,530), pair<int,int>(975,-2221), pair<int,int>(7094,-2516), pair<int,int>(9259,-4009), pair<int,int>(7249,7809), pair<int,int>(8473,2074), pair<int,int>(4981,-6998), pair<int,int>(9735,5737), pair<int,int>(9772,5866), pair<int,int>(8020,-6499), pair<int,int>(8874,-6389), pair<int,int>(3445,-9057), pair<int,int>(4815,8167), pair<int,int>(9847,1643), pair<int,int>(4193,2322), pair<int,int>(6780,2617), pair<int,int>(9204,4107), pair<int,int>(396,6298), pair<int,int>(1591,6008), pair<int,int>(2289,-4807), pair<int,int>(3817,762), pair<int,int>(7267,5150), pair<int,int>(116,-6646), pair<int,int>(887,-3760), pair<int,int>(5572,-4741), pair<int,int>(9741,4446), pair<int,int>(5223,-462), pair<int,int>(1742,38), pair<int,int>(7705,1589), pair<int,int>(1682,-1750), pair<int,int>(263,4814), pair<int,int>(867,9467), pair<int,int>(8921,7616), pair<int,int>(5765,-3135), pair<int,int>(3624,4406), pair<int,int>(2058,-2559), pair<int,int>(1520,-675), pair<int,int>(2591,-2012), pair<int,int>(2679,-169), pair<int,int>(4228,-1749), pair<int,int>(5090,-6031), pair<int,int>(2697,-9687), pair<int,int>(9859,791), pair<int,int>(352,3916), pair<int,int>(8732,-1614), pair<int,int>(2166,8995), pair<int,int>(3200,9385), pair<int,int>(4814,-1527), pair<int,int>(7001,579), pair<int,int>(5338,-3023), pair<int,int>(1337,-2604), pair<int,int>(4418,-7143), pair<int,int>(3073,3362), pair<int,int>(845,-7896), pair<int,int>(3193,-8575), pair<int,int>(6707,4635), pair<int,int>(1746,-595), pair<int,int>(4949,1605), pair<int,int>(6548,-8347), pair<int,int>(1873,5281), pair<int,int>(39,-5961), pair<int,int>(4276,-409), pair<int,int>(9777,-909), pair<int,int>(8064,3130), pair<int,int>(6022,-245), pair<int,int>(108,7360), pair<int,int>(7151,4526), pair<int,int>(6569,-3423), pair<int,int>(4240,-2585), pair<int,int>(8681,-2567), pair<int,int>(5192,5389), pair<int,int>(2069,-3061), pair<int,int>(1146,3370), pair<int,int>(4896,7694), pair<int,int>(5023,6770), pair<int,int>(2975,-8586), pair<int,int>(7161,-6396), pair<int,int>(1005,6938), pair<int,int>(2695,-4579), pair<int,int>(69,-4931), pair<int,int>(5176,177), pair<int,int>(2429,-1320), pair<int,int>(1055,8999), pair<int,int>(5257,-4704), pair<int,int>(2766,-6062), pair<int,int>(9081,-2042), pair<int,int>(5679,-2498), pair<int,int>(1249,6825), pair<int,int>(7224,-3854), pair<int,int>(872,2247), pair<int,int>(2916,-6153), pair<int,int>(3661,-9923), pair<int,int>(7451,-8982), pair<int,int>(7016,6498), pair<int,int>(6440,-6563), pair<int,int>(1568,-8384), pair<int,int>(9966,-9651), pair<int,int>(296,1021), pair<int,int>(9348,-8095), pair<int,int>(2669,8466), pair<int,int>(2196,-8249), pair<int,int>(2777,7875), pair<int,int>(5605,4026), pair<int,int>(1053,-7170), pair<int,int>(172,-8075), pair<int,int>(1429,-6912), pair<int,int>(5772,-8557), pair<int,int>(9518,-424), pair<int,int>(2461,2886), pair<int,int>(2426,-1099), pair<int,int>(6323,-6006), pair<int,int>(6870,-3711), pair<int,int>(696,3518), pair<int,int>(3662,6396), pair<int,int>(5424,-3668), pair<int,int>(4863,7620), pair<int,int>(4435,7640), pair<int,int>(1847,-3608), pair<int,int>(8018,-7100), pair<int,int>(9222,-5457), pair<int,int>(4825,7004), pair<int,int>(3983,-3050), pair<int,int>(8447,-6499), pair<int,int>(2878,-9092), pair<int,int>(6387,5304), pair<int,int>(6162,-938), pair<int,int>(5651,3032), pair<int,int>(5351,6347), pair<int,int>(2902,-4634), pair<int,int>(2743,8326), pair<int,int>(8050,-6042), pair<int,int>(2298,-1163), pair<int,int>(7950,-9502), pair<int,int>(5229,-4031), pair<int,int>(3398,-9196), pair<int,int>(512,-5424), pair<int,int>(7808,847), pair<int,int>(7878,6255), pair<int,int>(4349,7108), pair<int,int>(7163,736), pair<int,int>(8764,9677), pair<int,int>(6151,-5585), pair<int,int>(2709,-2146), pair<int,int>(7114,5612), pair<int,int>(3220,-3790), pair<int,int>(290,-8730), pair<int,int>(168,8941), pair<int,int>(107,-5529), pair<int,int>(9439,-8311), pair<int,int>(440,9189), pair<int,int>(2493,7304), pair<int,int>(117,6653), pair<int,int>(8151,-5653), pair<int,int>(2908,8852), pair<int,int>(1455,-3577), pair<int,int>(5941,-3428), pair<int,int>(6101,-7908), pair<int,int>(7339,5162), pair<int,int>(9946,-5546), pair<int,int>(7126,9519), pair<int,int>(7016,3769), pair<int,int>(789,7184), pair<int,int>(2710,-2751), pair<int,int>(1655,-1499), pair<int,int>(5290,-1553), pair<int,int>(4042,-2217), pair<int,int>(2103,-9488), pair<int,int>(788,-3393), pair<int,int>(1211,3696), pair<int,int>(1811,9019), pair<int,int>(6471,-2248), pair<int,int>(5591,8924), pair<int,int>(6196,2930), pair<int,int>(4087,6143), pair<int,int>(3736,7565), pair<int,int>(5662,-9248), pair<int,int>(1334,2803), pair<int,int>(4289,-9604), pair<int,int>(6404,2296), pair<int,int>(8897,-8306), pair<int,int>(7096,-708), pair<int,int>(5829,9199), pair<int,int>(6156,-3383), pair<int,int>(2158,-2633), pair<int,int>(6665,-9678), pair<int,int>(6386,3137), pair<int,int>(8074,1977), pair<int,int>(2061,4271), pair<int,int>(4908,-7500), pair<int,int>(6766,4996), pair<int,int>(66,8780), pair<int,int>(5749,1400), pair<int,int>(7935,38), pair<int,int>(1797,-5660), pair<int,int>(2334,7046), pair<int,int>(2386,9430), pair<int,int>(2690,-1784), pair<int,int>(4982,-1154), pair<int,int>(1185,3492), pair<int,int>(6214,-2149), pair<int,int>(3814,8952), pair<int,int>(7340,8241), pair<int,int>(930,-4247), pair<int,int>(8864,2190), pair<int,int>(8254,5630), pair<int,int>(7186,-5328), pair<int,int>(762,9287), pair<int,int>(6072,8697), pair<int,int>(9325,-5779), pair<int,int>(9389,1660), pair<int,int>(7620,-8224), pair<int,int>(7442,-9690), pair<int,int>(9992,-7576), pair<int,int>(5509,7529), pair<int,int>(2269,8075), pair<int,int>(5380,-3917), pair<int,int>(7027,-7280), pair<int,int>(4324,-5691), pair<int,int>(8474,3188), pair<int,int>(6499,3080), pair<int,int>(5170,-9962), pair<int,int>(7752,5932), pair<int,int>(9325,176), pair<int,int>(982,-1349), pair<int,int>(4398,371), pair<int,int>(6663,-1630), pair<int,int>(2147,-9543), pair<int,int>(5032,8491), pair<int,int>(9234,541), pair<int,int>(6021,1503), pair<int,int>(8616,7753), pair<int,int>(3938,-8004), pair<int,int>(6826,8263), pair<int,int>(6305,-8348), pair<int,int>(7803,9157), pair<int,int>(4732,-674), pair<int,int>(9195,-1164), pair<int,int>(5258,8520), pair<int,int>(9012,2592), pair<int,int>(3523,-238), pair<int,int>(2964,6538), pair<int,int>(8132,1463), pair<int,int>(3348,-6835), pair<int,int>(6307,2582), pair<int,int>(58,-7672), pair<int,int>(437,5027), pair<int,int>(6433,4375), pair<int,int>(7023,3259), pair<int,int>(8990,-6672), pair<int,int>(4911,3146), pair<int,int>(2485,-4005), pair<int,int>(2472,8032), pair<int,int>(4831,-5918), pair<int,int>(2905,196), pair<int,int>(6675,6428), pair<int,int>(9958,9639), pair<int,int>(9319,4443), pair<int,int>(7454,-7333), pair<int,int>(3960,3761), pair<int,int>(1601,-9630), pair<int,int>(2441,2038), pair<int,int>(5397,-1125), pair<int,int>(6413,2420), pair<int,int>(8486,1756), pair<int,int>(2101,3398), pair<int,int>(4902,938), pair<int,int>(5745,-2626), pair<int,int>(5323,-3071), pair<int,int>(1456,8228), pair<int,int>(7125,-1869), pair<int,int>(1008,3435), pair<int,int>(4122,6679), pair<int,int>(4230,1577), pair<int,int>(9346,8190), pair<int,int>(1690,947), pair<int,int>(4913,4132), pair<int,int>(9337,310), pair<int,int>(3007,-4249), pair<int,int>(9083,-8507), pair<int,int>(7507,-2464), pair<int,int>(1243,-7591), pair<int,int>(4826,-3011), pair<int,int>(6135,-9851), pair<int,int>(3918,7591), pair<int,int>(8377,-2605), pair<int,int>(5723,-4262), pair<int,int>(830,-3803), pair<int,int>(2417,-8587), pair<int,int>(7774,8116), pair<int,int>(5955,9465), pair<int,int>(5415,868), pair<int,int>(9949,-5247), pair<int,int>(1179,2956), pair<int,int>(6856,6614), pair<int,int>(801,-9285), pair<int,int>(4150,8397), pair<int,int>(9476,8976), pair<int,int>(1738,-4389), pair<int,int>(9126,2008), pair<int,int>(3202,3855), pair<int,int>(9403,-4723), pair<int,int>(9593,6585), pair<int,int>(1475,-7989), pair<int,int>(7998,-4399), pair<int,int>(127,306), pair<int,int>(1418,-4458), pair<int,int>(1174,1367), pair<int,int>(6647,-7647), pair<int,int>(4323,3503), pair<int,int>(8967,1477), pair<int,int>(4218,9469), pair<int,int>(6226,3694), pair<int,int>(8446,-2036), pair<int,int>(9305,3924), pair<int,int>(9972,8860), pair<int,int>(7779,5727), pair<int,int>(4137,-6275), pair<int,int>(8664,1964), pair<int,int>(5736,-6985), pair<int,int>(7566,-7785), pair<int,int>(3321,8984), pair<int,int>(4109,4495), pair<int,int>(352,757), pair<int,int>(3201,1027), pair<int,int>(4260,-1480), pair<int,int>(8856,4831), pair<int,int>(7990,-4918), pair<int,int>(8525,-7212), pair<int,int>(3046,-5817), pair<int,int>(6712,-630), pair<int,int>(3043,-5509), pair<int,int>(1449,-6468), pair<int,int>(8216,-3534), pair<int,int>(5497,304), pair<int,int>(9481,3063), pair<int,int>(8871,9154), pair<int,int>(8399,2981), pair<int,int>(1,8751), pair<int,int>(90,-6798), pair<int,int>(6131,-9298), pair<int,int>(8075,-5013), pair<int,int>(5533,6065), pair<int,int>(70,-9589), pair<int,int>(5205,9468), pair<int,int>(946,1917), pair<int,int>(5191,-6011), pair<int,int>(2760,-7008), pair<int,int>(3873,7329), pair<int,int>(9458,9370), pair<int,int>(7633,5291), pair<int,int>(8785,2857), pair<int,int>(797,3537), pair<int,int>(2190,-9201), pair<int,int>(2288,-7720), pair<int,int>(353,4771), pair<int,int>(9334,-1572), pair<int,int>(9759,1220), pair<int,int>(845,-3819), pair<int,int>(7983,6050), pair<int,int>(2001,-1071), pair<int,int>(4319,-2808), pair<int,int>(9270,7080), pair<int,int>(6537,3143), pair<int,int>(4409,2347), pair<int,int>(8866,8394), pair<int,int>(7639,4003), pair<int,int>(7603,4788), pair<int,int>(7540,-207), pair<int,int>(5587,6181), pair<int,int>(8425,5941), pair<int,int>(952,-5888), pair<int,int>(721,-2937), pair<int,int>(5332,-8433), pair<int,int>(3244,-6685), pair<int,int>(3969,5246), pair<int,int>(2244,8289), pair<int,int>(8790,-8486), pair<int,int>(1721,-4673), pair<int,int>(1009,-3870), pair<int,int>(7675,9875), pair<int,int>(876,-8334), pair<int,int>(231,-1520), pair<int,int>(6454,7771), pair<int,int>(4625,2042), pair<int,int>(304,9403), pair<int,int>(4335,-8743), pair<int,int>(3515,-4944), pair<int,int>(4672,8847), pair<int,int>(2975,7917), pair<int,int>(8514,6945), pair<int,int>(3163,758), pair<int,int>(1586,1953), pair<int,int>(8624,-6693), pair<int,int>(7281,9633), pair<int,int>(5789,1308), pair<int,int>(5861,-6983), pair<int,int>(2974,-3908), pair<int,int>(7849,-572), pair<int,int>(215,-7525)};
	cout << numberOfBoomerangs(v) << " 2" << endl;

}