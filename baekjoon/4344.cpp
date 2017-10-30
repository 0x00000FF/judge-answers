#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);

    unsigned tries;
    cin >> tries;

    for (unsigned i=0; i<tries; ++i)
    {
        std::vector<unsigned> students;
        unsigned sdt_count, avg = 0, overavg_count = 0;

        cin >> sdt_count;
        for (unsigned j = 0; j < sdt_count; ++j) {
            static unsigned input;
            cin >> input;
            avg += input;
            students.push_back(input);
        }

        avg /= sdt_count;
        std::for_each(students.begin(), students.end(), [&overavg_count, &avg](unsigned n) {
            if (n > avg) overavg_count++;
        });

        cout.precision(3);
        cout << fixed;
        cout << overavg_count * 100 / (double) sdt_count << '%' << endl;
    }

    return 0;
}
