//
//  main.cpp
//  practice2
//
//  Created by Liang Dong on 5/20/15.
//  Copyright (c) 2015 Liang Dong. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include<stack>
#include<queue>

using namespace std;

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p==NULL&&q==NULL)
        {
            return true;
        }
        else
        {
            if(p==NULL||q==NULL)return false;
            if(p->val!=q->val)return false;
            if(isSameTree(p->left,q->left)&&isSameTree(p->right,q->right))
                return true;
            else
                return false;
        }
        
        
    }
};

class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        int left,right;
        if(root==NULL)return 0;
        else
        {
            left=maxDepth(root->left);
            right=maxDepth(root->right);
            if(left>=right)
                return left+1;
            else
                return right+1;
        }
        
    }
};

class Solution3 {
public:
    int singleNumber(vector<int>& nums) {
        int i;
        int sum=0;
        for(i=0;i<nums.size();i++)
            sum^=nums[i];
        return sum;
        }
};

void testSolution3(){
    Solution3 solution;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(4);
    int tempnum=solution.singleNumber(nums);
    cout<<tempnum<<endl;
}

/**
 * Definition for singly-linked list.
 */
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution5 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> setint;
        ListNode* current,*currentnext;
        current=head;
        if(current==NULL)return NULL;
        currentnext=current->next;
        if(currentnext==NULL)return current;
        setint.insert(current->val);
        while(currentnext!=NULL){
            if(setint.find(currentnext->val) != setint.end())
            {
                current->next=currentnext->next;
                currentnext=currentnext->next;
            }
            else{
                setint.insert(currentnext->val);
                current=current->next;
                currentnext=currentnext->next;
            }
            
        }
        return head;
        
    }
};

void testduplicate()
{
    ListNode* a=new ListNode(1);
    ListNode b(1);
    ListNode c(2),d(3),e(3);
    a->next=&b;
    b.next=&c;
    c.next=&d;
    d.next=&e;
    
    Solution5 solution;
    ListNode* head=solution.deleteDuplicates(a);
    
    ListNode* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val;
        temp=temp->next;
    }
    
}

class Solution6 {
public:
    int maxArea(vector<int>& height) {
        if(height.size()<2)
            return 0;
        int n=(int)height.size();
        int left=0;
        int right=n-1;
        int maxarea=max(height[left],height[right])*(right-left);
        while(left<right)
        {
           
            maxarea=(maxarea>=min(height[left],height[right])*(right-left))?maxarea:max(height[left],height[right])*(right-left);
            if(height[left]>=height[right])
                right--;
            else
                left++;
        }
        return maxarea;
    }
};

void testSolution6()
{
    vector<int> height;
    height.push_back(1);
    height.push_back(9);
    height.push_back(9);
    height.push_back(1);
    height.push_back(1);
    height.push_back(1);
    Solution6 solution;
    int maxaream=solution.maxArea(height);
    cout<<maxaream<<endl;
    
}

class Solution7 {
public:
    int majorityElement(vector<int>& nums) {
        
        if(nums.size()==1)
            return nums[0];
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};

void testSolution7(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(2);
    Solution7 solution;
    int temp=solution.majorityElement(nums);
    cout<<temp<<endl;
}

class Solution8 {
public:
    int titleToNumber(string s) {
        int sum=0;
        for(string::iterator iter=s.begin();iter!=s.end();iter++)
        {
            sum=sum*26+int(*iter-'A')+1;
        }
        return sum;
    }
};

void testtitletoNumber(){
    Solution8 solution;
    int temp=solution.titleToNumber("AB");
    cout<<temp<<endl;
}

class Solution9{
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp1,*temp2;
        temp1=head;
        if(head==NULL)return false;
        if(head->next==NULL)return false;
        temp2=head->next;
        while(temp1!=temp2)
        {
            temp1=temp1->next;
            temp2=temp2->next;
            if(temp1==NULL||temp2==NULL)return false;
            temp2=temp2->next;
            if(temp2==NULL)return false;
        }
        return true;
    }
};

