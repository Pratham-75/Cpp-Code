// //Rat in a Maze
// #include<bits/stdc++.h>
// using namespace std;
// bool Safe(int **arr, int x, int y, int n)
// {
//  if (x < n && y < n && arr[x][y] == 1)
//  return true;
//  else
//  return false;
// }
// bool ratInMaze(int **arr, int x, int y, int n, int **solarr)
// {
//  if (x == n - 1 && y == n - 1)
//  {
//  solarr[x][y] = 1;
//  return true;
//  }
//  if (Safe(arr, x, y, n))
//  {
//  solarr[x][y] = 1;
//  if (ratInMaze(arr, x + 1, y, n, solarr))
//  return true;
//  if (ratInMaze(arr, x, y + 1, n, solarr))
//  return true;
//  solarr[x][y] = 0;
//  return false;
//  }
//  return false;
// }
// int main()
// {
//  int n;
//  cin >> n;
//  int **arr = new int *[n];
//  for (int i = 0; i < n; i++) 
//  {
//  arr[i] = new int[n];
//  }
//  for (int i = 0; i < n; i++)
//  {
//  for (int j = 0; j < n; j++)
//  {
//  cin >> arr[i][j];
//  }
//  }
//  int **solarr = new int *[n];
//  for (int i = 0; i < n; i++)
//  {
//  solarr[i] = new int[n];
//  for (int j = 0; j < n; j++)
//  {
//  solarr[i][j] = 0;
//  }
//  }
//  cout<<"the Rat will follow the 1's path\n";
//  if (ratInMaze(arr, 0, 0, n, solarr))
//  {
//  for (int i = 0; i < n; i++)
//  {
//  for (int j = 0; j < n; j++)
//  {
//  cout << solarr[i][j] << " ";
//  }
//  cout << endl;
//  }
//  }
//  else{
//  cout<<"sorry! rat doesn't go to the end point. \n";

//  }
//  return 0;
// } 


//iMPLEMENT THE MATCHING NUTS AND BOLTS
#include <bits/stdc++.h>
using namespace std;
int main() 
{
 char nuts[] = {'@', '#', '$', '%', '^', '&', '*', '+'};
 char bolts[] = {'&', '%', '+', '&', '*', '^', '@', '#'};
 int n = sizeof(nuts) / sizeof(nuts[0]);
 unordered_map<char, int> mp;
 for (int i = 0; i < n; i++)
 {
 mp[nuts[i]] = i;
 }
 for (int i = 0; i < n; i++)
 {
 if (mp.find(bolts[i]) != mp.end())
 {
 nuts[i] = bolts[i];
 }
 }
 cout << "\nMatched nuts and volts are: \n";
 for (int i = 0; i < n; i++)
 {
 cout << nuts[i] << " ";
 }
 cout << endl;
 for (int i = 0; i < n; i++)
 {
 cout << bolts[i] << " ";
 }
 cout<<endl<<endl;
 return 0;
}