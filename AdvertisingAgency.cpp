#include <vector>
using namespace std;

class AdvertisingAgency {
	public:
		int numberOfRejections(vector <int> requests) {
			bool free_billboards[101] = {true};
			for (int i = 1; i < 101; ++i)  {
				free_billboards[i] = true;
			}
			int num_rejections = 0;
			for (int i = 0; i < (int)requests.size(); ++i) {
				if (free_billboards[requests[i]]) {
					free_billboards[requests[i]] = false;
				} else {
					num_rejections++;
				}
			}
			return num_rejections;
		}
};