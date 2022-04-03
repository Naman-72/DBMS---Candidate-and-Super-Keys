#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void subsetsUtil(vector<int>& A, vector<vector<int> >& res,
                 vector<int>& subset, int index)
{
    res.push_back(subset);
    for (int i = index; i < A.size(); i++) 
    {
        subset.push_back(A[i]);
        subsetsUtil(A, res, subset, i + 1);
        subset.pop_back();
    }
    return;
}

vector<vector<int> > subsets(vector<int>& A)
{
    vector<int> subset;
    vector<vector<int> > res;
 
    // keeps track of current element in vector A;
    int index = 0;
    subsetsUtil(A, res, subset, index);
    return res;
}
 bool checkSubset(vector<int> A, vector<int> B)
{
    // B SUBSET OF A
    map<int,int> C;
    for(int i = 0 ; i< A.size();i++)
    {
        C[A[i]]++;
    }
    for(int i = 0 ; i< B.size();i++)
    {
        if(C.find(B[i])==C.end())
        {
            return false;
        }
    }
    return true;
}
bool checkSuperKey(vector<int> A, vector<vector<int>> L,vector<vector<int>> R, int n)
{
    unordered_set<int> Closure;
    for (int i = 0; i < A.size(); i++)
    {
        Closure.insert(A[i]);
    }
    int t = Closure.size();
    if(Closure.size()==n)
    {
        return true;
    }
    for(int i = 0 ; i<L.size();i++)
    {
        if(checkSubset(A,L[i]))
        {
            for(int j = 0 ; j<R[i].size();j++)
            {
                Closure.insert(R[i][j]);
            }
        }
    }
    vector<int> B;
    for(auto x : Closure)
    {
        B.push_back(x);
    }
    if(Closure.size()==t)
    {
        return false;
    }
    else
    {
        return checkSuperKey(B,L,R,n);
    }
}
vector<int>returnVectorFrom(string s)
{
	vector<int>ret;
	vector<string> vstrings; 
	istringstream iss(s); 
	for(string s; iss >> s; ) 
    	vstrings.push_back(s); 
	int siz=vstrings.size();
	for(int i= 0 ; i<siz;i++)
	{
		int n=stoi(vstrings[i]);
		ret.push_back(n);
	}
	return ret;
}
bool func(vector<int> A,vector<int>B)
{
 return A.size()<B.size();
}
int main()
{
    int n,fd;
    cin>>n>>fd;
    vector<int> N;
    for(int i = 1; i<n+1;i++)
    {
        N.push_back(i);
    }
    vector<vector<int>> res = subsets(N);
    vector<vector<int>> L;
    vector<vector<int>> R;
    int w = 0;
    string s;
    getline(cin,s);
   
    while(fd--)
    {
      getline(cin,s);
      L.push_back(returnVectorFrom(s));
      getline(cin,s);
      R.push_back(returnVectorFrom(s));
    }
    vector<vector<int>> Ans;
    for (int i = 0; i < res.size(); i++) 
    {
        if(checkSuperKey(res[i],L,R,n))
        {
            Ans.push_back(res[i]);
            // for (int j = 0; j < res[i].size(); j++)
            //     cout << res[i][j] << " ";
            // cout << endl;
        }
    }
    sort(Ans.begin(),Ans.end(),func);
    cout<<Ans.size()<<endl;
    for(int i = 0 ; i< Ans.size();i++)
    {
        for(int j = 0 ; j<Ans[i].size();j++)
        {
            cout<<Ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
