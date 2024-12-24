#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 500;
int seq[MAX];

struct LDS
{
	int len;
	int cnt;
	int prev[MAX];
	int prevCnt;

	void clear()
	{
		len = 0;
		cnt = 0;
		prevCnt = 0;
	}

	void push(int i)
	{
		prev[prevCnt++] = i;
	}
};

LDS lds[MAX];

int sorted[MAX];
int sortedCnt;

bool indexComp(int left, int right)
{
	return seq[left] < seq[right];
}

/*
1
10 3
2 1 4 3 5 6 7 9 8 0

6 6 5 5 4 3 2 1 1 1	// len : LIS 길이
4 4 2 2 2 2 2 1 1 1	// cnt : i번째부터 가능한 LIS 카운트


maxLen = 6;

*/
int main()
{
	int c;
	scanf("%d", &c);
	while (c-- > 0)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		for (int i=0; i<n; ++i)
		{
			scanf("%d", &seq[i]);
			lds[i].clear();
		}

		int maxLen = 0;
		for (int i=n-1; i>=0; --i)
		{
			int lmax = 0;
			for (int j=n-1; j>i; --j)
			{
				if (seq[i] < seq[j])
					lmax = max(lmax, lds[j].len);
			}
			lds[i].len = lmax + 1;
			maxLen = max(maxLen, lds[i].len);

			for (int j=n-1; j>i; --j)
			{
				if (seq[i] < seq[j] && lds[j].len == lmax)
				{
					lds[i].cnt += lds[j].cnt;
					if (lds[i].cnt < 0)
						lds[i].cnt = INT_MAX;
					lds[i].push(j);
				}
			}

			if (lds[i].cnt == 0)
				lds[i].cnt = 1;
		}

		printf("%d\n", maxLen);
		
		// 가장 길이가 긴놈들을 사전순으로 소팅하기 위해서 넣음
		sortedCnt = 0;
		for (int i=0; i<n; ++i)
		{
			if (lds[i].len == maxLen)
				sorted[sortedCnt++] = i;
		}

		// 출력
		int d = 0;
		for (int i=0; i<maxLen; ++i)
		{
			// 일단 소팅
			sort(sorted, sorted + sortedCnt, indexComp);
			for (int j=0; j<sortedCnt; ++j)
			{
				// 입력된 k와 비교해서 k가 더 작거나 같을 경우, 출력
				int s = sorted[j];
				if (k <= d + lds[s].cnt)
				{
					printf("%d", seq[s]);
					if (i < maxLen - 1)
						printf(" ");   

					sortedCnt = 0;
					for (int p=0; p<lds[s].prevCnt; ++p)
						sorted[sortedCnt++] = lds[s].prev[p];

					break;
				}
				else
					d += lds[s].cnt;
			}
		}

		printf("\n");
	}

	return 0;
}

