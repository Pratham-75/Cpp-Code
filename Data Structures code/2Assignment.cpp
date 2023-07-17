#include<iostream>
#include<vector>
#include<new>
#include<string>
using namespace std;
class graph
{
    public:
    int** a;
    bool* visit;
    string* name;
    static int count;
    int n;
    graph(int n)
    {
        this->n=n;
         a=new int*[n];
         visit=new bool[n];
         name=new string[n];
         for(int i=0;i<n;i++)
         {
             visit[i]=false;
             a[i]=new int[n];
             name[i]="";
             for(int j=0;j<n;j++)
             a[i][j]=-1;
         }
    }
    void insert(string key)
    {
        name[count]=key;
        for(int i=0;i<count;i++)
        {

             int diff=0;
            if(name[i].length()==name[count].length())
            {
               
                for(int j=0;j<name[count].length();j++)
                {
                    if(name[i][j]!=name[count][j])
                    diff++;
                }
            }
            if(diff==1)
            {
                
                int j=0;
                while(a[i][j]!=-1)
                {
                    j++;
                }
                a[i][j]=count;
                 j=0;
                while(a[count][j]!=-1)
                {
                    j++;
                }
                a[count][j]=i;
            }
        }

        count++;
    }
     void search(string s1,string s2)
        {
            
            int p,q;
            for(int i=0;i<n;i++)
            {
                if(name[i]==s1)
                p=i;
                else if(name[i]==s2)
                q=i;
            }
            vector<int> arr;
            arr.push_back(p);
            visit[p]=true;
            

            arr=check(p,q,arr);

            for(int i=0;i<arr.size();i++)
            {
                if(arr.size()-1==i)
                cout<<name[arr[i]];
                else
                cout<<name[arr[i]]<<" ---> ";

            }
            
        }
        vector<int> check(int p,int q,vector<int> arr)
        {

            if(p==q)
            {
                return arr;
            }
            for(int i=0;a[p][i]!=-1;i++)
             {
                 if(visit[a[p][i]]==false)
                 {
                arr.push_back(a[p][i]);
                visit[a[p][i]]=true;
    
                arr=check(a[p][i],q,arr);
                if(arr.back()!=q)
                {arr.pop_back();
                visit[a[p][i]]=false;}
                 }
             }
             return arr;
        }
    
};
int graph::count=0;
int main()
{
    graph g(6);
    g.insert("dig");
    g.insert("bog");
    g.insert("big");
    g.insert("foe");
    g.insert("fog");
    g.insert("toe");
    g.search("dig","fog");
    return 0;
}