class Solution10 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> sum;
        vector<int> left;
        vector<int> right;
        if(root==NULL)return vector<int>();
        sum.push_back(root->val);
        if(root->left!=NULL)
        {
            left=preorderTraversal(root->left);
            sum.insert(sum.end(),left.begin(),left.end());
        }
        
        if(root->right!=NULL)
        {
            right=preorderTraversal(root->right);
            sum.insert(sum.end(),right.begin(),right.end());
        }
        return sum;
        
    }
};

class Solution10_2{
public:
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> res;
        stack<TreeNode*> mystack;
        if(root==NULL) return res;
        mystack.push(root);
        while(!mystack.empty())
        {
            TreeNode* temp;
            temp=mystack.top();
            mystack.pop();
            res.push_back(temp->val);
            if(temp->right!=NULL)mystack.push(temp->right);
            if(temp->left!=NULL)mystack.push(temp->left);
        }
        return res;
    }
};

class Solution11 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<int> res;
        vector<int> resr;
        stack<TreeNode*> mystack;
        if(root==NULL) return resr;
        mystack.push(root);
        while(!mystack.empty())
        {
            TreeNode* temp;
            temp=mystack.top();
            mystack.pop();
            res.push(temp->val);
            if(temp->left!=NULL)mystack.push(temp->left);
            if(temp->right!=NULL)mystack.push(temp->right);
        }
        while(!res.empty())
        {
            resr.push_back(res.top());
            res.pop();
        }
        return resr;

    }
};

//3Sum
class Solution12 {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > mySum;
        
        vector<int> mytemp;
        mytemp.resize(3);
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                for(int k=j+1;k<nums.size();k++)
                {
                   
                    if((nums[i]+nums[j]+nums[k])==0)
                    {
                        mytemp[0]=nums[i];
                        mytemp[1]=nums[j];
                        mytemp[2]=nums[k];
                        
                        if(mySum.empty())
                        {
                            mySum.push_back(mytemp);
                            
                        }
                        else
                        {
                            int te=int(mySum.size()-1);
                            
                            if(!((mySum[te][0]==mytemp[0])&&(mySum[te][1]==mytemp[1])&&(mySum[te][2]==mytemp[2])))
                                mySum.push_back(mytemp);
                        }

                    }
                }
            }
        }
        
         
        
        return mySum;
    }
};


//Best Time to Buy and Sell Stcok
class Solution_bs {
public:
    int maxProfit(vector<int>& prices) {
        int sum=0;
        if(prices.size()<2)
            return 0;
        
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>prices[i-1])
                sum+=prices[i]-prices[i-1];
            
        }
        return sum;
    }
};


//best time to buy and sell stock one time
class Solution_onetime {
public:
    int maxProfit(vector<int>& prices) {
        int min;
        int maxd=0;
        if(prices.size()<2)
            return 0;
        min=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]<min)
                min=prices[i];
            if((prices[i]-min)>maxd)
                maxd=prices[i]-min;
            
        }
        return maxd;
    }
};

