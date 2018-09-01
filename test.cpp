#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define F first
#define S second
#define mk make_pair
#define inf 1e15
#define mini -1e15
#define mod 1000000007
#define all(v) (v).begin(),(v).end()
#define pii pair<int ,int >
#define pll pair<long long int ,long long int>
#define mset(v,x) memset(v,x,sizeof(v))
#define MODSET(d) if ((d) >= MOD) d %= MOD;
#define inp(x) (scanf("%d",&x))
#define inp2(x,y) (scanf("%d%d",&x,&y))
#define inp3(x,y,z) (scanf("%d%d%d",&x,&y,&z))
#define inp4(x,y,z,w) (scanf("%d%d%d%d",&x,&y,&z,&w))
#define inpl(d) scanf("%lld",&d)
#define inpl2(a,b) scanf("%lld%lld",&a,&b)
#define inpl3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define inpl4(a,b,c,d) scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
using namespace std;
//int arr[100005];
//bool vis[100005];
//vector<int >v[100005];
//vector<int >ans;
//set<int >st,st2;
//set<int >::iterator it;
//map<int ,int >mp,mp2,mp3;
//map<int ,int >::iterator it1,it2;
//priority_queue<int, vector<int >, greater<int > >pq;
//bool mysort(const pll &a,const pll &b)
string nid="a";
string gensisnid="a";
int parentnodenumber=0;
string hashfunction(string dt,string hashset,int parnodeno,string nid,string parnodeadd,string childnodeadd,string gensisnodeadd)
{
    int prime=23;
    long long int hasresult=0;
    for(int i=0;i<dt.length();i++)
        hasresult+=dt[i];
    for(int i=0;i<hashset.length();i++)
        hasresult+=hashset[i];             // doing hashing by addding and multiplyng  ascii vlaue and then taking modulus with a prime number and then concatinating all the string and then appending any hashed character at the end
    for(int i=0;i<nid.length();i++)
        hasresult+=nid[i];
    for(int i=0;i<parnodeadd.length();i++)
        hasresult+=parnodeadd[i];
    for(int i=0;i<childnodeadd.length();i++)
        hasresult+=childnodeadd[i];
    for(int i=0;i<gensisnodeadd.length();i++)
        hasresult+=gensisnodeadd[i];
    hasresult*=parnodeno;
    hasresult%prime;
    return dt+hashset+nid+parnodeadd+childnodeadd+gensisnodeadd+(char)hasresult;
}
string hashfunction2(int id,float value,string name)
{
    int prime=23;
    int hashofname=0,hashresult;
    for(int i=0;i<name.length();i++)     // doing hashing by addding and multiplyng  ascii vlaue and then taking modulus with a prime number and then concatinating all the string and then appending any hashed character at the begining of name
        hashofname+=name[i];
    hashresult=(id+(int)value+hashofname)%prime;
    return (name+(char)hashresult);
}
class node
{
public:
    string givetimestamp()
    {
       time_t now = time(0);  // I am taking timestamp as the current time of the system
       char* dt = ctime(&now);
       return dt;
    }
    string  data(int a,float v,string ownername,string hashinfo)
    {
        int owneridofnode=a;
        float value=v;
        string hashset=hashinfo;
        hashset=hashfunction2(owneridofnode,value,ownername);//creating has function using information of data
        return hashset;
    }
    int nodenumber()
    {
       int parnodeno=parentnodenumber+1;
       return parnodeno+1;
    }
    string nodeid()
    {
      nid=nid+'a';
      return nid;
    }
    string referencenodeid(string parnodeid)
    {
        char ch=parnodeid[0];
        return  &ch;
    }
    string childreferencenodeid(string childnodeid)
    {
        char ch2=childnodeid[0];
        return  &ch2;
    }
    string gensisreferencenodeid(string gensisnodeid)
    {
        char ch3=gensisnodeid[0];
        return  &ch3;
    }
    string hashvalue()
    {
      // return hashfunction(givetimestamp(),data(),nodenumber(),nodeid(),referencenodeid(parnodeid),childreferencenodeid(childnodeid),gensisreferencenodeid(gensisnodeid));//creating has functionfor hashvalue
    }
};
int main()
{
    vector<node>v;//creating dynamic list of nodes
    node gensis;
    gensis.givetimestamp();
    gensis.data(30,122.32,"gensis","gensis");
    gensis.nodeid();
    gensis.referencenodeid("NULL");
    gensis.childreferencenodeid("child1");
    gensis.gensisreferencenodeid("gensis");
    gensis.hashvalue();
    v.push_back(gensis);
    node child1;
    child1.givetimestamp();
    child1.data(17,121.32,"child1","child1");
    child1.nodeid();
    child1.referencenodeid("gensis");
    child1.childreferencenodeid("child3");
    child1.gensisreferencenodeid("gensis");
    child1.hashvalue();
    v.push_back(child1);
    node child2;
    child2.givetimestamp();
    child2.data(10,123.32,"child2","child2");
    child2.nodeid();
    child2.referencenodeid("gensis");
    child2.childreferencenodeid("child4");
    child2.gensisreferencenodeid("gensis");
    child2.hashvalue();
    v.push_back(child2);
    //for  further addition of nodes and their values taking input from users
    int x=10;
    float f=123.32;
    int numnodes;
    cin>>numnodes;
    for(int i=1;i<=numnodes;i++)
    {
        x-=3;
        f+=12.21;
        string nodename;
        string parentnodename;
        string gensisname="gensis";
        string childname;
        cin>>nodename>>parentnodename>>childname;
        node child;
        child1.givetimestamp();
        child1.data(x,f,nodename,nodename);
        child1.nodeid();
        child1.referencenodeid("child2");
        child1.childreferencenodeid("NULL");
        child1.gensisreferencenodeid("gensis");
        child1.hashvalue();
    }
}
