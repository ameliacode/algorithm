#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

//O(n^2)
typedef struct Job {	//Jobs structure
	int Si, Ei, Wi;
}Job;

//Jobs 우선순위 부여 custom-compare 함수
bool cmp(Job job1, Job job2)
{
	if (job1.Si < job2.Si)
		return true;
	else if (job1.Si == job2.Si)
		return job1.Ei < job2.Ei;
	else
		return false;
}

bool working(Job *jobs, int N)
{
	int shift, lastday;

	sort(jobs, jobs + N, cmp);
	lastday = jobs[N - 1].Ei;

	for (int day = 1; day <= lastday; day++) //day count
	{
		sort(jobs, jobs + N, cmp);
		shift = 8;	//로봇이 하루에 일할 수 있는 시간 = 8시간
		for (int i = 0; i < N; i++)
		{
			if (jobs[i].Si == day) //같은 날에 시작하는 모든 jobs 내에서
			{
				if (shift != 0)  //작업이 끝나지 않았다면,
				{
					if (jobs[i].Wi <= 8)
					{
						shift = 8 - jobs[i].Wi;
						jobs[i].Wi = 0;
					}
					else if (jobs[i].Wi > 8)
					{
						jobs[i].Wi -= shift;
						jobs[i].Si++;	//남은 작업물을 다음날에 넘겨주도록 계획
						shift = 0;
					}
				}
				else //작업이 끝났다면, "당일날" 잔여 작업 다음 날에 하도록 계획
				{
					if (jobs[i].Wi != 0) jobs[i].Si++;
				}
			}
		}
	}
	if (jobs[N - 1].Wi == 0) return true;	//만약 모든 일이 끝났다면 true 반환
	else return false;
}

int main() {

	int N, T;
	int start, end, work;
	Job *jobs;
	cin >> T;

	while (T--)
	{
		cin >> N;
		jobs = new Job[N];
		for (int i = 0; i < N; i++)
		{
			cin >> start;
			jobs[i].Si = start;
			cin >> end;
			jobs[i].Ei = end;
			cin >> work;
			jobs[i].Wi = work;
		}
		if (working(jobs, N)) cout << "Yes" << endl;
		else cout << "No" << endl;
		delete jobs;
	}
}//copyright 2019 github @ameliacode