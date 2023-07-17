// // To implement LRU Page replacement algorithm
#include <bits/stdc++.h>
using namespace std;

int fsize;
int frm[15];
void display();
int main()
{
    int pg[100],valid[15],nPage,i,j,k,l,index,pf=0,temp,flag=0,flag1=0;
    cout << "\n Enter frame size:";
    cin >> fsize;
    cout << "\n Enter number of pages:";
    cin >> nPage;
    for(i=0;i< nPage;i++)
    {
        cout << "\n Enter page"<<i+1<<": ";
        cin >> pg[i];
    }
    for(i=0;i< fsize;i++)
    frm[i]=-1;
    cout << "\n page | \t Frame content ";
    cout << "\n--------------------------------------";

    for(j=0;j< nPage;j++)
    {
    flag=0;
    flag1=0;

    for(i=0;i< fsize;i++)
    {
    if(frm[i]==pg[j])
    {
        flag=1;
        flag1=1;
        break;
    }
    }

    if(flag==0)
    {
    for(i=0;i< fsize;i++)
    {
        if(frm[i]==-1)
        {
        frm[i]=pg[j];
        pf++;
        flag1=1;
        break;
        }
    }
    }
    if(flag1==0)
    {
    for(i=0;i< fsize;i++)
        valid[i]=0;
    for(k=j-1,l=1;l<= fsize-1;k--,l++)
    {
    for(i=0;i< fsize;i++)
        {
    if(frm[i]==pg[k])
        valid[i]=1;
        }
    }


    for(i=0;i< fsize;i++)
    {
        if(valid[i]==0)
        index=i;
    }

    frm[index]=pg[j];
    pf++;
    }
    cout << "\n" <<pg[j];
    display();
    }

    cout << "\n--------------------------------------";
    cout << "\n total page fault: "<<pf;
}

void display()
{
 int i;
 for(i=0;i< fsize;i++)
  cout << "\t "<<frm[i];
}

// #include<bits/stdc++.h>
// using namespace std;
// const int N=100005;

// int n;
// int frame_size;
// int pages[N];

// void lru_page_replacement()
// {
//     unordered_set<int> s;
//     unordered_map<int, int> indexes;

//     int page_faults = 0;
//     for (int i=0; i<n; i++)
//     {

//         if(s.find(pages[i])!=s.end())
//         {
//             cout<<"Reference to page "<<pages[i]<<" did not cause a page fault\n";
//         }
//         else
//         {
//             if (s.size() < frame_size)
//             {
//                 s.insert(pages[i]);
//                 page_faults++;
//             }
//             else
//             {
//                 int lru = INT_MAX, val;
//                 for (auto it : s)
//                 {
//                     if (indexes[it] < lru)
//                     {
//                         lru = indexes[it];
//                         val = it;
//                     }
//                 }
//                 s.erase(val);
//                 s.insert(pages[i]);
//                 page_faults++;
//             }
//             cout<<"Reference to page "<<pages[i]<<" caused a page fault\n";

//         }
//         indexes[pages[i]] = i;
//     }

//     cout<<"\nTotal Page Faults: "<<page_faults;
// }

// int main()
// {
//     cout<<"Number of Frames: ";
//     cin>>frame_size;

//     cout<<"Page Reference Stream Length: ";
//     cin>>n;

//     cout<<"Page Reference Stream:\n";
//     for(int i=0; i<n; i++)
//         cin>>pages[i];
//     lru_page_replacement();
//     return 0;
// }