//best time to buy and sell two times
class Solution_bs2 {
public:
    int maxProfit(vector<int>& prices) {
        int min;
        int maxd1=0;
        int maxd2=0;
        int maxd3=0;
        int tempmint,tempmino,tempmax;
        if(prices.size()<2)
            return 0;
        min=prices[0];
        tempmint=0;
        tempmino=0;
        tempmax=0;
        int i;
        for(i=1;i<prices.size();i++)
        {
            if(prices[i]<min)
            {
                min=prices[i];
                tempmint=i;
            }
            if((prices[i]-min)>maxd1)
            {
                maxd1=prices[i]-min;
                tempmax=i;
                tempmino=tempmint;
            }
            
        }
        cout<<tempmino<<','<<tempmax<<endl;
        //cout<<'1'<<endl;
        if(tempmino>1)
        {
            min=prices[0];
        for(i=1;i<tempmino;i++)
        {
            if(prices[i]<min)
            {
                min=prices[i];
               
            }
            if((prices[i]-min)>maxd2)
            {
                maxd2=prices[i]-min;
               
            }
        }
        }
        
      //  cout<<'2'<<endl;
        
    //    cout<<tempmax<<','<<prices.size()-2<<endl;
        if(tempmax<(prices.size()-2))
        {
            min=prices[tempmax+1];
            for(i=tempmax+1;i<prices.size();i++)
            {
            
                if(prices[i]<min)
                {
                    min=prices[i];
                   
                }
                if((prices[i]-min)>maxd3)
                {
                    maxd3=prices[i]-min;
                   
                }
            

            }
        }
        
      
        
        return (maxd2>=maxd3)?(maxd1+maxd2):(maxd1+maxd3);
        
    }
};


class Solution_bsaccurate {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        vector<int> left;
        vector<int> right;
        left.resize(prices.size());
        right.resize(prices.size());
        
        int sumProfit=0;
        int i;
        left[0]=0;
        int min=prices[0];
        int maxd=0;
        int max=prices[prices.size()-1];
        for(i=1;i<prices.size();i++)
        {
            if(prices[i]<min)
                min=prices[i];
            if((prices[i]-min)>maxd)
                maxd=prices[i]-min;
            left[i]=maxd;
        }
        
        maxd=0;
        
        for(i=int(prices.size())-2;i>=0;i--)
        {
            if(prices[i]>max)
                max=prices[i];
            if((max-prices[i])>maxd)
                maxd=max-prices[i];
            right[i]=maxd;
        }
        
        for(i=0;i<int(prices.size());i++)
        {
            if((left[i]+right[i])>sumProfit)
                sumProfit=left[i]+right[i];
        }
        
        return sumProfit;
        
    }
};

void testBuyandSell()
{
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(4);
   
  
    Solution_bsaccurate solution;
    int sum=solution.maxProfit(prices);
    cout<<sum<<endl;
}


class Solution12_nSquare {
public:
    vector< vector<int> > threeSum(vector<int>& num) {
        vector<int> res_m(3);
        vector< vector<int> > res;
        vector<int>::iterator it1,it2,it3,iend;
        
        sort(num.begin(),num.end());
        if(num.size()>=3){
            iend = num.end();
            it1 = num.begin();
            bool f1 = false;
            for ( ;it1!=iend-2;++it1){
                if(f1 && *it1==*(it1-1)) {continue;}
                f1 = true;
                bool f2 = false;
                bool f3 = false;
                it3 = iend-1;
                it2 = it1+1;
                while (it2!=it3){
                    
                    if(f3 && *it3==*(it3+1)) { it3 = it3 -1 ;continue;}
                    if(f2 && *it2==*(it2-1)) { it2 = it2 +1 ;continue;}
                    
                    if (*it1 + *it2 + *it3==0){
                        res_m.at(0)=*it1;
                        res_m.at(1)=*it2;
                        res_m.at(2)=*it3;
                        res.push_back(res_m);
                    }
                    if (*it1 + *it2 + *it3 >0){
                        it3=it3-1;
                        f3 = true;
                        
                    }else{
                        it2=it2+1;
                        f2 = true;
                    }
                    
                }
                
            }
        }
        return res;
    }
};

class Solution12_nSquare_2 {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        vector<int> res_m(3);
        vector< vector<int> > res;
        int i,j,k;
        int nsize=int(nums.size());
        
