* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 typedef struct TreeNode tree;
 bool isPalindrome(int *arr,int size){
     int count[10]={0};
     for(int i=0;i<size;i++){
         count[arr[i]]++;
     }
     int odd_count=0;
     for(int i=1;i<10;++i){
         if(count[i]%2==1){
             odd_count++;
         }
     }
     return odd_count <=1;
 }

 void depth_first_search(tree *node,int *path,int depth,int *count){
     if(node==NULL){
         return;
     }
     path[depth]=node->val;

     if(node->left==NULL && node->right==NULL){
         if (isPalindrome(path,depth+1)){
             (*count)++;
         }
 }
 depth_first_search(node->left,path,depth+1,count);
 depth_first_search(node->right,path,depth+1,count);
 }
 int getMaxDepth(struct TreeNode* root) {
    if (!root) {
        return 0;
    }

    int leftDepth = getMaxDepth(root->left);
    int rightDepth = getMaxDepth(root->right);

    return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}



int pseudoPalindromicPaths(tree* root) {
   if (!root) {
        return 0;
    }

    int maxDepth = getMaxDepth(root);
    int *path = (int *)malloc(maxDepth * sizeof(int));

    int count = 0;
    depth_first_search(root, path, 0, &count);

    free(path);

    return count;
    
}