#include<stdio.h>
#include<stdlib.h>
// declare the fp,fpout
FILE *fp;
FILE *fpout;
// Declare the global variables
int size = 0;
int array_T1[20000005];   
// Define the structure of the tree node
typedef struct TreeNode{
    int val;
    struct TreeNode *left,*right;
}TreeNode;
// Define the function to create a new tree node
TreeNode *newTreeNode(int val){
    TreeNode *new = malloc(sizeof(TreeNode));
    new->val = val;
    // Initialize the left and right children to NULL
    new->left=new->right=NULL; 
    return new;
}
// Define the function to build a tree
TreeNode *buildTree(int n){
    //used to store the first line
    int *a = malloc(n*sizeof(int));
    //used to store the second line
    int *b = malloc(n*sizeof(int));
    //used to store each tree node
    TreeNode **T = malloc(n*sizeof(TreeNode*)); 
    //used to store the root of the tree
    TreeNode *root = NULL; 
    for(int i=0;i<n;i++){
        // Read the values from the input
        fscanf(fp,"%d %d",&a[i],&b[i]); 
        T[i] = newTreeNode(a[i]); 
        // if b[i] is -1 ,then it's root
        if(b[i] == -1) root = T[i];
    }
    // Connect the nodes
    // according to it's parent node index
    for(int i = 0;i<n;i++){
        if(b[i] != -1){
            /* If the value of the node is less than 
            the value of its parent node, then it is 
            the left child of its parent node*/
            if(T[i]->val < T[b[i]]->val) T[b[i]]->left = T[i];
            // Otherwise, it is the right child of its parent node
            else T[b[i]]->right = T[i];
        }
    }
    // free to avoid error
    free(a); free(b);free(T);
    return root;
}
// printf the tree
// is preOrder
void printTree(TreeNode *T,int isroot){
    if(T == NULL) return;
    if(isroot) fprintf(fpout,"%d",T->val);
    else fprintf(fpout," %d",T->val);
    printTree(T->left,0);
    printTree(T->right,0);
}
// Store data in increasing order
void in_order(TreeNode *T,int arr[]){
    if(T == NULL) return;
    in_order(T->left,arr);
    //store the value of each node in the array
    arr[size++] = T->val; 
    in_order(T->right,arr);
}
int main(int argc,char *argv[]){
    // The basic operation according to the question
    char in[20] = ".\\data\\8.txt";
    char out[20] = ".\\data\\8out.txt";
    // chaning dirs according to the system
     if(argv[1][1] == 'l') in[1]=in[6]=out[1]=out[6]='/';
     in[7] = out[7] = argv[2][1];
    // represent the input and output file
    printf("%s\n",in);
    printf("%s\n",out);
    fp = fopen(in,"r"); //open the input file
    fpout = fopen(out,"w"); //open the output file
    // The main function
    int number_T1,number_T2,n;
    fscanf(fp,"%d",&number_T1);
    // build the tree according to the input
    TreeNode *T1 = buildTree(number_T1);
    fscanf(fp,"%d",&number_T2);
    TreeNode *T2 = buildTree(number_T2);
    fscanf(fp,"%d",&n);
    // Sort the values in T1
    int size_T1 = 0;
    in_order(T1,array_T1);
    // Find the number A from T1 and B from T2 such that A+B=N
    int if_find = 0; // used as a flag
    for(int i = 0;i<number_T1;i++){
        // avoid repetition
        if(i < number_T1 && array_T1[i] == array_T1[i+1]) continue;
        TreeNode *tmp_T2 = T2; 
        while(tmp_T2!=NULL){
            if(array_T1[i]+tmp_T2->val == n){
                // Print the result first
                if(if_find == 0) fprintf(fpout,"true\n");
                // never print ture again
                if_find = 1;
                // output
                fprintf(fpout,"%d = %d + %d\n",
                n,array_T1[i],tmp_T2->val);
                break;
            }
            // A+B < n imply B is small,so try to find in right leaf
            else if(array_T1[i]+tmp_T2->val < n){
                tmp_T2 = tmp_T2->right;
            }
            // A+B > n imply B is too big,so try to find in left leaf
            else tmp_T2 = tmp_T2->left;
        }
    }
    if(if_find == 0) fprintf(fpout,"false\n"); 
    // Print the T1 tree
    printTree(T1,1);
    fprintf(fpout,"\n");
    // Print the T2 tree
    printTree(T2,1);
    return 0;
}