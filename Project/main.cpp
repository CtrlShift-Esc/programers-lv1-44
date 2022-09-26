#include <string>
#include <vector>
using namespace std;

bool isPrime(int lastprime, int n)
{
	if (n < 2 || lastprime > n)
		return false;

	for (int i = lastprime; i < n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int solution(int n) {
	int answer = 0;
	vector<int> nums(n + 1, 0);
	nums[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		if (i % 2 != 0)
			nums[i] = i;
	}
	int lastprime = 2;
	for (int i = 3; i <= n; i++)
	{
		if (!nums[i])
			continue;
		if (isPrime(lastprime, i))
		{
			lastprime = i;
			int start = i * 2;
			for (int j = start; j <= n; j += i)
			{
				nums[j] = 0;
			}
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (nums[i])
			answer++;
	}
	return answer;
}


void main()
{
	//test
	//auto ret = solution(10);
}