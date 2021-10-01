vector<int> p, i;
    int ind;
    unordered_map<int,int> m;
    
    TreeNode *construct(int l, int r)
    {
        if(l>r)
            return NULL;
        
        int num = p[ind];
        TreeNode *temp = new TreeNode(num);
        ind++;
        
        temp->left = construct(l, m[num]-1);
        temp->right = construct(m[num]+1, r);
        
        return temp;
    }
    
    TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
        
        m.clear();
        p.assign(preorder.begin(), preorder.end());
        i.assign(inorder.begin(), inorder.end());
        
        int n = i.size();
        
        for(int k=0; k<n; k++)
            m[i[k]]=k;
        
        ind = 0;
        
        return construct(0,n-1);
    }
    
