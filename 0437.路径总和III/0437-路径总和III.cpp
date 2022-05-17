/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        if(!root) return res;
        if(root->val == sum) res++;
        
        //��root�ڵ��޹ص�
        res += pathSum(root->left,sum);
        res += pathSum(root->right,sum);

        //��root�йصģ����ﲻ��ֱ�ӵ���pathSum,����ݹ��Ժ���ɡ��Ͽ���·����
        res += pathSum_nroot(root->left,  sum - root->val);
        res += pathSum_nroot(root->right, sum - root->val);


        return res;
    }

    int pathSum_nroot(TreeNode* root, int sum) {   //�������ֻ�Ұ���root��·��
        if(!root) return 0;
        int res = 0;
        if(root->val == sum) res++;
        res += pathSum_nroot(root->left,sum - root->val); //�Եݹ�
        res += pathSum_nroot(root->right,sum - root->val);
        return res;
    }


};