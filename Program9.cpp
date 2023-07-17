// Implement rate monotonic CPU schedulind algorithm
#include <iostream>
#include<vector>
using namespace std;

struct job {	
	int brusttime;
	int period;
	int count = 0;
	int reminder = 0;
	int finishedCount = 0;
};
void bubblesort_float(job *var, int size)
{
	for (int i = 0; i < size-1; i++) {
		for (int j = i; j < size; j++) {
			if (var[i].period > var[j].period) {
				float tmp = var[i].period;
				var[i].period = var[j].period;
				var[j].period = tmp;
				float tmp2 = var[i].brusttime;
				var[i].brusttime = var[j].brusttime;
				var[j].brusttime = tmp2;
			}
		}
	}
}
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int findlcm(vector<int> arr)
{
	int n = arr.size();
	int ans = arr[0];


	for (int i = 1; i < n; i++)
		ans = (((arr[i] * ans)) / (gcd(arr[i], ans)));

	return ans;
}
void calculate(job* var, int size,int lcm)
{
	for (int time = 0; time < lcm ; time++)
	{
		for (int x = 0; x < size; x++)
		{
			if (var[x].period * var[x].count <= time)
			{
				if ((time - var[x].period * var[x].count ) < var[x].brusttime)
				{
					var[x].reminder++;
				}
			}
		}
		for (int x = 0; x < size; x++)
		{
			if (var[x].reminder > 0)
			{
				var[x].finishedCount++;
				var[x].reminder--;
				if (var[x].finishedCount >= var[x].brusttime)
				{
					var[x].finishedCount = 0;
					var[x].count++;
				}
				x = size + 1;
			}
		}
	}
	int cnt = 0;
	for (int x = 0; x < size; x++)
	{
		
		if ((lcm / var[x].period) <= var[x].count)
		{
			cnt++;
		}
	}
	if (cnt == size)
	{
		cout << "Period\tBurst Time\n";
		for (int x = 0; x < size; x++)
		{
			cout<<var[x].period << "\t  ";
			cout << var[x].brusttime; 
			if ((lcm / var[x].period) <= var[x].count)
			{
				cout << "\t - This process can be completed\n";
			}
			else
			{
				cout << "\t - This process cannot be completed\n";
			}
		}
		cout << "\n-----------------------------------\n\n";
		cout << "set of processes can be completed";
		cout << "\n\n-----------------------------------\n\n";
	}
	else
	{
		cout << "Period\tBurst Time\n";
		for (int x = 0; x < size; x++)
		{
			cout<< var[x].period << "\t  ";
			cout << var[x].brusttime;
			if ((lcm / var[x].period) <= var[x].count)
			{
				cout << "\t - This process can be completed\n";
			}
			else
			{
				cout << "\t - This process cannot be completed\n";
			}
		}
		cout << "\n-----------------------------------\n\n";
		cout << "set of processes cannot be completed\n\n";
		cout << "-----------------------------------\n\n";
	}
}
int main()
{
	int numOfProcess;
	cout << "Enter number of process :";	
	cin >> numOfProcess;
	vector<int> arr;
	job* var = new job[numOfProcess];

	for (int x = 0; x < numOfProcess; x++)
	{
		cout << "Enter process " << x+1 << " period time :";
		cin >> var[x].period;
		arr.push_back(var[x].period);
		
		cout << "Enter process " << x+1 << " Brust time :";
		cin >> var[x].brusttime;
	}
	bubblesort_float(var, numOfProcess);
	int lcmValue= findlcm(arr);
	calculate(var, numOfProcess, lcmValue);
	return 0;
}