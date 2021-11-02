#include <vector>

using namespace std;

class RemovedNumbers
{
public:
    static vector<vector<long long>> removNb(long long n)
    {
        vector<vector<long long>> v;
        long long N = n * (n + 1) / 2;
        for (long long i = 1; i <= n; i++)
        {
            if ((N - i) % (i + 1) == 0)
            {
                long long j = (N - i) / (i + 1);

                if (j <= n)
                {
                    v.push_back({i, j});
                }
            }
        }
        return v;
    }
};
