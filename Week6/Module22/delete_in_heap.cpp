#include <bits/stdc++.h>
using namespace std;

class my_heap
{
    vector<int> v;

public:
    void insert(int val)
    {
        v.push_back(val);
        int curr_idx = v.size() - 1;
        while (curr_idx > 0)
        {
            int par_idx = (curr_idx - 1) / 2;

            if (v[par_idx] >= v[curr_idx])
            {
                break;
            }

            swap(v[curr_idx], v[par_idx]);
            curr_idx = par_idx;
        }
    }

    int pop()
    {
        if(v.empty()) return -1;
        int val = v[0];
        v[0] = v[v.size() - 1];
        v.pop_back();

        int curr_idx = 0;
        while (true)
        {
            int left_idx = 2 * curr_idx + 1;
            int right_idx = 2 * curr_idx + 2;

            int left = INT_MIN, right = INT_MIN;

            if (left_idx < v.size())
                left = v[left_idx];
            if (right_idx < v.size())
                right = v[right_idx];

            if (v[curr_idx] < left && left >= right)
            {
                swap(v[curr_idx], v[left_idx]);
                curr_idx = left_idx;
            }
            else if (v[curr_idx] < right && right > left)
            {
                swap(v[curr_idx], v[right_idx]);
                curr_idx = right_idx;
            }
            else
            {
                break;
            }
        }
        return val;
    }

    int top() {
        return v[0];
    }
};

int main()
{

    return 0;
}