        sort(nums.begin(),nums.end());
        if(nsize>=3){
            
            i = 0;
            bool f1 = false;
            for ( i=0;i<nsize-2;i++){
                if(f1 && nums[i]==nums[i-1]) {continue;}
                f1 = true;
                bool f2 = false;
                bool f3 = false;
                j = i+1;
                k = nsize-1;
                while (j!=k){
                    
                    if(f3 && nums[k]==nums[k+1]) { k = k -1 ;continue;}
                    if(f2 && nums[j]==nums[j-1]) { j = j +1 ;continue;}
                    
                    if (nums[i] + nums[j] + nums[k]==0){
                        res_m.at(0)=nums[i];
                        res_m.at(1)=nums[j];
                        res_m.at(2)=nums[k];
                        res.push_back(res_m);
                    }
                    if (nums[i] + nums[j] + nums[k] >0){
                        k=k-1;
                        f3 = true;
                        
                    }else{
                        j=j+1;
                        f2 = true;
                    }
                    
                }
                
            }
        }
        return res;
    }
};


void test3Sum()
{
    vector<int> s;
    s.push_back(0);
    s.push_back(0);
    s.push_back(0);
    s.push_back(-1);
    s.push_back(0);
    s.push_back(1);
    //s.push_back(-2);
    //s.push_back(4);
    vector<int> ts;
    vector< vector<int> > myvector;
    Solution12_nSquare_2 solution;
    myvector=solution.threeSum(s);
    
 
    for(int i=0;i<myvector.size();i++)
    {
        cout<<myvector[i][0]<<','<<myvector[i][1]<<','<<myvector[i][2]<<endl;
    }
}

//single number

class Solution_single {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()<1) return 0;
        int sizeint=sizeof(int)*8;
        int result=0;
        for(int i=0;i<sizeint;i++)
        {
            int c=0;
            int d=1<<i;
            int j=0;
            for(j=0;j<nums.size();j++)
                if(nums[j]&d)c++;
            if((c%3)!=0)result|=d;
            
        }
        return result;
    }
};

void testSolutionsingle()
{
    Solution_single solution;
    vector<int> nums;
    nums.push_back(1);
    int result=solution.singleNumber(nums);
    cout<<result<<endl;
}

//one Plus
class SolutiononePlus {
public:
    vector<int> plusOne(vector<int>& digits) {
        int nsize=int(digits.size());
        
        vector<int> result;
        for(int i=nsize-1;i>=0;i--)
        {
            if(digits[i]<9)
            {
                digits[i]+=1;
                break;
            }
            else
            {
                digits[i]=0;
                if(i==0)result.push_back(1);
            }
        }
        result.insert(result.end(),digits.begin(),digits.end());
        return result;
        
    }
};


class Solution_longestCommonPrefix {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()<1)
            return string();
        if(strs.size()<2)
            return strs[0];
        string temp;
        temp.assign(strs[0]);
        for(int j=1;j<strs.size();j++)
            temp=commonstr(temp,strs[j]);
        return temp;
    }
    string commonstr(string str1, string str2)
    {
        string newstr;
        int strlen=min(int(str1.size()),int(str2.size()));
        for(int i=0;i<strlen;i++)
        {
            if(str1[i]==str2[i])
                newstr.push_back(str1[i]);
            else
                break;
        }
        return newstr;
    }
};

void teststr()
{
    vector<string> strings;
    strings.push_back("aca");
    strings.push_back("aba");
    //strings.push_back("my");
    Solution_longestCommonPrefix solution;
    string tempstr;
   
    tempstr=solution.longestCommonPrefix(strings);
    cout<<tempstr<<endl;
}


class Solution_generateParentheses{
public:
    vector<string> generateParenthesis(int n) {
        vector<string> temp;
        int firstn=0;
        temp=generateParenthesisr(2*n,firstn);
        return temp;
    }
    
