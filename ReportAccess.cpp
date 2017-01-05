/*
Problem Statement
You are working on a large database that holds information about several different aspects of your company, such as customers, partners, prospects, employees, products, etc. Every user in the system has access to one or more types of data. For instance, a human resources worker might only have access to employee records, while a sales person might have access to prospects, customers, and products.

You are in charge of writing reports that summarize large volumes of this information. However, since the reports may contain more than one type of data, you need to be determine which users should be allowed to view that report. In this case, assume that a user has permission to view a report if and only if they have permission to view all of the types of data contained in that report.

You are given a list of usernames in userNames. You are given a list of what data types each user can access in allowedData, where each element of allowedData is a space-delimited list of the permitted data types for that user. Finally, you are given a reportData, where each element of report indicates a type of data included in the report.

You are to return a indicating the user names of those users who should be able to access the report. The list should be returned in alphabetical order.

Definition
Class: ReportAccess
Method: whoCanSee
Parameters: vector <string>, vector <string>, vector <string>
Returns: vector <string>
Method signature: vector <string> whoCanSee(vector <string> userNames, vector <string> allowedData, vector <string> reportData)
(be sure your method is public)
Limits
Time limit (s): 840.000
Memory limit (MB): 64
Constraints
- userNames will have between 1 and 50 elements, inclusive.
- Each element of userNames will contain between 1 and 50 'a'-'z' characters, inclusive.
- allowedData will contain the same number of elements as userNames.
- Each element of allowedData will contain between 1 and 50 characters, inclusive.
- Each element of allowedData will contain the characters 'a'-'z' or ' '.
- reportData will contain between 1 and 5 elements, inclusive.
- Each element of reportData will contain between 1 and 50 'a'-'z' characters, inclusive.
Examples
0)
{"joe", "nick", "ted"}
{"clients products", "products orders", "clients orders"}
{"clients", "products"}
Returns: {"joe" }
Here, only joe has access to both required data types.
1)
{"kathy", "john", "dan", "steve", "cheryl", "tony"}
{"users data", "data orders", "users permissions", "system users controls", "default", "admin users"}
{"users"}
Returns: {"dan", "kathy", "steve", "tony" }
Here, we only need one type of permission to view the report.
2)
{"jim", "scott", "barbara"}
{"users order products", "products shipping", "tracking products orders"}
{"admin"}
Returns: { }
Everyone has a variety of permissions, but nobody has the proper permission
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <set>
 
using namespace std;
 
class ReportAccess {
public:
	vector <string> whoCanSee(vector <string> userNames, vector <string> allowedData, vector <string> reportData) {
		vector<string> res;
		for (int i = 0; i < int(userNames.size()); ++i) {
			set<string> allowed;
			istringstream iss(allowedData[i]);
			string s;
			while (iss >> s) {
				allowed.insert(s);
			}

			bool ok = true;
			for(vector<string>::iterator it = reportData.begin(); it != reportData.end(); ++it) {
				if (allowed.count(*it) == 0) {
					ok = false;
					break;
				}
			}
			if (ok) {
				res.push_back(userNames[i]);
			}

		}

		// sort
		sort(res.begin(), res.end());
		return res;
	}	

};

int main() {
	ReportAccess r;
	vector<string> v = r.whoCanSee(vector<string>{"joe", "nick", "ted"}, vector<string>{"clients products", "products orders", "clients orders"}, vector<string>{"clients", "products"});
	cout << v.size() << endl;	
}  