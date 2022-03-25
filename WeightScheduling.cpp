#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<int, int>, int> weight_interval;

int m_Compute_Opt(vector<weight_interval> vec, int *M, int *P, int n, int j)
{
    if (j == 0)
        return 0;
    else if (M[j] != 0)
        return M[j];
    else
    {
        M[j] = max((vec.at(j).second + m_Compute_Opt(vec, M, P, n, P[j])), m_Compute_Opt(vec, M, P, n, (j - 1)));
    }

    return M[j];
}

int main()
{
    int n = 8;
    cout << "Number of intervals: " << n << endl;

    int m[n + 1] = {0};
    int p[n + 1] = {0};

    vector<weight_interval> jobs;
    jobs.push_back({{0, 0}, 0});
    jobs.push_back({{0, 3}, 3});
    jobs.push_back({{1, 4}, 2});
    jobs.push_back({{0, 5}, 4});
    jobs.push_back({{3, 6}, 1});
    jobs.push_back({{4, 6}, 2});
    jobs.push_back({{3, 9}, 5});
    jobs.push_back({{5, 10}, 2});
    jobs.push_back({{8, 10}, 1});

    cout << "Start Time\t\tEnd Time\t\tWeight\n";
    for (int i = 1; i <= n; i++)
    {
        cout << "      " << jobs.at(i).first.first << "\t\t\t" << jobs.at(i).first.second
             << "\t\t\t" << jobs.at(i).second << endl;
    }

    sort(jobs.begin(), jobs.end(), [&](weight_interval &a, weight_interval &b)
         { return a.first.second < b.first.second; });

    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (jobs.at(i).first.first >= jobs.at(j).first.second)
            {
                p[i] = j;
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        m[i] = m_Compute_Opt(jobs, m, p, n, i);
    }

    cout << "Maximum Weightof Non-Overlapping Intervals: " << m[n] << endl;
    return 0;
}