    vector<string> generateParenthesisr(int n,int firstn) {
        if(n==0)return vector<string>();
        vector<string> temp;
        
        if(firstn>0&&firstn<n)
        {
            vector<string> res1=generateParenthesisr(n-1,firstn+1);
            for(int i=0;i<res1.size();i++)
            {
                string now='('+res1[i];
                temp.push_back(now);
                
            }
            vector<string> res2=generateParenthesisr(n-1,firstn-1);
            for(int i=0;i<res2.size();i++)
            {
                string now=')'+res2[i];
                temp.push_back(now);
            }
            
            

        }
        else
        {
            if(firstn==0)
            {
            vector<string> res=generateParenthesisr(n-1,firstn+1);
            for(int i=0;i<res.size();i++)
            {
                string now='('+res[i];
                temp.push_back(now);
                
            }
            }
            else
            {
                string now;
                for(int j=0;j<n;j++)
                    now.push_back(')');
                temp.push_back(now);
            }
        }
        
        return temp;
    }

};

void testGenerate()
{
    Solution_generateParentheses solution;
    vector<string> mystring=solution.generateParenthesis(3);
    for(vector<string>::iterator temp=mystring.begin();temp!=mystring.end();temp++)
        cout<<*temp<<endl;
}

class SolutionIsPalindrome {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;

        int temp=x;
        int sum=0;
        int digit=0;
        while(temp!=0)
        {
            digit=temp%10;
            temp/=10;
            sum=sum*10+digit;
            
        }
        //cout<<x<<','<<sum<<endl;
        if(x==sum)return true;
        else return false;
    }
};

void testIsPalindrome(){
    SolutionIsPalindrome solution;
    bool pali=solution.isPalindrome(1234321);
    cout<<pali<<endl;
    pali=solution.isPalindrome(1233311);
    cout<<pali<<endl;
}

class Solution_findMin {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()<2) return nums[0];
        return findMin(nums,0,int(nums.size())-1);
    }
    
    int findMin(vector<int>& nums, int left,int right)
    {
        if(left==right) return nums[left];
        if((right-left)==1) return nums[left]>nums[right]?nums[right]:nums[left];
        int mintemp=nums[left];
        int middle=(left+right)/2;
        if(nums[left]>nums[middle])
        {
            mintemp=min(findMin(nums,left,middle-1),nums[middle]);
        }
        else
        {
            mintemp=min(nums[left],findMin(nums,middle+1,right));
        }
        
        cout<<left<<','<<right<<','<<mintemp<<endl;
        return mintemp;
    }
};


class Solution_findMin2 {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()<2) return nums[0];
        return findMin(nums,0,int(nums.size())-1);
    }
    
    int findMin(vector<int>& nums, int left,int right)
    {
        if(left==right) return nums[left];
        if((right-left)==1) return nums[left]>nums[right]?nums[right]:nums[left];
        int mintemp=nums[left];
        int middle=(left+right)/2;
        if(nums[left]>nums[middle])
        {
            mintemp=min(findMin(nums,left,middle-1),nums[middle]);
        }
        else
        {
            if(nums[middle]>nums[right])
            mintemp=min(nums[left],findMin(nums,middle+1,right));
            else
                mintemp=min(nums[left],findMin(nums,left+1,right));
        }
        
        cout<<left<<','<<right<<','<<mintemp<<endl;
        return mintemp;
    }
};

void testFindMin()
{
    Solution_findMin2 findmin;
    vector<int> nums;
    //4 5 6 7 0 1 2
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(3);
    //nums.push_back(7)
    
    //nums.push_back(10);
    //nums.push_back(0);
    //nums.push_back(1);
    //nums.push_back(2);
    //nums.push_back(3);
    int min=findmin.findMin(nums);
    cout<<min<<endl;
}


class Solution_peakNum {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()<1)return 0;
        vector<int> tempnums;
        tempnums.push_back(nums[0]-1);
        tempnums.insert(tempnums.end(),nums.begin(),nums.end());
        tempnums.push_back(nums[int(nums.size())-1]-1);
        for(int i=2;i<tempnums.size();i++)
        {
            if(tempnums[i-1]>tempnums[i]&&tempnums[i-1]>tempnums[i-2])
                return i-2;
        }
        return 0;
    }
};

