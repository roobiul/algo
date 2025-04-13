#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job
{
    char id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

int main()
{
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);
    cout << "Enter job details (id deadline profit):\n";
    for (int i = 0; i < n; i++)
    {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = 0;
    for (auto job : jobs)
        maxDeadline = max(maxDeadline, job.deadline);

    vector<char> result(maxDeadline, '-');
    vector<bool> slot(maxDeadline, false);

    for (auto job : jobs)
    {
        for (int j = job.deadline - 1; j >= 0; j--)
        {
            if (!slot[j])
            {
                slot[j] = true;
                result[j] = job.id;
                break;
            }
        }
    }

    cout << "\nScheduled Jobs: ";
    for (char c : result)
        if (c != '-')
            cout << c << " ";
    cout << endl;

    return 0;
}
