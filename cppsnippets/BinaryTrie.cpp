class Node{
public:
       int c;
       bool isLeaf;
       Node* children[2];
};
Node *getNode(int c)
{
         Node *node=new Node();
         node->c=c;
         node->isLeaf=false;
         for(int i=0;i<2;i++)
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
        root=getNode(2);
    }
    static Node *getroot(Trie &trie)
    {
        return trie.root;
    }
};
int calculate(vector<int>& nums,Trie &trie)
{   //Building trie
    for(int i=0;i<nums.size();i++)
    {
         Node *cur=trie.getroot(trie);
         for(int j=31;j>=0;j--)
         {
                int x;
                if(nums[i]&(1<<j))
                    x=1;
                else
                    x=0;
                if(cur->children[x]==NULL)
                {
                    cur->children[x]=getNode(x);
                }
                cur=cur->children[x];
         }
         cur->isLeaf=true;
    } 
    //Finding answer
    int ans=0;
    for(int i=0;i<nums.size();i++)
    {
            Node *cur=trie.getroot(trie);
            int res=0;
            for(int j=31;j>=0;j--)
            {
                int x;
                if(nums[i]&(1<<j))
                    x=1;
                else
                    x=0;
                if(cur->children[x^1])
                {
                    res=(res|(1<<j));
                    cur=cur->children[x^1];
                }
                else
                    cur=cur->children[x];
            }
            ans=max(ans,res);
     }
     return ans;                                                                                          
} 