void testPeakNumber()
{
    Solution_peakNum solution;
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(3);
    int temp=solution.findPeakElement(nums);
    cout<<temp<<endl;
}


class Solution_longestSubStr {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0;
        int hashtable[256];
        int maxlen=0;
        for(int i=0;i<256;i++)hashtable[i]=-1;
        for(int i=0;i<s.length();i++)
        {
            if(hashtable[s[i]]!=-1){
                while(start<=hashtable[s[i]])
                    hashtable[s[start++]]=-1;
            }
            if(i-start+1>maxlen)maxlen=i-start+1;
            hashtable[s[i]]=i;
        }
        return maxlen;
    }
};

class Solution_containduplicate {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> contnum;
        for(int i=0;i<nums.size();i++)
        {
            if(contnum.find(nums[i])!=contnum.end())return true;
            else contnum.insert(nums[i]);
        }
        return false;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution_linklist2 {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)return NULL;
        ListNode* temp1;
        ListNode* temp2;
        ListNode* current;
        temp1=head->next;
        temp2=head->next->next;
        
        while(1)
        {
            if(temp1==temp2)
            {
                current=temp1;
                break;
            }
            
            if(temp2==NULL)
                return NULL;
            if(temp2->next==NULL)
                return NULL;
            
            
            temp1=temp1->next;
            temp2=temp2->next->next;
        }
        
        cout<<current->val<<endl;
        
        temp1=head;
        while(temp1!=current)
        {
            temp1=temp1->next;
            current=current->next;
        }
        
        return current;
    }
};

void testSolution_linklist2()
{
    ListNode* head;
    ListNode temp0(3);
    ListNode temp1(2);
    ListNode temp2(0);
    ListNode temp3(-4);
    head=&temp0;
    //if(head->next==NULL)cout<<'1'<<endl;
    temp0.next=&temp1;
    temp1.next=&temp2;
    temp2.next=&temp3;
    temp3.next=&temp0;
    
    Solution_linklist2 solution;
    
    ListNode* current=solution.detectCycle(head);
    if(current!=NULL)
        cout<<current->val<<endl;
}


class Solution_reverse {
public:
    int reverse(int x) {
        bool negative=false;
        long sum=x;
        if(sum<0)
        {
            negative=true;
            sum=-sum;
        }
        
        long temp=0;
        
        while(sum!=0)
        {
            temp=temp*10+sum%10;
            sum/=10;
            if(temp>2147483647)return 0;
        }
        
        if(negative)
            return -int(temp);
        else
            return int(temp);
    }
};

void testreverse()
{
    Solution_reverse solution;
    int a=solution.reverse(-123);
    cout<<a<<endl;
    //2,147,483,647
    int b=solution.reverse(-2147483648);
    cout<<b<<endl;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class SolutionTraversalInoder {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> mystack;
        stack<int> tempint;
        if(root==NULL) return res;
        mystack.push(root);
        while(!mystack.empty())
        {
            TreeNode* temp;
            temp=mystack.top();
            
            mystack.pop();
            if(temp==NULL)
            {
                res.push_back(tempint.top());
                tempint.pop();
                continue;
            }
            if(temp->right==NULL&&temp->left==NULL)
            {
                res.push_back(temp->val);
                continue;
            }
            if(temp->right!=NULL)mystack.push(temp->right);
            mystack.push(NULL);
            tempint.push(temp->val);
            if(temp->left!=NULL)mystack.push(temp->left);
            
        }
        return res;
        
    }
};

