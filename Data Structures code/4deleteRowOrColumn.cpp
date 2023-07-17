#include<bits/stdc++.h>
using namespace std; 
int main(){
    int m,n;
    cout<<"Enter the number of rows and columns you want ";
    cin>>m>>n;
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>a[i][j];
        }
        
    }
    cout<<"Enter 1 for delete row Or 2 for delete column: ";
    string str;
    cin>>str;
    int x;
    if (str == "1")
    {
        cout<<"Enter the row number you want to delete ";
        cin>>x;
        int b[m-1][n];
        for (int i = 0; i < m-1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == x)
                {
                    continue;
                }
                b[i][j] = a[i][j];
            }
        }
        for (int i = 0; i < m-1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<b[i][j]<<" ";
            }
        cout<<endl;
        }
    }else if (str == "2")
    {
        cout<<"Enter the column number you want to delete ";
        cin>>x;
        int b[m][n-1];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n-1; j++)
            {
                if (j == x)
                {
                    continue;
                }
                b[i][j] = a[i][j];
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n-1; j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        } 
    }else{
        cout<<"Error";
    }
    return 0;
}