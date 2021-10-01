stack<int> st1,st2;
    bool got = false;
    int x, y;
    
    void solve(TreeNode *root, int level, int p, int c)
    {
        if(!root)
            return;
        
        if(!c)
            st1.push(root->val);
        else
            st2.push(root->val);
        
        if(p == root->val)
        {
            if(!c)
                x = level;
            else
                y = level;
            
            got = true;
            return;
        }
        
        solve(root->left, level+1, p, c);
        if(got)
            return;
        
        solve(root->right, level+1, p, c);
        if(got)
            return;
        
        if(!c)
            st1.pop();
        else
            st2.pop();
    }
    
    int Solution::lca(TreeNode* root, int p, int q) {
        x=y=-1;
        
        solve(root,1,p,0);
        if(!got)
            return -1;
        got = false;
        solve(root,1,q,1);
            if(!got)
                return -1;
        
        while(x>y)
        {
            x--;
            st1.pop();
        }
        
        while(y>x)
        {
            y--;
            st2.pop();
        }
        
        while(!st1.empty() && !st2.empty())
        {
            int a= st1.top();
            int b= st2.top();
            
            if(a == b)
                return a;
            
            st1.pop();
            st2.pop();
        }
        
        return -1;
    }