void testSolutionTraversalInoder()
{
    SolutionTraversalInoder solution;
    TreeNode* root;
    TreeNode a(4);
    TreeNode b(3);
    TreeNode c(6);
    TreeNode d(7);
    root=&a;
    a.left=&b;
    a.right=&c;
    c.right=&d;
    vector<int> temp=solution.inorderTraversal(root);
    for(int i=0;i<temp.size();i++)
        cout<<temp[i]<<endl;
    
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution_binarytreenode {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL) return vector<vector<int> >();
        
        queue<TreeNode*> myqueue;
        TreeNode* temp;
        int templevel;
        int tempnumber;
        
        queue<int> levels;
        
        queue<int> recordlevels;
        queue<int> numbers;
        myqueue.push(root);
        levels.push(0);
        
        recordlevels.push(0);
        numbers.push(root->val);
        
        int maxlevel=0;
        
        while(!myqueue.empty())
        {
            temp=myqueue.front();
            myqueue.pop();
            
            templevel=levels.front();
            levels.pop();
            
            if(temp->left!=NULL)
            {
                myqueue.push(temp->left);
                levels.push(templevel+1);
                
                recordlevels.push(templevel+1);
                numbers.push(temp->left->val);
                
                if(templevel+1>maxlevel)
                    maxlevel=templevel+1;
            }
            
            if(temp->right!=NULL)
            {
                myqueue.push(temp->right);
                levels.push(templevel+1);
                
                recordlevels.push(templevel+1);
                numbers.push(temp->right->val);
                if(templevel+1>maxlevel)
                    maxlevel=templevel+1;
            }
            
        }
        
        
        
        vector< vector<int> > myvector;
        
        myvector.resize(maxlevel+1);
        
        while(!recordlevels.empty())
        {
            templevel=recordlevels.front();
            tempnumber=numbers.front();
            
            recordlevels.pop();
            numbers.pop();
            
            myvector[maxlevel-templevel].push_back(tempnumber);
        }
        
        return myvector;
        
        
    }
};

void testSolution_binarytreenode()
{
    Solution_binarytreenode solution;
    TreeNode* root;
    TreeNode a(3);
    TreeNode b(9);
    TreeNode c(20);
    TreeNode d(15);
    TreeNode e(7);
    TreeNode f(6);
    root=&a;
    a.left=&b;
    a.right=&c;
    c.left=&d;
    c.right=&e;
    d.left=&f;
    
    vector<vector<int> > myvector=solution.levelOrderBottom(root);
    
    for(int i=0;i<myvector.size();i++)
    {
        for(int j=0;j<myvector[i].size();j++)
            cout<<myvector[i][j]<<',';
        cout<<endl;
    }
    

}

class Solution_convert {
public:
    string convert(string s, int numRows) {
        vector<string> convertstring;
        convertstring.resize(numRows);
        int i;
        
        if(numRows<2)return s;
        
        string::iterator temp=s.begin();
        while(temp!=s.end())
        {
            for(i=0;i<numRows;i++)
            {
                if(temp==s.end())break;
                else
                {
                    convertstring[i].push_back(*temp);
                    temp++;
                }
            }
            
            if(numRows>2)
            {
            for(i=numRows-2;i>0;i--)
            {
                if(temp==s.end())break;
                else
                {
                    convertstring[i].push_back(*temp);
                    temp++;
                }
            }
            }
            
        }
        
        for(i=1;i<numRows;i++)
            convertstring[0]+=convertstring[i];
        
        return convertstring[0];
    
    }
};

void testZigZag()
{
    string zigzagtest="ABC";
    Solution_convert solution;
    string zigzagresult=solution.convert(zigzagtest,2);
    cout<<zigzagresult<<endl;
}

class Solution_regularExpressionMatching {
public:
    bool isMatch(string s, string p) {
        int m=int(s.length());
        int n=int(p.length());
        vector<vector<bool> > dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        
        for(int i=0;i<=m;i++){
            for(int j=1;j<=n;j++){
                if (p[j-1]!='.'&&p[j-1]!='*') {
                    if(i>0&&s[i-1]==p[j-1]&&dp[i-1][j-1])
                        dp[i][j]=true;
                }
                else
                    if(p[j-1]=='.'){
                        if(i>0&&dp[i-1][j-1])
                            dp[i][j]=true;
                    }
                    else
                        if(j>1){
                            if(dp[i][j-1]||dp[i][j-2])//0 element d[i][j-2], 1 element d[i][j-1]
                                dp[i][j]=true;
                            else
                                if(i>0&&(p[j-2]==s[i-1]||p[j-2]=='.')&&dp[i-1][j])
                                    dp[i][j]=true;
                        }
            }
        }
        
        
        return dp[m][n];
        
    }
};

