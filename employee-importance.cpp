/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        for (Employee* e: employees) {
            if (e->id == id) {
                int s = 0;
                for (int subordinate: e->subordinates) {
                    s += getImportance(employees, subordinate);
                }
                return s + e->importance;
            }
        }
        return 0; // Never reached.
    }
};