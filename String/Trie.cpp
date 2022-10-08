#include<bits/stdc++.h>

using namespace std;
using ll = long long;
struct trieNode
{
    bool isEnd;
    trieNode* child[27];

    trieNode()
    {
        isEnd=0;
        for(int i=0; i<27; i++) child[i]=NULL;
    }
};

void Insert(trieNode* root, string &str)
{

    trieNode* curr=root;
    for(int i=0; i<(int)str.size(); i++)
    {
        int ch=str[i]-'a';
        if(curr->child[ch]==NULL)
        {
            curr->child[ch]= new trieNode();
        }
        curr=curr->child[ch];
    }
    curr->isEnd=1;
}
bool Search(trieNode* root, string &str){
    trieNode* curr=root;
    for(int i=0; i<(int)str.size(); i++)
    {
        int ch=str[i]-'a';
        if(curr->child[ch]==NULL)
        {
            return 0;
        }
        curr=curr->child[ch];
    }
    return curr && curr->isEnd;
}

void dfs(trieNode* root,string str){
    trieNode* curr=root;
    if(curr==NULL) return;
    if(curr->isEnd) cout<<str<<endl;
    for(int i=0;i<26;i++){
        if(curr->child[i]!=NULL){
                char c=i+'a';
            str.push_back(c);
            dfs(curr->child[i],str);
            str.pop_back();
        }
    }


}

int main()
{
    trieNode* root=new trieNode();
    string s;
    cin>>s;
    Insert(root,s);
      cin>>s;
    Insert(root,s);
      cin>>s;
    Insert(root,s);
    cin>>s;
    cout<<Search(root,s)<<endl;
    string str="";
    dfs(root,str);

}