void testRegularExpressionMatching()
{
    Solution_regularExpressionMatching solution;
    bool ismatch=solution.isMatch("abbc", "ab*bbbc");
    cout<<ismatch<<endl;
}


class SolutionthreeSumClosest {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3)return 0;
        int difference=abs(target-nums[0]-nums[1]-nums[2]);
        int closethree=nums[0]+nums[1]+nums[2];
        
        int tempsum;
        sort(nums.begin(),nums.end());
        int i,j,k;
        for(i=0;i<nums.size();i++)
        {
            j=i+1;
            k=int(nums.size())-1;
            while(j<k)
            {
                tempsum=nums[i]+nums[j]+nums[k];
                if(tempsum>target)
                {
                    k--;
                    if(abs(target-tempsum)<difference)
                       {
                          
                           closethree=tempsum;
                           difference=abs(target-tempsum);
                           
                       }
                }
                else
                {
                    if(tempsum<target)
                    {
                        j++;
                        if(abs(target-tempsum)<difference)
                        {
                            
                            closethree=tempsum;
                            difference=abs(target-tempsum);
                        }
                    }
                    else
                    {
                        
                        return target;
                    }
                }

                
            }
        }
        
   
    return closethree;
    
    }
};

void testSolutionthreeSumClosest(){
    SolutionthreeSumClosest solution;
    vector<int> threeint;
    //-1 2 1 -4
    threeint.push_back(-1);
    threeint.push_back(2);
    threeint.push_back(1);
    threeint.push_back(-4);
    threeint.push_back(0);
    int temptarget=solution.threeSumClosest(threeint, 1);
    cout<<temptarget<<endl;
    
}

class Solution_mergeSortedArray {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> newnums;
        vector<int>::iterator temp1,temp2,temp1end,temp2end;
        temp1=nums1.begin();
        temp1end=temp1+m;
        temp2=nums2.begin();
        temp2end=temp2+n;
        while(temp1<temp1end&&temp2<temp2end)
        {
            if(*temp1>*temp2)
            {
                newnums.push_back(*temp2);
                temp2++;
            }
            else
            {
                newnums.push_back(*temp1);
                temp1++;
            }
                
        }
        
        if(temp1!=temp1end)
            newnums.insert(newnums.end(),temp1 , temp1end);
        else
        {
            if(temp2!=nums2.end())
                newnums.insert(newnums.end(),temp2,temp2end);
        }
        
        nums1.clear();
        nums1.insert(nums1.end(), newnums.begin(),newnums.end());
        
        
    }
};

void testSolution_mergeSortedArray()
{
    Solution_mergeSortedArray solution;
    vector<int> a;
    vector<int> b;
    a.push_back(0);
    //a.push_back(5);
    b.push_back(2);
    b.push_back(6);
    b.push_back(7);
    solution.merge(a,0,b,3);
    for(vector<int>::iterator temp=a.begin();temp!=a.end();temp++)
        cout<<*temp<<endl;
}
int main(int argc, const char * argv[]) {
    //testtitletoNumber();
    // insert code here...
    //test3Sum();
    //testBuyandSell();
    //testSolutionsingle();
    //teststr();
    //testGenerate();
    //testIsPalindrome();
    //testFindMin();
    //testPeakNumber();
    //testSolution_linklist2();
    //testreverse();
    //testSolutionTraversalInoder();
    //testSolution_binarytreenode();
    //testZigZag();
    //testRegularExpressionMatching();
    //testSolutionthreeSumClosest();
    testSolution_mergeSortedArray();
    return 1;
}
