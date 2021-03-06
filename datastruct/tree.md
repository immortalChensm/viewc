### 树  
- 定义  
    树【tree】是n个结点的有限集.  
    n=0为空树，n>1时有一个根结点Root  
    当n>1时，其余结点可以分为m(m>0)个结点的有限集，T1,T2,...它们每个集合也是树，称为根结点的子树   
    【Substree】  
    
    图示  
    ![tree](datastruct/tree1.png)  
- 结点分类   

    ![tree](datastruct/tree_type.png)   
    
    子结点的子树数称为节点的度，节点的度为0则是终端节点或叶节点  
    节点度不为0的分支结点或非终端节点，分支结点也称为内部结点  
    树的度是指树内各结点度的最大值     
    
- 结点间的关系  
    ![tree](datastruct/tree2.png)  
    
- 树的层次  
    ![tree](datastruct/tree3.png)  
    
- 树的存储结构  
    双亲表示法，孩子表示法，孩子兄弟表示法    
    
- 双亲表示法  
    
    ![tree](datastruct/tree4.png)  
    节点结构存在双亲域，长子域，兄弟域    
    
    长子域  
    ![tree](datastruct/tree5.png)   
    
    兄弟域  
    ![tree](datastruct/tree6.png)    
    
    [测试源码](tree1.c)
    
    
- 孩子表示法   
    每个结点有多个指针域，每个指针指向一棵了树的根结点  
    又叫双重链表表示法   
    
    ![tree](datastruct/tree7.png)    
    
    每个结点多出了一个度域+多个指针域，度域个数决定指针域个数
    指针指向每棵子树的根结点  
    ![tree](datastruct/tree8.png)  
    
    ![tree](datastruct/tree9.png)  
    
    树的双亲表示法+孩子表示法   
    ![tree](datastruct/tree10.png)     
    
    [测试源码](tree2.c)  
    
- 孩子兄弟表示    

    ![兄弟表示法](datastruct/tree11.png)   
    
    二叉树  
    ![二叉树](datastruct/tree12.png)  
    
    [treetest](tree3.c)  
    
    折半查找法  
    ![tree](datastruct/tree13.png)  
    
- 二叉树【Binary Tree】  
    由N个结点组成的有限集合，由根结点和两棵互不相交，分别称为根结点的左子树和右子树的二叉树组成   
    
    ![binary_tree](datastruct/binary_tree.png)   
    
   特点：          
   1、每个结点只能最多有两棵子树 
   2、左子树和右子树是有顺序的   
   3、即使树中某个结点只有一棵子树，也要区分左子树和右子树的    
   
   
   基本形态   
   1、空二叉树   
   2、只有一个根结点   
   3、根结点只有左子树  
   4、根结点只有右子树   
   5、根结点有左子树和右子树     
   
   特殊的二叉树  
   1、斜树   
   所有结点只有左子树的称为左斜树  所有结点只有右子树的称为右斜树     
   ![tree](datastruct/tree14.png)  
   2、满二叉树   
   所有结点都有左子树和右子树，并且在同一层上【树的层次】     
   ![tree](datastruct/tree15.png)
   
   3、完全二叉树  
   ![tree](datastruct/tree16.png)  
   
   二叉树的性质     
   1、在二叉树的第i层上有2i-1(i>=1)个结点     
   
   二叉树的顺序存储结构   
   ![tree](datastruct/tree17.png)  
   
   二叉树的链表存储  
   ![tree](datastruct/tree18.png)  
   
   二叉树的定义   
   ![tree](datastruct/tree19.png)  
   
   二叉树的遍历  
   按照某种次序从根结点开始遍历所有结点且只遍历一次   
   
   二叉树的遍历方法   
   1、前序遍历  
   先访问根结点，再遍历左子树，然后再遍历右子树   【根，左，右】    
   遍历图示   
   ![tree](datastruct/tree20.png)  
   
   2、中序遍历  
   从根结点的左子树开始，中序遍历，再访问根结点，再中序遍历右结点   【左，根，右】    
   ![tree](datastruct/tree21.png)  
   
   3、后序遍历   
   先左到右叶结点遍历左右子树，再访问根结点   【左，右，根】  
   ![tree](datastruct/tree22.png)  
   
   4、层序遍历   
   逐层遍历，每层遍历时从左到右方式遍历   
   ![tree](datastruct/tree23.png)   
   
   以上遍历方式目的是连成一条线【线性方式】方便遍历查找      
   
   [二叉树的遍历测试源码](tree8.c)
   
   
   
- 二叉树的建立   
    就是二叉树的每个结点的空指针引出一个虚结点，其值为一个特定值如#，这种处理后的二叉树为原二叉树的   
    扩展二叉树   
    
    ![tree](datastruct/tree25.png)  
- 线索二叉树   
    指向前驱和后继的指针称为线索，加上线索的二叉树链表称为线索链表，相应的二叉树称为线索二叉树  
    【线索二叉树】Threaded Binary Tree  
    
- 树与二叉树的转换   

    1、给兄弟加线   
    2、给除长子外去线   
    3、层次调整  
    
    
    