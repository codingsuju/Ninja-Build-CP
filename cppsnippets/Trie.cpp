//Implementation:
class Node{
    public:
       char c;
       bool isWord;
       int Count;
       int terminating;
       Node* children[26];
};
Node *getNode(char c)
        {
         Node *node=new Node();
         node->c=c;
         node->Count=0;
         node->terminating=0;
         node->isWord=false;
         for(int i=0;i<26;i++)
         {
             node->children[i]=NULL;
         }
         return node;
       }
class Trie{
private:
    Node *root;
public:
    Trie()
    {
        root=getNode('\0');
    }
    void insert(string &word)
    {
        Node *curr=root;
        for(int i=0;i<word.size();i++)
        {
            char c=word[i];
            if(curr->children[c-'a']==NULL)
                curr->children[c-'a']=getNode(c);
            curr=curr->children[c-'a'];
            (curr->Count)=(curr->Count)+1;
        }
        curr->terminating=curr->terminating+1;
        curr->isWord=true;
    }
    int search_count(string word)
    {
        Node *curr=root;
        for(int i=0;i<word.size();i++)
        {
           char c=word[i];
           if(curr->children[c-'a']==NULL)
             return 0;
           curr=curr->children[c-'a'];   
        }
        return curr->terminating;
    }
    int prefix_count(string str)
    {
        Node *curr=root;
        for(int i=0;i<str.size();i++)
        {
           char c=str[i];
           if(curr->children[c-'a']==NULL)
             return 0;
           curr=curr->children[c-'a'];   
        }
        return curr->Count;
    }
    void construct_trie(vector<string> & words)
    {
        for(string &word:words)
        {
            insert(word);
        }
    }
    long long int calculate(string &word,string &a,int k)
    {
        long long int ans=0;
        for(int i=0;i<word.size();i++)
        {
           int t=0;
           Node *curr=root;
           for(int j=i;j<word.size();j++)
           {
              char c=word[j];
              if(a[c-'a']=='0')
                t++;
              if(t>k)
                break;
              if(curr->children[c-'a']==NULL){
                  curr->children[c-'a']=getNode(c);
                  ans++;
              }
              curr=curr->children[c-'a'];
              (curr->Count)=(curr->Count)+1;
           }
           curr->terminating=curr->terminating+1;
           curr->isWord=true;
       }
       return ans;
    }
};
//Function call
void solve()
{
   Trie trie;
   string s;
   cin>>s;
   int n=26;
   string a;
   cin>>a;
   int k;
   cin>>k;
   long long int  ans=trie.calculate(s,a,k);
   cout<<ans<<"\n";
}