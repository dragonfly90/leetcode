
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
#include<deque>
#include<unordered_map>
#include<unordered_set>

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
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

class Solution_binaryTreeOrderTraversal {
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
            
            myvector[templevel].push_back(tempnumber);
        }
        
        return myvector;
        
        
    }
};

void testSolution_binaryTreeOrderTraversal()
{
    Solution_binaryTreeOrderTraversal solution;
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

class SolutionsearchMatrix {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=int(matrix.size());
        if(m==0)return false;
        int n=int(matrix[0].size());
        if(n==0) return false;
        int left,right,middle;
        int row,col;
        
        left=0;
        right=m*n-1;
        middle=(left+right)/2;
        while(left<=right)
        {
            row=middle/n;
            col=middle%n;
            if(matrix[row][col]<target)
            {
                if(middle<right)
                    left=middle+1;
                else
                    return false;
                middle=(left+right)/2;
            }
            else
            {
                if(matrix[row][col]>target)
                {
                    if(middle>left)
                        right=middle-1;
                    else
                        return false;
                    middle=(left+right)/2;
                }
                else
                    return true;
            }
        }
        
        return false;
    }
    
};

void testSolutionsearchMatrix()
{
    SolutionsearchMatrix solution;
    vector<vector<int> > nums;
    nums.resize(3);
    /*
     [
     [1,   3,  5,  7],
     [10, 11, 16, 20],
     [23, 30, 34, 50]
     ]
     */
    nums[0].push_back(1);
    nums[0].push_back(3);
    nums[0].push_back(5);
    nums[0].push_back(7);
    
    nums[1].push_back(10);
    nums[1].push_back(11);
    nums[1].push_back(16);
    nums[1].push_back(20);
    
    nums[2].push_back(23);
    nums[2].push_back(30);
    nums[2].push_back(34);
    nums[2].push_back(50);
    
    vector<vector<int> > nums2;
    nums2.resize(1);
    nums2[0].push_back(1);
    nums2[0].push_back(1);
    
    bool findnumber=solution.searchMatrix(nums, 22);
    
    cout<<findnumber<<endl;
}


/**
 * Definition for binary tree with next pointer.
**/
struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class SolutionTreeLinkNode {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)return;
        queue<TreeLinkNode*> myqueue;
        queue<int> myqueuelevel;
        int currentlevel,previouslevel;
        TreeLinkNode* currentTreeLinkNode,*previousTreeLinkNode;
        myqueue.push(root);
        myqueuelevel.push(0);
        root->next=NULL;
        currentlevel=0;
        currentTreeLinkNode=root;
        
        while(!myqueue.empty())
        {
            previouslevel=currentlevel;
            previousTreeLinkNode=currentTreeLinkNode;
            currentTreeLinkNode=myqueue.front();
            currentlevel=myqueuelevel.front();
            currentTreeLinkNode->next=NULL;
            
            myqueue.pop();
            myqueuelevel.pop();
            
            if(previouslevel==currentlevel&&previousTreeLinkNode!=currentTreeLinkNode)
                previousTreeLinkNode->next=currentTreeLinkNode;
            
            if(currentTreeLinkNode->left!=NULL)
            {
                myqueue.push(currentTreeLinkNode->left);
                myqueuelevel.push(currentlevel+1);
            }
            
            if(currentTreeLinkNode->right!=NULL)
            {
                myqueue.push(currentTreeLinkNode->right);
                myqueuelevel.push(currentlevel+1);
            }
                
            
        }
    }
};

void testSolutionTreeLinkNode()
{
    SolutionTreeLinkNode solution;
    TreeLinkNode* root;
    TreeLinkNode a1(1),a2(2),a3(3),a4(4),a5(5),a6(6),a7(7);
    a1.left=&a2;
    a1.right=&a3;
    a2.left=&a4;
    a2.right=&a5;
    a3.left=&a6;
    a3.right=&a7;
    root=&a1;
    
    solution.connect(root);
    
    TreeLinkNode* a2l,*a3l,*a4l,*a5l,*a6l,*a7l;
    a2l=&a2;
    a3l=&a3;
    a4l=&a4;
    a5l=&a5;
    a6l=&a6;
    a7l=&a7;
    
    
    if(a1.next==NULL&&a3.next==NULL&&a7.next==NULL)
        cout<<'1'<<endl;
    
    if((a1.next==NULL)&&(a2.next==a3l)&&a3.next==NULL&&a4.next==a5l&&a5.next==a6l&&a6.next==a7l&&a7.next==NULL)
        cout<<"1"<<endl;
    else
        cout<<'0'<<endl;
    
}


class Solution_uniquebinary {
public:
    int numTrees(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        vector<int> uniquenumber;
        
        uniquenumber.resize(n+1);
        
        uniquenumber[0]=1;
        uniquenumber[1]=1;
        uniquenumber[2]=2;
        for(int i=3;i<=n;i++)
        {
            uniquenumber[i]=0;
            for(int j=0;j<i;j++)
                uniquenumber[i]+=uniquenumber[j]*uniquenumber[i-1-j];
            
        }
        
        return uniquenumber[n];
    }
};

void testSolution_uniquebinary(){
    Solution_uniquebinary solution;
    int numtemp=solution.numTrees(11);
    cout<<numtemp<<endl;
}


class SolutiontotalNQueens {
public:
    int totalNQueens(int n) {
    
        vector<int> cols;
        
        int totalSolution=findSolution(n,0,cols);
        return totalSolution;
    }
    
    int findSolution(int n,int current,vector<int>& cols)
    {
        //cout<<current<<endl;
        int i=0;
        if(current==n)
        {
   
            return 1;
            //for(i=0;i<int(cols.size());i++)
            //    cout<<i<<','<<cols[i]<<endl;
        }
        
        int sum=0;
        for(i=0;i<n;i++)
        {
           if(noconflict(cols,i))
           {
               cols.push_back(i);
               sum+=findSolution(n, current+1 , cols);
               cols.pop_back();
           }
        }
        return sum;
    }
    
    bool noconflict(vector<int>& cols,int newint)
    {
        int j=0;
        int tempsize=int(cols.size());
        for(j=0;j<tempsize;j++)
        {
            if(abs(newint-cols[j])==abs(tempsize-j)||newint==cols[j])
                return false;
        }
        
        return true;
    }
};

void testSolutiontotalNQueens()
{
    SolutiontotalNQueens solution;
    int solutionnumber=solution.totalNQueens(4);
    cout<<solutionnumber<<endl;
}


class SolutionSearchInsert {
public:
    int searchInsert(vector<int>& nums, int target) {
        int numsize=int(nums.size());
        int left;
        int right,middle;
        left=0;
        right=numsize-1;
        middle=(left+right)/2;
        while(left<right)
        {
            if(target>nums[middle])
            {
                left=middle+1;
                middle=(left+right)/2;
            }
            else
            {
                if(target<nums[middle])
                {
                    right=middle-1;
                    middle=(left+right)/2;
                }
                else
                {
                    cout<<middle<<endl;
                    return middle;
                }
            }
        }
        
        if(target<nums[left])
        {
        
            return left;
        }
        else
        {
            if(target>nums[left])
            return left+1;
            else
                return left;
        }
    }
};

void testSolutionSearchInsert()
{
    SolutionSearchInsert solution;
    vector<int> testint;
    //1,3,5,6
    testint.push_back(1);
    //testint.push_back(3);
    //testint.push_back(5);
    //testint.push_back(6);
    int position=solution.searchInsert(testint, 1);
    cout<<position<<endl;
}

class SolutionclimbStairs {
public:
    int climbStairs(int n) {
        vector<int> solutionnumbers;
        solutionnumbers.resize(n+1);
        solutionnumbers[0]=1;
        solutionnumbers[1]=1;
        if(n<2) return 1;
        for(int i=2;i<=n;i++)
            solutionnumbers[i]=solutionnumbers[i-1]+solutionnumbers[i-2];
        return solutionnumbers[n];
        
    }
};

class SolutionmaxSubArray {
public:
    int maxSubArray(vector<int>& nums) {
        int nsize=int(nums.size());
        
        int max=nums[0];
        int sum=0;
        for(int i=0;i<nsize;i++)
        {
            if(sum>0)
                sum+=nums[i];
            else
            {
                sum=nums[i];
            }
            if(sum>max)
                max=sum;
        }
        return max;
    }
};

void testSolutionmaxSubArray()
{
    SolutionmaxSubArray solution;
    vector<int> arraynumber;
    int myints[] = {-2,1,-3,4,-1,2,1,-5,4};
  
    arraynumber.assign(myints,myints+9);
    int sum=solution.maxSubArray(arraynumber);
    cout<<sum<<endl;
    //[−2,1,−3,4,−1,2,1,−5,4];
}

class SolutionmyAtoi {
public:
    int myAtoi(string str) {
        string::iterator tempiterator;
        bool positivenumber=true;
        long numbervalue=0;
        tempiterator=str.begin();
        while((tempiterator!=str.end())&&*tempiterator==' ')
            tempiterator++;
        if(tempiterator==str.end()) return 0;
        
        if(*tempiterator=='+')
        {
            positivenumber=true;
            tempiterator++;
        }
        else
            if(*tempiterator=='-')
            {
                positivenumber=false;
                tempiterator++;
            }
            else
                if(*tempiterator>='0'&&*tempiterator<='9')
                {
                    numbervalue+=*tempiterator-'0';
                    tempiterator++;
                }
                else
                {
                    return 0;
                }
        
        
        
        while(tempiterator!=str.end())
        {
            if((*tempiterator>='0')&&(*tempiterator<='9'))
                numbervalue=10*numbervalue+(*tempiterator-'0');
            else
                break;
            
            if(numbervalue>INT_MAX&&positivenumber)return INT_MAX;
            else
                if(numbervalue>-long(INT_MIN)&&positivenumber==false) return INT_MIN;
            tempiterator++;
        }
        
        
                    
        if(positivenumber)
            return int(numbervalue);
        else
            return -int(numbervalue);
    }
};

void testSolutionmyAtoi()
{
    SolutionmyAtoi solution;
    int num=solution.myAtoi("-1");
    
    cout<<num<<endl;
}

class SolutionheightbalancedBST {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return newNode(nums, 0, int(nums.size()-1));
    }
    
    TreeNode* newNode(vector<int>& nums, int left, int right)
    {
        if(left==right)
        {
            TreeNode* currentNode=new TreeNode(nums[left]);
            return currentNode;
        }
        else
        if(left<right)
        {
            int middle=(left+right)/2;
            TreeNode* currentNode=new TreeNode(nums[middle]);
            currentNode->left=newNode(nums,left,middle-1);
            currentNode->right=newNode(nums,middle+1,right);
            return currentNode;
        }
        else
            return NULL;
            
            
    }
};


void testSolutionheightbalancedBST(){
    int a[]={1,2,3,4,5,6,7};
    vector<int> nums;
    nums.assign(a,a+7);
    SolutionheightbalancedBST solution;
    TreeNode* root=solution.sortedArrayToBST(nums);
    SolutionTraversalInoder solution2;
    vector<int> newnums=solution2.inorderTraversal(root);
    for(int i=0;i<newnums.size();i++)
        cout<<newnums[i]<<endl;
    
    
}
void testString2int(){
    std::string str_dec = "2001, A Space Odyssey";
    std::string str_hex = "40c3";
    std::string str_bin = "-10010110001";
    std::string str_auto = "0x7f";
    
    std::string::size_type sz;   // alias of size_t
    
    int i_dec = std::stoi (str_dec,&sz);
    int i_hex = std::stoi (str_hex,nullptr,16);
    int i_bin = std::stoi (str_bin,nullptr,2);
    int i_auto = std::stoi (str_auto,nullptr,0);
    
    std::cout << str_dec << ": " << i_dec << " and [" << str_dec.substr(sz) << "]\n";
    std::cout << str_hex << ": " << i_hex << '\n';
    std::cout << str_bin << ": " << i_bin << '\n';
    std::cout << str_auto << ": " << i_auto << '\n';
    cout<<INT_MAX<<','<<INT_MIN<<endl;
}

class SolutionUniquePath {
public:
    int uniquePaths(int m, int n) {
        int i,j;
        vector<vector<int> > uniquePaths;
        uniquePaths.resize(m);
        for(i=0;i<m;i++)
            uniquePaths[i].resize(n);
        
        for(i=0;i<m;i++)
            uniquePaths[i][0]=1;
        for(i=0;i<n;i++)
            uniquePaths[0][i]=1;
        if(m<=1||n<=1)
            return uniquePaths[m-1][n-1];
        cout<<'1'<<endl;
        for(i=1;i<m;i++)
            for(j=1;j<n;j++)
                uniquePaths[i][j]=uniquePaths[i-1][j]+uniquePaths[i][j-1];
        return uniquePaths[m-1][n-1];
        
    }
};

void testSolutionUniquePath(){
    SolutionUniquePath solution;
    int numbersolution=solution.uniquePaths(1, 2);
    cout<<numbersolution<<endl;
}

class SolutionSortedList {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head1,* head2,* head,*temp;
        head1=l1;
        head2=l2;
        if(l1==NULL&&l2==NULL)
            return NULL;
        else
            if(l1==NULL)
                return l2;
            else
                if(l2==NULL)
                    return l1;
        
        if(l1->val<l2->val)
        {
            head=l1;
            temp=l1;
            head1=l1->next;
        }
        else
        {
            head=l2;
            temp=l2;
            head2=l2->next;
        }
            
        while(head1!=NULL&&head2!=NULL)
        {
            if(head1->val<head2->val)
            {
                temp->next=head1;
                temp=temp->next;
                head1=head1->next;
            }
            else
            {
                temp->next=head2;
                temp=temp->next;
                head2=head2->next;
            }
        }
        if(head1!=NULL)
            temp->next=head1;
        else
            if(head2!=NULL)
                temp->next=head2;
        return head;
    }
};

void testSolutionSortedList(){
    SolutionSortedList solution;
    ListNode* l1,*l2,* head;
    l1=new ListNode(1);
    l2=new ListNode(1);
    ListNode a(3),b(5),c(2),d(7);
    l1->next=&c;
    c.next=&b;
    l2->next=&a;
    a.next=&d;
    
    head=solution.mergeTwoLists(l1, l2);
    
    while(head!=NULL)
    {
        cout<<head->val;
        head=head->next;
    }
    
    
}


class SolutiongrayCode {
public:
    vector<int> grayCode(int n) {
        vector<int> grayc;
        grayc.push_back(0);
        
      
        for(int i=0;i<n;i++)
        {
            int highestbit=1<<i;
            for(int j=int(grayc.size())-1;j>=0;j--)
                grayc.push_back(highestbit+grayc[j]);
        }
      
        return grayc;
    }
};

void testSolutiongrayCode()
{
    SolutiongrayCode solution;
    vector<int> temp=solution.grayCode(2);
    for(vector<int>::iterator current=temp.begin();current!=temp.end();current++)
        cout<<*current<<endl;
}


class SolutionremoveElement {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator current;
        vector<int>::iterator inser;
        current=nums.begin();
        inser=nums.begin();
        while(current!=nums.end())
        {
            if(*current!=val)
            {
                *inser=*current;
                inser++;
                current++;
            }
            else
                current++;
        }
        nums.erase(inser,nums.end());
        return int(nums.size());
        
    }
};

void testSolutionremoveElement()
{
    SolutionremoveElement solution;
    int a[]={1,2,3,5,1,4,1};
    vector<int> nums;
    nums.assign(a,a+7);

    int nsize=solution.removeElement(nums,1);
    for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<endl;
    cout<<nsize<<endl;
}

class SolutioncomputeArea {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int width=0;
        int height=0;
        if(C<=E||G<=A)
            return (C-A)*(D-B)+(G-E)*(H-F);
        else
            if(C<G)
            {
                if(E<A)
                    width=C-A;
                else
                    width=C-E;
            }
            else
            {
                if(E<A)
                    width=G-A;
                else
                    width=G-E;
            }
        if(F>=D||B>=H)
           return  (C-A)*(D-B)+(G-E)*(H-F) ;
        else
            if(D>H)
            {
                if(B>F)
                    height=H-B;
                else
                    height=H-F;
                    
            }
        else
        {
            if (B<F)
                height=D-F;
            
            else
                height=D-B;
        }

        return (C-A)*(D-B)+(G-E)*(H-F)-height*width;
    }
};

void testSolutioncomputeArea(){
    SolutioncomputeArea solution;
    int areaa=solution.computeArea(-3, 0, 3, 4, 0, -1, 9, 2);
    std::cout<<areaa;
}

class SolutionminPathSum {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=int(grid.size());
        if(m<1) return 0;
        int n=int(grid[0].size());
        if(n<1) return 0;
        
        int i,j;
        vector<vector<int> >sum;
        sum.resize(m);
        for(i=0;i<m;i++)
            sum[i].resize(n);
        
        sum[0][0]=grid[0][0];
        for(i=1;i<m;i++)
            sum[i][0]=grid[i][0]+sum[i-1][0];
        for(j=1;j<n;j++)
            sum[0][j]=grid[0][j]+sum[0][j-1];
        
        for(i=1;i<m;i++)
            for(j=1;j<n;j++)
                sum[i][j]=min(sum[i-1][j]+grid[i][j],sum[i][j-1]+grid[i][j]);
        
        return sum[m-1][n-1];
        
    }
};

void testSolutionminPathSum()
{
    SolutionminPathSum solution;
    vector<vector<int>> grid;
    grid.resize(1);
    grid[0].push_back(0);
    int path=solution.minPathSum(grid);
    cout<<path<<endl;
}


class SolutionBalancedBinaryTree  {
public:
    bool isBalanced(TreeNode* root) {
        int nleft,nright;
        bool banlance=true;
        if(root==NULL)return true;
        if(root->left!=NULL)
            nleft=height(root->left,banlance);
        else
            nleft=0;
        
        if(root->right!=NULL)
            nright=height(root->right,banlance);
        else
            nright=0;
        
        if(banlance==false||abs(nleft-nright)>1)
            return false;
        else
            return true;
    }
                           
    int height(TreeNode* tempTreeNode, bool& banlance)
    {
      if(tempTreeNode==NULL)
          return 0;
      else
      {
          int lefth=height(tempTreeNode->left,banlance);
          int righth=height(tempTreeNode->right,banlance);
          
          if(banlance&&abs(lefth-righth)>1)
              banlance=false;
              
          return max(lefth,righth)+1;
      }
        
    }
};

void testSolutionBalancedBinaryTree()
{
    SolutionBalancedBinaryTree solution;
    TreeNode* root;
    TreeNode a(1),b(2),c(3);
    root=&a;
    root->right=&b;
    b.right=&c;
    bool isbalance=solution.isBalanced(root);
    cout<<isbalance<<endl;
}

class SolutionPermutations {// interesting
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > allpermutation;
        if(nums.empty()) return allpermutation;
        allpermutation.push_back(vector<int>(1,nums[0]));
        
        for(int i=1;i<nums.size();i++)
        {
            int n=(int)allpermutation.size();
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<allpermutation[j].size();k++)
                {
                    vector<int> per=allpermutation[j];
                    per.insert(per.begin()+k,nums[i]);
                    allpermutation.push_back(per);
                }
                
                allpermutation[j].push_back(nums[i]);
            }
        }
        
        return allpermutation;
        
    }
};

void testSolutionPermutations()
{
    SolutionPermutations solution;
    vector<vector<int> > permutation;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    permutation=solution.permute(nums);
    
    for(int i=0;i<permutation.size();i++)
    {
        for (int j=0; j<permutation[0].size(); j++)
            cout<<permutation[i][j];
        cout<<endl;
    }
}

class SolutionSymmetricTree  {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return false;
        return isSymmetric(root->left,root->right);
        
    }
    
    bool isSymmetric(TreeNode* left, TreeNode* right)
    {
        if(left==NULL&&right==NULL) return true;
        
        if(left==NULL||right==NULL) return false;
        
        if(left->val==right->val)
            return isSymmetric(left->left,right->right)&&isSymmetric(left->right,right->left);
        else
            return false;
    }
};


class Solutionrotate {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=i+1;j<matrix.size();j++)
                swap(matrix[i][j],matrix[j][i]);
        }
        
        for(int i=0;i<matrix.size();i++)
            reverse(matrix[i].begin(),matrix[i].end());
                
    }
    
  };

/*
 1 2
 4 3
 */

/* 
 1 2 3
 8 9 4
 7 6 5
 */

/*
 1 2  3   4
12 13 14  5
11 16 15  6
10 9  8   7
 */

class SolutionSpiralMatrix {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > newMatrix;
        newMatrix.resize(n);
        for(int i=0;i<n;i++)
            newMatrix[i].resize(n);
        
        int left=0;
        int right=n-1;
        int current=1;
        
        while(left<right)
        {
            visitMatrix(newMatrix,current,left,right);
            left++;
            right--;
        }
        
        if(left==right)newMatrix[left][left]=current;
        
        return newMatrix;
    }
    
    void visitMatrix(vector<vector<int> >& newMatrix,int& start,int left,int right)
    {
        int k=left;
        while(k<right)
            newMatrix[left][k++]=start++;
        k=left;
        while(k<right)
            newMatrix[k++][right]=start++;
        k=right;
        while(k>left)
            newMatrix[right][k--]=start++;
        k=right;
        while(k>left)
            newMatrix[k--][left]=start++;
        
    }
    
};

void testSolutionSpiralMatrix(){
    SolutionSpiralMatrix solution;
    vector<vector<int> > spiralMatrix=solution.generateMatrix(5);
    for(int i=0;i<spiralMatrix.size();i++)
    {
        for(int j=0;j<spiralMatrix[i].size();j++)
            cout<<spiralMatrix[i][j]<<',';
        cout<<endl;
    }
}


class SolutionremoveDuplicates {
public:
    int removeDuplicates(vector<int>& nums) {
        int i;
        int j;
        if(nums.size()==0)return 0;
        if(nums.size()==1)return 1;
        j=1;
        for(i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[j-1])
                nums[j++]=nums[i];
        }
        nums.erase(nums.begin()+j,nums.end());
        return j;
    }
};

void testremoveDuplicates()
{
    SolutionremoveDuplicates solution;
    int a[]={1,1,2,2,2,3};
    vector<int> temp;
    temp.assign(a,a+6);
    int length=solution.removeDuplicates(temp);
    for(int i=0;i<temp.size();i++)
        cout<<temp[i]<<endl;
    cout<<"length:"<<length<<endl;
}

//33
class SolutionRotatedSortedArray {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()<1) return -1;
        int pos=-1;
        int min=findMin(nums,pos);
        
        int k=search(nums,target,0,pos);
        if(k!=-1)
            return k;
        k=search(nums,target,pos,(int)nums.size());
        return k;
        
        
    }
    
    int search(vector<int>& nums, int target,int left,int right)
    {
        int middle;
        if(left>right)
            return -1;
        if(left==right)
        {
            if(target==nums[left])
                return left;
            else
                return -1;
        }
        
        middle=(left+right)/2;
        if(nums[middle]==target)return middle;
        else
            if(nums[middle]>target)
                return search(nums,target,left,middle-1);
            else
                return search(nums,target,middle+1,right);
                
                
            
    }
    
    int findMin(vector<int>& nums, int& position) {
        if(nums.size()<2)
        {
            position=0;
            return nums[0];
        }
        return findMin(nums,0,int(nums.size())-1,position);
    }
    
    int findMin(vector<int>& nums, int left,int right,int &position)
    {
        if(left==right)
        {
            position=left;
            return nums[left];
        }
        if((right-left)==1)
        {
            position=nums[left]>nums[right]?right:left;
            return nums[left]>nums[right]?nums[right]:nums[left];
        }
        int mintemp=nums[left];
        
        int middle=(left+right)/2;
        if(nums[left]>nums[middle])
        {
            mintemp=findMin(nums,left,middle-1,position);
            if(nums[middle]<mintemp)
            {
                mintemp=nums[middle];
                position=middle;
            }
           // mintemp=min(findMin(nums,left,middle-1),nums[middle]);
        }
        else
        {
            mintemp=findMin(nums,middle+1,right,position);
            if(nums[left]<mintemp)
            {
                mintemp=nums[left];
                position=left;
            }
            //mintemp=min(nums[left],findMin(nums,middle+1,right));
        }
        
        //cout<<left<<','<<right<<','<<mintemp<<endl;
        return mintemp;
    }
};

//search in sorted array with duplicate
class SolutionRotatedSortedArray2 {
public:
    bool search(vector<int>& nums, int target) {
        int start=0;
        int end=(int)nums.size()-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(nums[mid]==target)return true;
            if(nums[start]<nums[mid])
            {
                if(target>=nums[start]&&target<nums[mid])
                    end=mid-1;
                else
                    start=mid+1;
            }
            else
                if(nums[start]>nums[mid])
                {
                    if(target>nums[mid]&&target<=nums[end])
                        start=mid+1;
                    else
                        end=mid-1;
                }
            else
                start++;
        }
        
        return false;
    }
    
 
};

void testSolutionRotatedSortedArray(){
    SolutionRotatedSortedArray solution;
    int a[]={1,3};
    vector<int> testa;
    testa.assign(a,a+2);
    int pos=solution.search(testa, 3);
    cout<<pos<<endl;
}

void testSolutionRotatedSortedArray2(){
    SolutionRotatedSortedArray2 solution;
    int a[]={1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1};
    vector<int> testa;
    testa.assign(a,a+20);
    int pos=solution.search(testa, 2);
    cout<<pos<<endl;
}

class SolutionsetZeroes {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int i,j;
        if(matrix.empty())
            return;
        int m=(int)matrix.size();
        if(matrix[0].empty())
            return;
        int n=(int)matrix[0].size();
        
        int temp1=1,temp2=1;
        for(i=0;i<m;i++)if(matrix[i][0]==0)temp1=0;
        for(i=0;i<n;i++)if(matrix[0][i]==0)temp2=0;
        
        for(i=1;i<m;i++)
        {
            for(j=1;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        
        for(i=1;i<m;i++)
        {
            
            if(matrix[i][0]==0)
            {
            for(j=1;j<n;j++)
            {
               matrix[i][j]=0;
            }
                
            }
        }
        
        for(j=1;j<n;j++)
        {
            if(matrix[0][j]==0)
            {
            for(i=1;i<m;i++)
               matrix[i][j]=0;
            }
        }
        
        for(i=0;i<m;i++)if(temp1==0)matrix[i][0]=0;
        for(i=0;i<n;i++)if(temp2==0)matrix[0][i]=0;

        
        
        return;
    }
};


void testSolutionsetZeroes()
{
    SolutionsetZeroes solution;
    vector<vector<int> > nums;
    nums.resize(1);
    nums[0].push_back(0);
    nums[0].push_back(1);
    
    solution.setZeroes(nums);
    for(int i=0;i<nums.size();i++)
        for(int j=0;j<nums[0].size();j++)
        {
            cout<<nums[i][j]<<',';
            cout<<endl;
        }
    
}

class SolutionCombinations {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > allcombinations;
        vector<int> currentcombination;
        vector<bool> boolput;
        boolput.assign(n,false);
        searchcom(allcombinations,currentcombination,boolput,k);
        return allcombinations;
    }
    void searchcom(vector<vector<int> >& allcombinations, vector<int>& currentcombination,vector<bool> search, int k)
    {
        if(k==0)
        {
            allcombinations.push_back(currentcombination);
            return;
        }
        for(int i=0;i<search.size();i++)
        {
            if(search[i]==false)
            {
                search[i]=true;
                currentcombination.push_back(i+1);
                searchcom(allcombinations,currentcombination,search,k-1);
                currentcombination.pop_back();
            }
        }
    }
};

void testSolutionCombinations()
{
    vector<vector<int> >allcombinations;
    SolutionCombinations solution;
    allcombinations=solution.combine(4,3);
    for(int i=0;i<allcombinations.size();i++)
    {
        for(int j=0;j<allcombinations[0].size();j++)
        {
            cout<<allcombinations[i][j]<<',';
        }
        cout<<endl;
    }
}


class SolutionremoveDuplicates2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int repeatimes=0;
        if(nums.empty())return 0;
        if(nums.size()==1) return 1;
        
        int i=1;
        int j=1;
        for(j=1;j<nums.size();j++)
        {
            if(nums[j]==nums[i-1])
                repeatimes++;
            else
                repeatimes=0;
            
            if(repeatimes<2)
                nums[i++]=nums[j];
        }
        return i;
    }
};

void testSolutionremoveDuplicates(){
    SolutionremoveDuplicates2 solution;
    vector<int> nums;
    int a[]={1,1,1,2,2,2,3,3};
    nums.assign(a,a+8);
    int length=solution.removeDuplicates(nums);
    cout<<length<<endl;
    for(int i=0;i<length;i++)
        cout<<nums[i]<<endl;
}

class SolutionRoottoLeafNumbers{
public:
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*> myTree;
        queue<int> myTreenumber;
        vector<int> allNumbers;
        int currentnumber;
        TreeNode* currentTreeNode;
        
        myTree.push(root);
        myTreenumber.push(root->val);
        
        while(!myTree.empty())
        {
            currentTreeNode=myTree.front();
            currentnumber=myTreenumber.front();
            myTree.pop();
            myTreenumber.pop();
            
            if(currentTreeNode->left==NULL&&currentTreeNode->right==NULL)
            {
                allNumbers.push_back(currentnumber);
                continue;
            }
            
            if(currentTreeNode->left!=NULL)
            {
                myTree.push(currentTreeNode->left);
                myTreenumber.push(currentnumber*10+currentTreeNode->left->val);
            }
            
            
            if(currentTreeNode->right!=NULL)
            {
                myTree.push(currentTreeNode->right);
                myTreenumber.push(currentnumber*10+currentTreeNode->right->val);
            }
            

        }
        
        int sum=0;
        for(vector<int>::iterator temp=allNumbers.begin();temp!=allNumbers.end();temp++)
            sum+=*temp;
        
        return sum;
        
    }
};

void testSolutionRoottoLeafNumbers()
{
    SolutionRoottoLeafNumbers solution;
    TreeNode* head;
    TreeNode a(1),b(2),c(3);
    head=&a;
    a.left=&b;
    b.right=&c;
    
    int sum=solution.sumNumbers(head);
    cout<<sum<<endl;
}

class SolutionInvertBinaryTree {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if(root==NULL)return NULL;
        TreeNode* left,* right;
        
        left=root->left;
        right=root->right;
        
        if(left==NULL&&right==NULL)
            return root;
        invertTree(left);
        invertTree(right);
        root->right=left;
        root->left=right;
        
        return root;
    }
};

class SolutionPascal {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > sumPascal;
        vector<int> temp;
        vector<int> previous;
        
        if(numRows==0)return sumPascal;
        temp.push_back(1);
        sumPascal.push_back(temp);
        
        if(numRows==1)return sumPascal;
        
        for(int i=2;i<=numRows;i++)
        {
            previous=temp;
            temp.clear();
            
            temp.push_back(1);
            for(int j=0;j<previous.size()-1;j++)
                temp.push_back(previous[j]+previous[j+1]);
            temp.push_back(1);
            
            sumPascal.push_back(temp);
        }
        return sumPascal;
    }
};

void testSolutionPascal(){
    SolutionPascal solution;
    vector<vector<int> > sumPascal=solution.generate(5);
    for(int i=0;i<sumPascal.size();i++)
    {
        for(int j=0;j<sumPascal[i].size();j++)
        {
            cout<<sumPascal[i][j]<<',';
        }
        cout<<endl;
    }
}

class SolutionpathSum {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)return false;
        
        if(root->left==NULL&&root->right==NULL)
            if(root->val==sum)return true;
        
        if(root->left!=NULL&&hasPathSum(root->left,sum-(root->val)))
            return true;
        
        if(root->right!=NULL&&hasPathSum(root->right, sum-(root->val)))
           return true;
        
        return false;
    }
};

void testSolutionpathSum(){
    SolutionpathSum solution;
    TreeNode* root;
    TreeNode a(5),b(4),c(8),d(11),e(13),f(4),g(7),h(2),i(1);
    
    root=&a;
    a.left=&b;
    a.right=&c;
    
    b.left=&d;
    c.left=&e;
    c.right=&f;
    
    d.left=&g;
    d.right=&h;
    
    f.right=&i;
    
    bool findsum=solution.hasPathSum(root, 22);
    
    if(findsum)
        cout<<"find sum=22"<<endl;
}

class Stack {
public:
    queue<int> queue1;
    queue<int> queue2;
    int current1=1;
    bool emptystack;
    int temp;
    // Push element x onto stack.
    void push(int x) {
        if(emptystack)emptystack=false;
        if(current1==1)
        {
            queue1.push(x);
            temp=x;
        }
        else
        {
            queue2.push(x);
            temp=x;
        }
    }
    
    // Removes the element on top of the stack.
    void pop() {
        if(current1==1)
        {
            if(queue1.size()==1)
            {

                queue1.pop();
                emptystack=true;
                return;
                
            }

            while(queue1.size()>1)
            {
                if(queue1.size()==2)
                    temp=queue1.front();
                queue2.push(queue1.front());
                queue1.pop();
                
            }

            queue1.pop();
            current1=2;
        }
       else
        {
            if(queue2.size()==1)
            {
                
                queue2.pop();
                emptystack=true;
                return;
            }

            
            while(queue2.size()>1)
            {
                
                if(queue2.size()==2)
                    temp=queue2.front();
                queue1.push(queue2.front());
                queue2.pop();
            }
            
            queue2.pop();
            current1=1;
        }
        
    }
    
    // Get the top element.
    int top() {
        if(!emptystack)
        return temp;
        else
            return -1;
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return emptystack;
    }
};

class SolutionMultiplyStrings {
public:
    string multiply(string num1, string num2) {
        int size1=(int)num1.size();
        int size2=(int)num2.size();
        //cout<<num1<<endl;
        //cout<<num2<<endl;
        string renum1=string(num1.rbegin(),num1.rend());
        string renum2=string(num2.rbegin(),num2.rend());
        string result;
        int tempsum=0;
        for(int i=0;i<size1+size2-1;i++)
        {
            
            
            for(int j=0;j<=i&&j<size1;j++)
            {
                if((i-j)>=size2)continue;
                tempsum+=(int(renum1[j]-'0'))*(int(renum2[i-j]-'0'));
                //cout<<renum1[j]<<','<<renum2[i-j]<<endl;
            }
            //cout<<char(tempsum%10+'0')<<endl;
            //cout<<"-----"<<endl;
            
            result.push_back(char(tempsum%10+'0'));
            tempsum/=10;
        }
        while(tempsum!=0)
        {
            result.push_back(char(tempsum%10+'0'));
            tempsum/=10;
        }
        
        
        string resultr=string(result.rbegin(),result.rend());
        //cout<<result<<endl;
        int i=0;
        for(i=0;i<((int)resultr.size()-1);i++)
        {
            if(resultr[i]=='0')continue;
            else break;
        }
        return resultr.substr(i,(int)resultr.size()-i);
    }
};

void testSolutionMultiplyStrings()
{
    SolutionMultiplyStrings solution;
    string num1="9";
    string num2="9";
    string result=solution.multiply(num1, num2);
    cout<<result<<endl;
}

void testStack(){
    Stack mystack;
    mystack.push(5);
    mystack.push(6);
    mystack.push(7);
    mystack.push(8);
    mystack.pop();
    mystack.pop();
    while(!mystack.empty())
    {
        cout<<mystack.top()<<endl;
        mystack.pop();
    }
    
    
    mystack.push(5);
    mystack.push(6);
    mystack.push(7);
    mystack.push(8);
    mystack.push(10);
    
    
    while(!mystack.empty())
    {
        cout<<mystack.top()<<endl;
        mystack.pop();
    }
    

    
};

class SolutionminDepth {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int left,right;
        if(root->left==NULL&&root->right==NULL)
            return 1;
        else
            if(root->left==NULL)
                return 1+minDepth(root->right);
        else
            if(root->right==NULL)
                return 1+minDepth(root->left);
        else
        {
            left=minDepth(root->left);
            right=minDepth(root->right);
            if(left<right)
                return left+1;
            else
                return right+1;
        }
            
        
    }
};

class SolutionTrappingRainWater  {
public:
    int trap(vector<int>& height) {
      
        vector<int> leftmostheight;
        int leftmost;
        int rightmost;
        int nsize=(int)height.size();
        
        if(nsize<2)return 0;
        
        leftmostheight.push_back(height[0]);
        leftmost=height[0];
        
        for(int i=1;i<nsize;i++)
        {
            
            if(height[i]>leftmost)
                leftmost=height[i];
            leftmostheight.push_back(leftmost);
            
        }
        
        int sum=0;
        rightmost=height[nsize-1];
        
        for(int i=nsize-2;i>=0;i--)
        {
            if(height[i]>rightmost)
                rightmost=height[i];
            if(min(leftmostheight[i],rightmost)>height[i])
                sum+=min(leftmostheight[i],rightmost)-height[i];
        }
        
        return sum;
        
    }
};


class SolutionlongestConsecutive {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> mapnums;
        for(int i=0;i<nums.size();i++){
            mapnums[nums[i]]=true;
        }
        
        int maxlength=0;
        for(int i=0;i<nums.size();i++)
        {
            int current=nums[i];
            int len=1;
            mapnums.erase(nums[i]);
            
            while(mapnums.find(current+1)!=mapnums.end())
            {
                current++;
                mapnums.erase(current);
                len++;
            }
            
            current=nums[i];
            while(mapnums.find(current-1)!=mapnums.end())
            {
                current--;
                mapnums.erase(current);
                len++;
            }
            
            if(len>maxlength)
                maxlength=len;
        }
        
        return maxlength;
    }
};

void testSolutionTrappingRainWater()
{
    vector<int> height;
    int a[]={0,1,0,2,1,0,1,3,2,1,2,1};
    int b[]={5,5,1,7,1,1,5,2,7,6};
    int c[]={0,2,0};
    height.assign(b,b+10);
    SolutionTrappingRainWater solution;
    int sum=solution.trap(height);
    cout<<sum<<endl;
}

/*
     1
   1  1
 1   2   1
1  3   3    1
 */

class SolutionPASCAL {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pasacalrow;
        pasacalrow.resize(rowIndex+1);
        if(rowIndex==0)
        {
            pasacalrow[0]=1;
            
            return pasacalrow;
        }
        if(rowIndex==1)
        {
            pasacalrow[0]=1;
            pasacalrow[1]=1;
            return pasacalrow;
        }
        
        pasacalrow[0]=1;
        pasacalrow[1]=1;
        int tempp,templ;
        for(int i=2;i<=rowIndex;i++)
        {
            pasacalrow[0]=1;
            templ=1;
            for(int j=1;j<=i-1;j++)
            {
                tempp=pasacalrow[j];
                pasacalrow[j]=templ+pasacalrow[j];
                templ=tempp;
                
            }
            pasacalrow[i]=1;
           
        }
        return pasacalrow;
    }
};

void testSolutionPASCAL()
{
    SolutionPASCAL solution;
    vector<int> tempint;
    tempint=solution.getRow(2);
   for(int i=0;i<tempint.size();i++)
       cout<<tempint[i]<<endl;
}

class BSTIterator_On {
private:
    vector<int> m_values;
    int m_idx;
  
public:

    BSTIterator_On(TreeNode *root) {
        inOrder(root);
        m_idx=0;
    }
    
    void inOrder(TreeNode* root)
    {
        if(root==NULL)
            return;
        inOrder(root->left);
        m_values.push_back(root->val);
        inOrder(root->right);
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
       if(m_idx<m_values.size())
           return true;
        
        return false;
    }
    
    /** @return the next smallest number */
    int next() {
        return m_values[m_idx++];
    }
};

/*
public class BSTIterator{
    ST
    
    public BSTIterator(TreeNode root){
       
        while(root!=NULL){
            stack.push(root):
            root=root.left;
        }
    }
    
    public bool hasNext(){
        return STACK.
    }
};
*/

class BSTIterator {
    stack<TreeNode*> mystack;
public:
    BSTIterator(TreeNode *root) {
        while(root!=NULL)
        {
            mystack.push(root);
            root=root->left;
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !mystack.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* node=mystack.top();
        mystack.pop();
        int ret=node->val;
        if(node->right!=NULL){
            node=node->right;
            while(node!=NULL){
                mystack.push(node);
                node=node->left;
            }
        }
        
        return ret;
    }
};

//f(n)=max{f(n-1),f(n-2)+nums[n-1]
class SolutionRob {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<1)return 0;
        int nsize=(int)nums.size();
        vector<int> newnums;
        newnums.resize(nsize+1);
        newnums[0]=0;
        newnums[1]=nums[0];
        
        for(int i=2;i<=nsize;i++)
        {
            newnums[i]=max(newnums[i-2]+nums[i],newnums[i-1]);
        }
        return newnums[nsize];
    }
};

void testSolutionRob(){
    SolutionRob solution;
    vector<int> temp;
    temp.push_back(0);
    temp.push_back(0);
    int robtemp=solution.rob(temp);
    cout<<robtemp<<endl;
}


class SolutionTreetoLinked {
public:
    void flatten(TreeNode* root) {
        if(root==NULL)return;
        TreeNode* cright=root->right;
        TreeNode* leftend;
        if(root->left!=NULL)
        {
            root->right=root->left;
            leftend=findTreeNode(root->left);
            root->left=NULL;
            if(cright!=NULL)
            {
                findTreeNode(cright);
                leftend->left=NULL;
                leftend->right=cright;
            }
        }
        else
        {
            if(cright!=NULL)
            {
            findTreeNode(cright);
            }
        }
    }
    
    TreeNode* findTreeNode(TreeNode* root)
    {
       
        TreeNode* cright=root->right;
        TreeNode* leftend;
        TreeNode* rightend;
        if(root->left!=NULL)
        {
            root->right=root->left;
            
            leftend=findTreeNode(root->left);
            root->left=NULL;
            rightend=leftend;
            
            if(cright!=NULL)
            {
                rightend=findTreeNode(cright);
                leftend->left=NULL;
                leftend->right=cright;
                
            }
            return rightend;
        }
        else
        {
            if(cright!=NULL)
            {
              return findTreeNode(cright);
            }
            
            return root;
        }
    }
  
};

void testSolutionTreetoLinked()
{
    SolutionTreetoLinked solution;
    TreeNode* head;
    TreeNode a(1),b(2),c(3),d(4),e(5),f(6);
    head=&a;
    a.left=&b;
    a.right=&e;
    
    b.left=&c;
    b.right=&d;
    
    e.right=&f;
    
    solution.flatten(head);
    
    TreeNode* temp=head;
    while(temp!=NULL)
    {
        if(temp->left!=NULL)cout<<"wrong"<<endl;
        cout<<temp->val<<endl;
        temp=temp->right;
    }
}


class SolutiongetIntersectionNode {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int alength,blength;
        ListNode* temp,*temp2;
        alength=0;
        blength=0;
        temp=headA;
        while (temp!=NULL) {
            alength++;
            temp=temp->next;
        }
        temp2=headB;
        while(temp2)
        {
            blength++;
            temp2=temp2->next;
        }
        
        int morele=alength-blength;
        temp=headA;
        temp2=headB;
        if(morele>0)
        {
            for(int i=0;i<morele;i++)
                temp=temp->next;
            
        }
        else
        {
            if(morele<0)
            for(int i=0;i<-morele;i++)
                temp2=temp2->next;
        }
        
        while(temp!=temp2)
        {
            temp=temp->next;
            temp2=temp2->next;
        }
        
        return temp;
    }
};


class SolutionreverseBits {
public:
    uint32_t reverseBits(uint32_t n) {
        bool bitb[32];
        uint32_t sum=0;
        for(int i=0;i<32;i++)
        {
            if(n&(1<<i))
                bitb[i]=true;
            else
                bitb[i]=false;
                
        }
        
        for(int i=0;i<32;i++)
        {
            if(bitb[31-i])
                sum|=(1<<i);
        }
        return sum;
    }
};

void testSolutionreverseBits()
{
    SolutionreverseBits solution;
    uint32_t a=2;
    uint32_t b;
    b=solution.reverseBits(a);
    cout<<b<<endl;
}


class SolutionTrailingZeroes {
public:
    int trailingZeroes(int n) {
        int sum=0;
        int x=5;
        while(n>=x)
        {
            sum+=n/x;
            x*=5;
        }
        return sum;
    }
};

void testSolutionTrailingZeroes()
{
    SolutionTrailingZeroes solution;
    int temp=solution.trailingZeroes(10);
    cout<<temp<<endl;
}

class Solutionsubsets {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > allSubSets;
        vector<int> currentSubset;
        
       // allSubSets.push_back(currentSubset);
        sort(nums.begin(),nums.end());
        if(nums.empty())return allSubSets;
        
        currentSubset.push_back(nums[0]);
        allSubSets.push_back(currentSubset);
        
        for(int i=1;i<nums.size();i++)
        {
            int nsize=(int)allSubSets.size();
            for(int j=0;j<nsize;j++)
            {
                currentSubset=allSubSets[j];
                currentSubset.push_back(nums[i]);
                allSubSets.push_back(currentSubset);
            }
            
            currentSubset.clear();
            currentSubset.push_back(nums[i]);
            allSubSets.push_back(currentSubset);
        }
        
        currentSubset.clear();
        allSubSets.push_back(currentSubset);
        return allSubSets;
        
    }
    
};

void testSolutionsubsets()
{
    Solutionsubsets solution;
    vector<int> numbers;
    //numbers.push_back(1);
    //numbers.push_back(2);
    
    vector<vector<int> > allSubSets=solution.subsets(numbers);
    
    for(int i=0;i<allSubSets.size();i++)
    {
        for(int j=0;j<allSubSets[i].size();j++)
            cout<<allSubSets[i][j]<<',';
        cout<<endl;
    }

    
}


class SolutionlengthOfLastWord {
public:
    int lengthOfLastWord(string s) {
        int len=(int)s.size();
        int current=len-1;
        while(current>=0&&s[current]==' ')
            current--;
        
        int i=0;
        while(current>=0&&s[current]!=' ')
        {
            i++;
            current--;
        }
        
        return i;
    }
};

class SolutionsortedListToBST {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp;
        temp=head;
        vector<ListNode*> allNode;
        
        while(temp!=NULL)
        {
            allNode.push_back(temp);
            temp=temp->next;
        }
        
        vector<TreeNode*> allTreeNode;
        int nsize=(int)allNode.size();
        allTreeNode.resize(nsize);
        
        TreeNode* headTree=sortTree(allTreeNode,allNode,0,nsize-1);
        return headTree;
        
    }
    
    TreeNode* sortTree(vector<TreeNode*>& allTreeNode,vector<ListNode*>& allNode,int begin,int end)
    {
        if(begin>end) return NULL;
        int middle=(begin+end)/2;
        allTreeNode[middle]=new TreeNode(allNode[middle]->val);
        
        
        allTreeNode[middle]->left=sortTree(allTreeNode,allNode,begin,middle-1);
        allTreeNode[middle]->right=sortTree(allTreeNode,allNode,middle+1,end);
        return allTreeNode[middle];
    }
};

void preorder(TreeNode* head)
{
    if(head==NULL)return;
    if(head->left!=NULL)preorder(head->left);
    cout<<head->val<<endl;
    if(head->right!=NULL)preorder(head->right);
}

void testSolutionsortedListToBST(){
    SolutionsortedListToBST solution;
    ListNode* head;
    ListNode a(5),b(6),c(7),d(8),e(9);
    head=&a;
    a.next=&b;
    b.next=&c;
    c.next=&d;
    d.next=&e;
    TreeNode* mytreeHead=solution.sortedListToBST(head);
    preorder(mytreeHead);
    
}

class SolutionuniquePathsWithObstacles {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int> > pathSolution;
        int rows=(int)obstacleGrid.size();
        if(rows==0) return 0;
        int cols=(int)obstacleGrid[0].size();
        
        pathSolution.resize(rows);
        for(int i=0;i<rows;i++)
            pathSolution[i].resize(cols);
        
        if(obstacleGrid[0][0]==1)
            pathSolution[0][0]=0;
        else
            pathSolution[0][0]=1;
            
        
        for(int i=1;i<rows;i++)
        {
            if(obstacleGrid[i][0]==1)
                pathSolution[i][0]=0;
            else
                pathSolution[i][0]=pathSolution[i-1][0];
            
        }
        
        for(int i=1;i<cols;i++)
        {
            if(obstacleGrid[0][i]==1)
                pathSolution[0][i]=0;
            else
                pathSolution[0][i]=pathSolution[0][i-1];
        }
        
        for(int i=1;i<rows;i++)
            for(int j=1;j<cols;j++)
            {
                if(obstacleGrid[i][j]==1)
                    pathSolution[i][j]=0;
                else
                    pathSolution[i][j]=pathSolution[i-1][j]+pathSolution[i][j-1];
               // cout<<pathSolution[i][j]<<endl;
                
            }
        
        return pathSolution[rows-1][cols-1];
        
    }
};


void testSolutionuniquePathsWithObstacles()
{
    vector<vector<int> > obstacleGrid;
    SolutionuniquePathsWithObstacles solution;
    obstacleGrid.resize(3);
    obstacleGrid[0].push_back(0);
    obstacleGrid[0].push_back(0);
    obstacleGrid[0].push_back(0);
    obstacleGrid[1].push_back(0);
    obstacleGrid[1].push_back(1);
    obstacleGrid[1].push_back(0);
    obstacleGrid[2].push_back(0);
    obstacleGrid[2].push_back(0);
    obstacleGrid[2].push_back(0);
    
    vector<vector<int> > obstacleGrid2;
    obstacleGrid.resize(2);
    obstacleGrid[0].push_back(0);
    obstacleGrid[1].push_back(0);
    
    int pathNumbers=solution.uniquePathsWithObstacles(obstacleGrid2);
    cout<<pathNumbers<<endl;
    
}

class SolutiongenerateTrees {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return generateTrees(1,0);
        return generateTrees(1,n);
    }
    
    vector<TreeNode*> generateTrees(int start,int end)
    {
        vector<TreeNode*> allTrees;
        if(start>end)
        {
            allTrees.push_back(NULL);
            return allTrees;
        }
        
        for(int i=start;i<=end;i++)
        {
            
            vector<TreeNode*> leftTree;
            vector<TreeNode*> rightTree;
            
            leftTree=generateTrees(start,i-1);
        
            rightTree=generateTrees(i+1, end);
            
            
            for(int j=0;j<leftTree.size();j++)
                for(int k=0;k<rightTree.size();k++)
                {
                    TreeNode* temp=new TreeNode(i);
                    
                    temp->left=leftTree[j];
                    temp->right=rightTree[k];
                    allTrees.push_back(temp);
                    
                    
                }
        }
        
        
        return allTrees;
    }
    
};



void testSolutiongenerateTrees()
{
    SolutiongenerateTrees solution;
    vector<TreeNode*> allTrees=solution.generateTrees(0);
    for(int i=0;i<allTrees.size();i++)
        preorder(allTrees[i]);
}


class SolutionCombinationSum {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > allCombinationSum;
        vector<int> current;
        generateAllCombinations(candidates,0,(int)candidates.size()-1,target,current,allCombinationSum);
        
        return allCombinationSum;
        
    }
    
    void generateAllCombinations(vector<int>& candidates,int start,int end,int sum,vector<int>& current,vector<vector<int> >& allCombinations){
        
        if(sum==0)
        {
            allCombinations.push_back(current);
            return;
        }

        
        if(sum<0||start>end)return;
        
        int i=0;
        
        while(i<(sum/candidates[start]))
        {
            current.push_back(candidates[start]);
            generateAllCombinations(candidates,start+1,end,sum-(i+1)*candidates[start],current,allCombinations);
            i++;
        }
        
        while(i>0)
        {
            current.pop_back();
            i--;
        }
        
        generateAllCombinations(candidates,start+1,end,sum,current,allCombinations);
        
    }
};

void testSolutionCombinationSum()
{
    SolutionCombinationSum solution;
    vector<int> testvector;
    testvector.push_back(1);
    testvector.push_back(2);
    vector<vector<int> > newvector=solution.combinationSum(testvector, 3);
    
    for(int i=0;i<newvector.size();i++)
    {
        for(int j=0;j<newvector[i].size();j++)
            cout<<newvector[i][j]<<',';
        cout<<endl;
    }
}


class SolutioncombinationSum3 {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > allCombinationSum;
        int start=1;
        vector<int> tempnumbers;
        combinationSumNumbers(k,n,start,tempnumbers,allCombinationSum);
        return allCombinationSum;
    }
    
    void combinationSumNumbers(int k,int n, int temp, vector<int>& tempnumbers, vector<vector<int> >& allCombinationSum)
    {
        if(n==0&&k==0)
        {
            allCombinationSum.push_back(tempnumbers);
        }
        
        if(k<0||n<0||temp>9)
            return;
        
        for(int i=temp;i<=9;i++)
        {
            tempnumbers.push_back(i);
            combinationSumNumbers(k-1,n-i,i+1,tempnumbers,allCombinationSum);
            tempnumbers.pop_back();
        }
    }
};


void testSolutioncombinationSum3()
{
    SolutioncombinationSum3 solution;
    vector<vector<int>> newvector=solution.combinationSum3(2,18);
    for(int i=0;i<newvector.size();i++)
    {
        for(int j=0;j<newvector[i].size();j++)
            cout<<newvector[i][j]<<',';
        cout<<endl;
    }

}


class SolutionsubsetsWithDup {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > allSubsets;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        allSubsets.push_back(temp);
        
        int i=0;
        if(nums.size()==0)
            return allSubsets;
        allSubsets.pop_back();
        
        int nsize=(int)nums.size()-1;
        
        generateAllSubSets(allSubsets,nums,temp,i,nsize);
        return allSubsets;
    }
    
    void generateAllSubSets(vector<vector<int> >& allSubsets, vector<int>& nums, vector<int>& temp, int i, int nsize)
    {
        if(i>nsize)
        {
            allSubsets.push_back(temp);
            return;
        }
        int j=0;
        int numscurrent;
        
        if(i+1<=nsize)
        {
        for(j=i+1;j<=nsize;j++)
        {
            if(nums[j]!=nums[j-1])
                break;
        }
            numscurrent=j-i;
        }
        else
            numscurrent=1;
            
        
        
        
        generateAllSubSets(allSubsets, nums, temp, i+numscurrent,nsize);
        
        for(j=0;j<numscurrent;j++)
        {
            temp.push_back(nums[i]);
            generateAllSubSets(allSubsets,nums,temp,i+numscurrent,nsize);
        }
        
        for(j=0;j<numscurrent;j++)
            temp.pop_back();
    }
};

void testSolutionsubsetsWithDup()
{
    SolutionsubsetsWithDup solution;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
       vector<vector<int> > newvector=solution.subsetsWithDup(nums);
    for(int i=0;i<newvector.size();i++)
    {
        for(int j=0;j<newvector[i].size();j++)
            cout<<newvector[i][j]<<',';
        cout<<endl;
    }
}

class SolutionPartition {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* head2=new ListNode(x);
        ListNode* head1=new ListNode(0);
        ListNode* temp=head;
        ListNode* head1tail=NULL;
        ListNode* head2tail=NULL;
        while(temp!=NULL)
        {
            ListNode* tempNext=temp->next;
            
            if(temp->val<x)
            {
                if(head1tail==NULL)
                {
                    head1->next=temp;
                    
                    head1tail=temp;
                    head1tail->next=NULL;
                    //cout<<temp->val<<endl;
                }
                else
                {
                    head1tail->next=temp;
                    head1tail=temp;
                    head1tail->next=NULL;
                    //cout<<temp->val<<endl;
                }
            }
            else
            {
                if(head2tail==NULL)
                {
                    head2->next=temp;
                    head2tail=temp;
                    head2tail->next=NULL;
                    //cout<<temp->val<<endl;
                }
                else
                {
                    head2tail->next=temp;
                    head2tail=temp;
                    head2tail->next=NULL;
                    //cout<<temp->val<<endl;
                }
            }
            temp=tempNext;
        }
        
        if(head1tail==NULL)
        {
            head2tail=head2->next;
            delete head2;
            
            return head2tail;
        }
        else
        {
        
            head1tail->next=head2->next;
            head1tail=head1->next;
            delete head1;
            
            return head1tail;
        }
        
    }
};

void testSolutionPartition()
{
    SolutionPartition solution;
    ListNode* head;
    ListNode* headSort;
    ListNode a(1),b(1);
    head=&a;
    a.next=&b;
    
    headSort=solution.partition(head, 2);
    
    ListNode* temp;
    temp=headSort;
    while(temp!=NULL)
    {
        cout<<temp->val<<endl;
        temp=temp->next;
    }
    
}

class SolutionSearchRange {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left,right;
        int current,currentl,currentr;
        vector<int> myvector;
        left=0;
        right=(int)nums.size()-1;
        current=searchInt(nums,left,right,target);
        if(current==-1)
        {
            myvector.push_back(-1);
            myvector.push_back(-1);
        }
        else
        {
            currentl=searchLeftHand(nums,left,current,target);
            
            currentr=searchRightHand(nums,current,right,target);
           
            
            myvector.push_back(currentl);
            myvector.push_back(currentr);
            
        }
        
        return myvector;
    }
    
    int searchLeftHand(vector<int> &nums,int left,int right,int target){
        if(left==right)return left;
     
        int middle=(left+right)/2;
        
        if(nums[middle]==target)
            return searchLeftHand(nums, left, middle, target);
        else
            return searchLeftHand(nums, middle+1, right, target);
            
    }
    
    int searchRightHand(vector<int> &nums,int left,int right,int target)
    {
      
        if(left==right) return left;
        int middle=(left+right)/2;
        
        if(nums[middle]==target)
        {
            if((right-middle)==1)
            {
                if(nums[right]==target)
                    return right;
                else
                    return middle;
            }
            return searchRightHand(nums, middle,right, target);
        }
        else
        {
            
            return searchRightHand(nums, left, middle-1, target);
        }
    }

    
    int searchInt(vector<int>& nums,int left,int right, int target)
    {
        if(left>right)
            return -1;
    
        if(left==right)
        {
            if(nums[left]==nums[right])
            {
                if(nums[left]==target)
                    return left;
                else
                    return -1;
            }
        
        }
        
        int middle=(left+right)/2;
        if(nums[middle]==target)return middle;
        else
        {
            if(nums[middle]>target)
            {
                return searchInt(nums,left,middle-1,target);
            }
            else
            {
                return searchInt(nums,middle+1,right,target);
            }
        }
    }
                                       
                                       
};

void testSolutionSearchRange()
{
    SolutionSearchRange solution;
    vector<int> nums;
    //nums.push_back(-2);
    //nums.push_back(-1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    //nums.push_back(2);
    vector<int> myvector=solution.searchRange(nums, 1);
    
    for(int i=0;i<myvector.size();i++)
    {
        cout<<myvector[i]<<endl;
    }
}

class SolutionfindKthLargest {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int Left=0;
        int Right=(int)nums.size()-1;
        
        int lef,rig;
        
        while(Left<Right)
        {
            lef=Left;
            rig=Right;
            
            int pivot=nums[lef];
            
            while(lef<rig)
            {
                while(lef<rig&&nums[rig]<pivot)
                    rig--;
                if(lef<rig)nums[lef]=nums[rig];
                while(lef<rig&&nums[lef]>=pivot)
                    lef++;
                if(lef<rig)nums[rig]=nums[lef];
            }
            
            nums[lef]=pivot;
            if(lef==k-1)
                return pivot;
            else
            {
                if(lef>k-1)
                    Right=lef;
                else
                    Left=lef;
            }
        }
        
        return nums[k-1];
        
    }
    
};

class SolutionMinimumTotal {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int i,j;
        int tempSize;
        vector<vector<int> > pathSum;
        int nsize=(int)triangle.size();
        
        if(nsize==0) return 0;
        
        vector<int> tempVector;
        
        tempVector.push_back(triangle[0][0]);
        pathSum.push_back(tempVector);
       
        
        for(i=1;i<nsize;i++)
        {
            
            tempSize=(int)triangle[i].size();
            
            
            tempVector.clear();
            tempVector.resize(tempSize);
            
            if(tempSize>2)
            {
                for(j=1;j<tempSize-1;j++)
                {
                    if(pathSum[i-1][j-1]<pathSum[i-1][j])
                        tempVector[j]=pathSum[i-1][j-1]+triangle[i][j];
                    else
                        tempVector[j]=pathSum[i-1][j]+triangle[i][j];
                    
                }
            }
            
          
           
            
            tempVector[0]=pathSum[i-1][0]+triangle[i][0];
           
            tempVector[tempSize-1]=pathSum[i-1][tempSize-2]+triangle[i][tempSize-1];
            
            
            pathSum.push_back(tempVector);
            
        }
        
        int minValue=pathSum[nsize-1][0];
        for(i=1;i<pathSum[nsize-1].size();i++)
        {
            if(minValue>pathSum[nsize-1][i])
                minValue=pathSum[nsize-1][i];
        }
        
        return minValue;
    }
};

void testSolutionMinimumTotal()
{
    SolutionMinimumTotal solution;
    vector<vector<int> > myvector;
    myvector.resize(4);
    myvector[0].push_back(2);
    myvector[1].push_back(3);
    myvector[1].push_back(4);
    myvector[2].push_back(6);
    myvector[2].push_back(5);
    myvector[2].push_back(7);

    myvector[3].push_back(4);
    myvector[3].push_back(1);
    myvector[3].push_back(8);
    myvector[3].push_back(3);

    int valuem=solution.minimumTotal(myvector);
    cout<<valuem<<endl;
}


class SolutionIsValidSudoku {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size()!=9||board[0].size()!=9)
            return false;
        return rowIsValid(board)&&colIsValid(board)&&gridIsValid(board);
    }
    
    bool rowIsValid(vector<vector<char>>& board){
        for(int i=0;i<9;i++)
        {
            vector<bool> used;
            used.assign(9,false);
            for(int j=0;j<9;j++){
                if(!isdigit(board[i][j]))continue;
                int k=board[i][j]-'0';
                if(k==0||used[k-1])return false;
                used[k-1]=true;
            }
        }
        return true;

    }
    
    bool colIsValid(vector<vector<char>>& board){
        for(int i=0;i<9;i++)
        {
            vector<bool> used;
            used.assign(9,false);
            for(int j=0;j<9;j++){
                if(!isdigit(board[j][i]))continue;
                int k=board[i][j]-'0';
                if(k==0||used[k-1])return false;
                used[k-1]=true;
            }
        }
            return true;
        
    }
    
    bool gridIsValid(vector<vector<char>>& board){
            
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                int row = 3*i;
                int col = 3*j;
                vector<bool> used(9,false);
                for(int m=row; m<row+3; m++) {
                    for(int n=col; n<col+3; n++) {
                        if(!isdigit(board[m][n])) continue;
                        int k = board[m][n]-'0';
                        if(k==0 || used[k-1]) return false;
                        used[k-1]=true;
                    }
                }
            }
        }
        return true;
    }
};


class Queue {
public:
    stack<int> InputStack;
    stack<int> OutputStack;
    // Push element x to the back of queue.
    void push(int x) {
        InputStack.push(x);
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
        if(OutputStack.empty())
        {
            while (!InputStack.empty()) {
                OutputStack.push(InputStack.top());
                InputStack.pop();
            }
        }
        if(!OutputStack.empty())
            OutputStack.pop();
    }
    
    // Get the front element.
    int peek(void) {
        if(OutputStack.empty())
        {
            while (!InputStack.empty()) {
                OutputStack.push(InputStack.top());
                InputStack.pop();
            }
        }
        if(!OutputStack.empty())
            return OutputStack.top();
        return -1;
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        if(InputStack.empty()&&OutputStack.empty())
            return true;
        else
            return false;
    }
};

class SolutionisPowerOfTwo {
public:
    bool isPowerOfTwo(int n) {
        int bitn=1;
        while(n>bitn)
        {
            bitn=bitn<<1;
            cout<<bitn<<endl;
        }
        
        if(n==bitn)
            return true;
        
        return false;
    }
};

void testSolutionisPowerOfTwo(){
    SolutionisPowerOfTwo solution;
    int num=16;
    bool isPowerofTwo=solution.isPowerOfTwo(num);
    if(isPowerofTwo)
        cout<<"is Power of Two"<<endl;
    else
        cout<<"not Power of Two"<<endl;
        
}


class SolutionkthSmallest {
public:
    bool find;
    int result;
    SolutionkthSmallest(){
        result=-1;
        find=true;
    }
    int kthSmallest(TreeNode* root, int k)
    {
        int numk=k;
        return kthSmallests(root,numk);
        
    }
                    
    int kthSmallests(TreeNode* root, int& k) {
       
        
        if(!root||k<=0)
            return -1;
       
        if(root)
        {
          
            kthSmallests(root->left, k);
            
            k--;
           
            if(k==0&&find)
            {
                result=root->val;
                find=false;
            }
            if(k>0)
            {
                return kthSmallests(root->right, k);
            }
            
        }
        else
            if(k>0)
                result=-1;
        
        return result;
    }
};


void SolutionkthSmallesttest(){
    SolutionkthSmallest solution;
    TreeNode a(3);
    TreeNode b(1);
    TreeNode c(4);
    TreeNode d(2);
    TreeNode* root=&a;
    a.left=&b;
    b.right=&d;
    a.right=&c;
    
    int kthSmallest=solution.kthSmallest(root, 3);
    cout<<kthSmallest<<endl;
}

class SolutionrightSideView {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightVector;
        queue<TreeNode*> allNodes;
        queue<int> allLevels;
        
        TreeNode* currentNode;
        int currentLevel;
        
        rightVector.clear();
        TreeNode* temp=root;
        if(temp==NULL)
            return rightVector;
        allNodes.push(root);
        allLevels.push(1);
        
        while(!allNodes.empty())
        {
            currentNode=allNodes.front();
            currentLevel=allLevels.front();
            if(currentLevel>rightVector.size())
                rightVector.push_back(currentNode->val);
            else
                if(currentLevel==((int)rightVector.size()))
                    rightVector[currentLevel-1]=currentNode->val;
            
            if(currentNode->left!=NULL)
            {
                allNodes.push(currentNode->left);
                allLevels.push(currentLevel+1);
            }
            
            if(currentNode->right!=NULL)
            {
                allNodes.push(currentNode->right);
                allLevels.push(currentLevel+1);
            }
            
            allNodes.pop();
            allLevels.pop();
        }
        
        return rightVector;
    }
};




void testSolutionrightSideView(){
    SolutionrightSideView solution;
    TreeNode* head;
    TreeNode a(1),b(2);
    head=&a;
    a.left=&b;
    
    vector<int> solutionVector=solution.rightSideView(head);
    for(int i=0;i<solutionVector.size();i++)
        cout<<solutionVector[i]<<endl;
}


class SolutionRemoveNthFromEnd {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tempHead,* tempEnd;
        int currentIteration=0;
        tempHead=head;
        tempEnd=head;
        while(currentIteration<n)
        {
            tempEnd=tempEnd->next;
            currentIteration++;
        }
        
        ListNode* tempPrevious=NULL;
        
        while(tempEnd!=NULL)
        {
            tempPrevious=tempHead;
            tempHead=tempHead->next;
            tempEnd=tempEnd->next;
            
        }
        
        if(tempPrevious==NULL)
            return head->next;
        else
        {
            if(tempHead==NULL)
                tempPrevious->next=NULL;
            else
                tempPrevious->next=tempHead->next;
        }
        
        return head;
    }
};


class SolutioncanJumpOrigin {
public:
    bool canJump(vector<int>& nums) {
        int nsize=(int)nums.size()-1;
        
        return canJumpPosition(nums, 0, nsize);
    }
    
    bool canJumpPosition(vector<int>& nums, int startPosition,int nsize)
    {
        if(startPosition>=nsize)
            return true;
        
        if(nums[startPosition]>0)
        {
            for(int i=1;i<=nums[startPosition];i++)
            {
                if(canJumpPosition(nums, startPosition+i, nsize))
                    return true;
            }
        }
        
        return false;
        
    }
};


class SolutioncanJump {
public:
    bool canJump(vector<int>& nums) {
    
        int nsize=(int)nums.size();
        if(nsize<=1)return true;
        
        vector<bool> boolnums;
        boolnums.resize(nsize);
        
        for(int i=1;i<nsize;i++)
        {
            boolnums[i]=false;
            for(int j=0;j<i;j++)
            {
                if(nums[i]>=(i-j)&&boolnums[j])
                {
                    boolnums[i]=true;
                    break;
                }
            }
        }
        
        return boolnums[nsize-1];
    }
    
};

/*
 :  bool canJump(int A[], int n) {
 2:      // Start typing your C/C++ solution below
 3:      // DO NOT write int main() function
 4:      int* jump = new int[n];
 5:      jump[0] = 0;
 6:      for(int i=1; i < n; i++)
 7:      {
 8:        jump[i] = max(jump[i-1], A[i-1]) -1;
 9:        if(jump[i] <0)
 10:          return false;;
 11:      }
 12:      return jump[n-1] >=0;
 13:    }
 */

class SolutioncanJumpNP{
public:
    bool canJump(vector<int>& nums)
    {
        int nsize=(int)nums.size();
        if(nsize<=1)return true;
        vector<int> jumpNums;
        jumpNums.resize(nsize);
        
        for(int i=1;i<nsize;i++)
        {
            jumpNums[i]=max(jumpNums[i-1],nums[i-1])-1;
            if(jumpNums[i]<0)
                return false;
        }
        
        return jumpNums[nsize-1]>=0;
    }
};

class SolutionlowestCommonAncestor {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* findTree;
        bool find=false;
        search(root,p,q,find,findTree);
        return findTree;
    }
    
    int search(TreeNode* root,TreeNode* p,TreeNode* q,bool& find,TreeNode*& findTree)
    {
        if(find==true)return 3;
        int current0=0;
        int current1=0;
        int current2=0;
        if(root==p)
            current0=1;
        if(root==q)
            current0=2;
        if(root==NULL)
            return 0;
        if(root->left!=NULL)
            current1=search(root->left,p,q,find,findTree);
        if(root->right!=NULL)
            current2=search(root->right,p,q,find,findTree);
        
        if(current0!=0)
        {
            if(current1==0)
                current1=current0;
            else
                if(current2==0)
                    current2=current0;
                else
                    return 3;
        }
        
        if((current1==1&&current2==2)||(current1==2&&current2==1))
        {
            find=true;
            findTree=root;
            return 3;
        }
        else
        {
            if(current1==1||current2==1)
                return 1;
            else
            {
                if(current1==2||current2==2)
                    return 2;
                else
                    return 0;
            }
        }
        
    }
};



class SolutionDeleteNode {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp=node->next;
        *node=*temp;
        delete temp;
    }
};

class SolutionproductExceptSelf{
public:
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> allProducts;
    int nsize=(int)nums.size();
    
    allProducts.assign(nsize,1);
    
    int temp=1;
    
    for(int i=0;i<nsize;i++)
    {
        if(i>0)
            allProducts[i]*=temp;
        
        temp*=nums[i];
    }
    
    temp=1;
    for(int i=nsize-1;i>=0;i--)
    {
        if(i<nsize-1)
            allProducts[i]*=temp;
        temp*=nums[i];
    }
    
    return allProducts;
    
}
};


class SolutionsearchMatrix2{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=(int)matrix.size();
        if(m<1) return false;
        int n=(int)matrix[0].size();
        if(n<1) return false;
        return searchMatrix(matrix,target,0,0,m-1,n-1);
    }
    
    bool searchMatrix(vector<vector<int> >& matrix, int target, int startr,int startc, int endr, int endc)
    {
        
        if(startr>endr||startc>endc)
        return false;
        if(startr==endr&&startc==endc&&matrix[startr][startc]!=target)
        return false;
        int middler=(startr+endr)/2;
        int middlec=(startc+endc)/2;
        if(matrix[middler][middlec]==target)
        return true;
        else
        {
            if(matrix[middler][middlec]>target)
            {
                if(searchMatrix(matrix,target,startr,startc,middler,middlec))
                return true;
                
                if(searchMatrix(matrix,target,middler+1,startc,endr,middlec-1))
                return true;
                
                if(searchMatrix(matrix,target,startr,middlec,middler-1,endc))
                return true;
                
                return false;
            }
            else
            {
                if(searchMatrix(matrix,target,middler+1,middlec+1,endr,endc))
                return true;
                
                if(searchMatrix(matrix,target,middler+1,startc,endr,middlec))
                return true;
                
                if(searchMatrix(matrix,target,startr,middlec+1,middler,endc))
                return true;
                
                return false;
                
            }
        }
        
    }

};

void testSolutionsearchMatrix2()
{
    vector<vector<int> > matrixs;
    vector<int> matrixAll;
    
    matrixAll.push_back(-5);
    matrixs.push_back(matrixAll);
    
    SolutionsearchMatrix2 solution;
    bool findInt=solution.searchMatrix(matrixs,-10);
    
    if(findInt)
    cout<<"find matrix"<<endl;
    else
    cout<<"don't find matrix"<<endl;
    
    
}


class Solutionpartition {
public:
    
    std::vector<std::vector<std::string> > partition(std::string s) {
        len = int(s.size());
        std::vector<std::vector<std::string> > res;
        std::vector<std::string> pars;
        partitionHelper(s, res, pars, 0);
        return res;
    }
    
private:
    
    int len;
    void partitionHelper(std::string &s, std::vector<std::vector<std::string> > &res, std::vector<std::string> &pars, int begin) {
        if (begin == len)
            res.push_back(pars);
        for (int end = begin; end != len; ++end)
            if (isPalindrome(s, begin, end)) {
                pars.push_back(s.substr(begin, end - begin + 1));
                partitionHelper(s, res, pars, end + 1);
                pars.pop_back();
            }
    }
    
    bool isPalindrome(std::string &s, int begin, int end) {
        while (begin <= end)
            if (s[begin++] != s[end--])
                return false;
        return true;
    }
};

class Solutionpartition2{
public:
    vector<vector<string> > partition(string s){
        vector<vector<string> > allPalindromes;
        vector<string> onePalindrome;
        
        searchAllPartitions(allPalindromes,onePalindrome,s.begin(),s.end());
        return allPalindromes;
    }
    
    void searchAllPartitions(vector<vector<string> >& allPalindromes,vector<string>& onePalindrome,string::iterator currentIter,string::iterator endIter)
    {
        if(currentIter==endIter)
        {
            allPalindromes.push_back(onePalindrome);
            return;
        }
        
        else
        {
            for(string::iterator currents=currentIter;currents!=endIter;currents++)
            {
                string temp=string(currentIter,currents+1);
               
                if(isPalindrome(temp))
                {
                    onePalindrome.push_back(temp);
                    searchAllPartitions(allPalindromes,onePalindrome,currents+1,endIter);
                    onePalindrome.pop_back();
                }
                
                   
            }
        }
    }
                   
    bool isPalindrome(std::string &s) {
        int begin=0;
        int end=(int)s.length()-1;
        while (begin <= end)
            if (s[begin++] != s[end--])
                    return false;
        return true;
    }
};

void testSolutionpartition2(){
    Solutionpartition2 solution1;
    string s="aab";
    vector<vector<string> > alls=solution1.partition(s);
    
    for(int i=0;i<alls.size();i++)
    {
        for(int j=0;j<alls[i].size();j++)
        {
            cout<<alls[i][j]<<endl;
        }
        cout<<"---------------------------"<<endl;
    }
}
class SolutionmyPow {
public:
    double myPow(double x, int n) {
        if(x==0||x==1||n==1)
            return x;
        else
            if(n==0)
                return 1;
        if(x<0&&n%2!=0)
            return -myPow(-x,n);
        else
            if(x<0&&n%2==0)
                return myPow(-x,n);
        
        if(n<0)
            return 1/myPow(x,-n);
        
        return powerP(x,n);
    }
    
    double powerP(double x, int n)
    {
        if(n==1)
            return x;
        return ((n%2)==0)?powerP(x*x,n/2):(powerP(x*x,n/2)*x);
    }
    
};
/*

 2
1 3
 
inorder:   1 2 3
postorder: 1 3 2
 
*/

class SolutionbuildTree {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int m=(int)inorder.size();
        int n=(int)postorder.size();
        int itemp;
        
        if(m==0||m!=n)return NULL;
        TreeNode* temp=new TreeNode(postorder[n-1]);
        
        for(itemp=0;itemp<m;itemp++)
        {
            if(inorder[itemp]==temp->val)
                break;
        }
        
        
        temp->right=findRoot(inorder,itemp+1,m-1,postorder,n-(m-itemp),n-2);
        temp->left=findRoot(inorder,0,itemp-1,postorder,0,n-(m-itemp)-1);
        return temp;
    }
    
    TreeNode* findRoot(vector<int>& inorder, int inleft, int inright, vector<int>& postorder, int outleft,int outright)
    {
        
        TreeNode* temps;
        int itemp;
        if(inleft>inright||outleft>outright)
            return NULL;
        
        if(inleft==inright||outleft==outright)
        {
            temps=new TreeNode(inorder[inleft]);
            return temps;
        }
        else
        {
            temps=new TreeNode(postorder[outright]);
            for(itemp=inleft;itemp<=inright;itemp++)
            {
                
                if(inorder[itemp]==temps->val)
                    break;
            }
            
         
            
            temps->right=findRoot(inorder,itemp+1,inright,postorder,outright-(inright-itemp),outright-1);
            
            temps->left=findRoot(inorder,inleft,itemp-1,postorder,outleft,outright-(inright-itemp)-1);
            return temps;
        }
            
    }
   
};

void testSolutionbuildTree()
{
    SolutionbuildTree solution;
    int a[]={1,2,3,4,5};
    int b[]={4,3,5,2,1};
    vector<int> middle;
    vector<int> post;
    middle.assign(a,a+5);
    post.assign(b,b+5);
    
    TreeNode* root=solution.buildTree(middle, post);
    preorder(root);
}


class SolutionlowestCommonAncestor2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p||root==q||root==NULL)
            return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left&&right)
            return root;
        if(left)
            return left;
        else
            return right;
        
    }
};

class SolutionRobcircle {
public:
    int rob(vector<int>& nums) {
        int length=(int)nums.size();
        
        if(length==0)
            return 0;
        if(length==1)
            return nums[0];
        if(length==2)
            return max(nums[0],nums[1]);
        
        vector<int> numsall1;
        numsall1.resize(length);
        numsall1[0]=nums[0];
        
        for(int i=1;i<length;i++)
        {
            if(i==1)
                numsall1[i]=max(numsall1[i-1],nums[1]);
            else
                if(i==length-1)
                    numsall1[i]=numsall1[i-1];
                else
                    numsall1[i]=max(numsall1[i-1],numsall1[i-2]+nums[i]);
        }
        
        vector<int> numsall2;
        numsall2.resize(length);
        numsall2[0]=nums[length-1];
        numsall2[1]=numsall2[0]+nums[1];
        
        
        for(int i=2;i<length-2;i++)
        {
            numsall2[i]=max(numsall2[i-1],numsall2[i-2]+nums[i]);
        }
        
        
        return max(numsall1[length-1],numsall2[length-3]);
    }
};

void testSolutionRobcircle()
{
    SolutionRobcircle solution;
    int a[]={1,2,1,1};
    vector<int> nums;
    nums.assign(a,a+4);
    
    int maxnum=solution.rob(nums);
    
    cout<<maxnum<<endl;
}

class SolutiondiffWaysToCompute {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> allResults;
        int size=(int)input.size();
        
        for(int i=0;i<size;i++){
            char cur=input[i];
            if(cur=='+'||cur=='-'||cur=='*'){
                vector<int> result1=diffWaysToCompute(input.substr(0,i));
                vector<int> result2=diffWaysToCompute(input.substr(i+1));
                
                for(vector<int>::iterator temp1=result1.begin();temp1!=result1.end();temp1++)
                    for(vector<int>::iterator temp2=result2.begin();temp2!=result2.end();temp2++)
                    {
                        if(cur=='+')
                            allResults.push_back((*temp1)+(*temp2));
                        else
                            if(cur=='-')
                                allResults.push_back((*temp1)-(*temp2));
                            else
                                allResults.push_back((*temp1)*(*temp2));
                        
                    }
            }
        }
        
        if(allResults.empty())
            allResults.push_back(atoi(input.c_str()));
        
        return allResults;
    
    }
};

class SolutioninsertionSortList2 {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* tempHead=new ListNode(0);
        
        ListNode* temp,* tempNext, * searchList, * currentList;
        temp=head;
        
        while(temp!=NULL)
        {
            tempNext=temp->next;
            
            currentList=tempHead;
            searchList=tempHead->next;
            while(searchList!=NULL)
            {
                if(searchList->val<=temp->val)
                {
                    currentList=searchList;
                    searchList=searchList->next;
                }
                else
                {
                    currentList->next=temp;
                    temp->next=searchList;
                    break;
                }
            }
            
            if(searchList==NULL)
            {
                currentList->next=temp;
                temp->next=NULL;
            }
            
            temp=tempNext;
        }
        
        return tempHead->next;
        
    }
};

class SolutionisAnagram {
public:
    bool isAnagram(string s, string t) {
        vector<int> snums;
        vector<int> tnums;
        
        snums.assign(26,0);
        tnums.assign(26,0);
        
        for(string::iterator temp=s.begin();temp!=s.end();temp++)
        {
            snums[int(*temp-'a')]++;
            
        }
        
        for(string::iterator temp=t.begin();temp!=t.end();temp++)
        {
            tnums[int(*temp-'a')]++;
        }
        
        for(int i=0;i<26;i++)
        {
            if(snums[i]!=tnums[i])
                return false;
        }
        
        return true;
    }
};

void testSolutionisAnagram()
{
    SolutionisAnagram solution;
    string s("rat");
    string t("car");
    
    bool findanagram=solution.isAnagram(s, t);
    if(findanagram)
        cout<<"true"<<endl;
}


class SolutionpathSum2 {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > allPathSum;
        vector<int> current;
        findPaths(allPathSum,current,root,sum);
        return allPathSum;
    }
    
    void findPaths(vector<vector<int> >& allPathSum, vector<int>& current,TreeNode* root, int sum)
    {
        
        if(root==NULL)
            return;
        if(root->left==NULL&&root->right==NULL)
        {
            if(sum==root->val)
            {
                current.push_back(root->val);
                allPathSum.push_back(current);
                current.pop_back();
                return;
            }
            else
                return;
        }
    
        
        current.push_back(root->val);
        if(root->left!=NULL)
            findPaths(allPathSum,current,root->left,sum-root->val);
        if(root->right!=NULL)
            findPaths(allPathSum,current,root->right,sum-root->val);
        
        current.pop_back();
    }
    
    
};


class SolutionnumDistinct {
public:
    int numDistinct(string s, string t) {
        int m=(int)t.length();
        int n=(int)s.length();
        int previous;
        
        vector<int>  allnums(m+1,0);
        allnums[0]=1;
     
        
        for(int j=1;j<=n;j++)
        {
            previous=1;
            for(int i=1;i<=m;i++)
            {
                int temp=allnums[i];
                allnums[i]=allnums[i]+(t[i-1]==s[j-1]?previous:0);
                previous=temp;
            }
        }
        return allnums[m];
    }
};

void testSolutionnumDistinct()
{
    SolutionnumDistinct solution;
    string s("rabbbit");
    string t("rabbit");
    
    int numOfDistinct=solution.numDistinct(s, t);
    
    cout<<numOfDistinct<<endl;
}

class SolutionwordBreak {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int nsize=(int)s.size();
        vector<bool> findWordBreak;
        findWordBreak.assign(nsize+1,false);
        
        findWordBreak[0]=true;
        
        for(int i=1;i<=nsize;i++)
        {
            
            for(int j=0;j<i;j++)
            {
                if(wordDict.find(s.substr(j,i-j))!=wordDict.end()&&findWordBreak[j]==true)
                {
                    findWordBreak[i]=true;
                    break;
                }
                
            }
        }
        
        
        return findWordBreak[nsize];
        
        
    }
};


class SolutionwordBreak2 {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int nsize=(int)s.size();
        vector<bool> findWordBreak;
        findWordBreak.assign(nsize+1,false);
        
        findWordBreak[0]=true;
        
        for(int i=1;i<=nsize;i++)
        {
            
            for(int j=0;j<i;j++)
            {
                if(wordDict.find(s.substr(j,i-j))!=wordDict.end()&&findWordBreak[j]==true)
                {
                    findWordBreak[i]=true;
                    break;
                }
                
            }
        }
        
        
        return findWordBreak[nsize];
        
        
    }
};

/*
 minDistance(i,j)
 =(minDistance(i-1,j)+1,
 minDistance(i,j-1)+1,
 minDistance(i-1,j-1)+1,if word[i]!=word[j]
 )
 
 minDistance(0,0)=0,
 minDistance(0,1)=minDistance(1,0)=1
 
 
 abc
 defg
 */
 
class SolutionminDistance {
public:
    int minDistance(string word1, string word2) {
        int size1=(int)word1.size();
        int size2=(int)word2.size();
        
        vector< vector<int> > allMin(size1+1, vector<int>(size2+1,0));
        allMin[0][0]=0;
        for(int i=1;i<=size1;i++)
        {
            allMin[i][0]=i;
        }
        for(int i=1;i<=size2;i++)
        {
            allMin[0][i]=i;
        }
        
        for(int i=1;i<=size1;i++)
            for(int j=1;j<=size2;j++)
            {
                vector<int> alls(3,0);
                if(word1[i-1]==word2[j-1])
                    alls[0]=allMin[i-1][j-1];
                else
                    alls[0]=allMin[i-1][j-1]+1;
                
                alls[1]=allMin[i][j-1]+1;
                
                alls[2]=allMin[i-1][j]+1;
                
                allMin[i][j]=min(alls[0],alls[1]);
                allMin[i][j]=min(alls[2],allMin[i][j]);
            }
        
        return allMin[size1][size2];
    }
};

class SolutionisScramble {
public:
    bool isScramble(string s1, string s2) {
       
        
        if(s1==s2)return true;
        
        vector<int> allNumbers;
        allNumbers.assign(26,0);
        
        for(int i=0;i<s1.size();i++)
        {
            allNumbers[s1[i]-'a']++;
            allNumbers[s2[i]-'a']--;
        }
        
        for(int i=0;i<26;i++)
        {
            if(allNumbers[i]!=0)
                return false;
        }
        
        for(int i=1;i<s1.size();i++)
        {
            if(isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if(isScramble(s1.substr(0,i),s2.substr(s2.size()-i))&&isScramble(s1.substr(i), s2.substr(0,s2.size()-i)))
                return true;
        }
        
        return false;
        
    }
};

class SolutionlargestRectangleArea {
public:
    int largestRectangleArea(vector<int>& height) {
        vector<int> s;
        height.push_back(0);
        
        int sum=0;
        int i=0;
        
        while(i<(int)height.size()){
            if(s.empty()||height[i]>height[s.back()]){
                s.push_back(i);
                i++;
            }
            else
            {
                int t=s.back();
                s.pop_back();
                sum=max(sum,height[t]*(s.empty()?i:i-s.back()-1));
            }
        }
        
        return sum;
            
        
        
    }
};

class SolutionmaximalRectangle {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m=(int)matrix.size();
        if(m==0)return 0;
        int n=(int)matrix[0].size();
        if(n==0)return 0;
        
        
        
        //a[m,n]=
        for(int i=0;i<m;i++)
            for(int i=0;i<n;i++)
            {
                
            }
        return 0;
    }
};

/*
int main(int argc, const char * argv[]) {
    testSolutionnumDistinct();
    return 1;
}
*/

class SolutionaddDigits {
public:
    int addDigits(int num) {
        return 1+(num-1)%9;
    }
};

class SolutionremoveElements {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp=head;
        if(temp==NULL)return NULL;
        if(temp->val==val)
            return removeElements(temp->next,val);
        
        ListNode* tempHead=temp;
        temp=temp->next;
        
        while(temp!=NULL)
        {
            if(temp->val==val)
            {
                temp=temp->next;
                tempHead->next=temp;
            }
            else
            {
                tempHead=temp;
                temp=temp->next;
            }
            
        }
        
        return head;
            
    }
};

unsigned int Factorial( unsigned int number ) {
    return number > 1 ? Factorial(number-1)*number:1;
}

class SolutionsolveNQueens {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > allQueens;
        vector<int>  allNums;
        searchAll(allQueens,allNums,0,n);
        
        return allQueens;
    }
    
    void searchAll(vector<vector<string> >& allQueens,vector<int>& myNums, int current,int& n)
    {
       
        int currentPosition,currentSize;
        int i,j;
        if(current==n)
        {
            vector<string> currentVectorString;
            string currentString;
            
            for(i=0;i<n;i++)
            {
                currentString.clear();
                currentPosition=myNums[i];
                
                for(j=0;j<currentPosition;j++)
                    currentString.push_back('.');
                
                currentString.push_back('Q');
                
                for(j=currentPosition+1;j<n;j++)
                    currentString.push_back('.');
                
                currentVectorString.push_back(currentString);
            }
            
            allQueens.push_back(currentVectorString);
            
            return;
            
        }
        
        currentSize=(int)myNums.size();
        
        for(i=0;i<n;i++)
        {
            if(!isConflict(myNums,currentSize,i))
            {
                myNums.push_back(i);
                searchAll(allQueens,myNums,currentSize+1,n);
                myNums.pop_back();
            }
        }
        
        
    }
    
    bool isConflict(vector<int>& myNums,int currentSize,int num)
    {
        for(int i=0;i<myNums.size();i++)
        {
            if(myNums[i]==num)
                return true;
            
            if(abs(currentSize-i)==abs(num-myNums[i]))
                return true;
        }
        
        return false;
    }
};


class SolutionisUgly {
public:
    bool isUgly(int num) {
        int current=num;
        if(current<=0) return false;
        while(current!=1)
        {
            if(current%2==0)
            {
                current/=2;
                continue;
            }
            else
                if(current%3==0)
                {
                    current/=3;
                    continue;
                }
                else
                    if(current%5==0)
                    {
                        current/=5;
                        continue;
                    }
            
            return false;
            
        }
        
        return true;
    }
};


class SolutionisValid {
public:
    bool isValid(string s) {
        string temp;
        char tempChar;
        char searChar;
        
        for(int i=0;i<s.size();i++)
        {
            searChar=s[i];
            if(searChar=='('||searChar=='{'||searChar=='[')
            {
                temp.push_back(s[i]);
            }
            else
            {
                if(temp.empty())
                    return false;
                tempChar=temp.back();
                if(validate(tempChar,searChar))
                {
                    temp.pop_back();
                    continue;
                }
                else
                    return false;
                
            }
            
            
            
        }
        
        if(temp.empty())
            return true;
        else
            return false;
        
        
    }
    
    bool validate(char tempChar,char endChar)
    {
        if(tempChar=='('&&endChar==')')
            return true;
        
        if(tempChar=='['&&endChar==']')
            return true;
        
        if(tempChar=='{'&&endChar=='}')
            return true;
        
        return false;
    }
};

class SolutionrotateRight {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return  head;
        ListNode* copy=head;
        int len=1;
        while(copy->next!=NULL){
            copy=copy->next;
            len++;
        }
        copy->next=head;
        for(int i=len-k%len;i>1;i--)
        {
            head=head->next;
        }
        copy=copy->next;
        head->next=NULL;
        return copy;
    }
    /*
     if (head == null)
     return head;
     
     ListNode copyHead = head;
     
     int len = 1;
     while (copyHead.next != null) {
     copyHead = copyHead.next;
     len++;
     }
     
     copyHead.next = head;
     
     for (int i = len - k % len; i > 1; i--)
     head = head.next;
     
     copyHead = head.next;
     head.next = null;
     
     return copyHead;
     }
     */
};

class SolutionbuildTree2 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int m=(int)preorder.size();
        int n=(int)inorder.size();
        int middle;
        
        if(m==0||m!=n)
            return NULL;
        
        return findNode(preorder,inorder,0,m-1,0,n-1);
        
        
    }
    
    TreeNode* findNode(vector<int>& preorder,vector<int>& inorder, int pres,int pree, int inos,int inoe)
    {
        if(pres>pree)
            return NULL;
        
        TreeNode* root=new TreeNode(preorder[pres]);
        int middle;
        
        for(int i=inos;i<=inoe;i++)
        {
            if(inorder[i]==preorder[pres])
            {
                middle=i;
                break;
            }
        }
        
        root->left=findNode(preorder,inorder,pres+1,pres+middle-inos,inos,middle-1);
        root->right=findNode(preorder,inorder,pres+1+middle-inos,pree,middle+1,inoe);
        
        return root;
        
        
    }
};

class SolutionsingleNumber2 {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp,a,b;
        temp=0;
        a=0;
        b=0;
        
        for(int i=0;i<nums.size();i++)
        {
            temp^=nums[i];
        }
        
        int highbit=(temp&(temp-1))^temp;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&highbit)a^=nums[i];
            else
                b^=nums[i];
        }
        
        return vector<int>{a,b};
    }
};

class SolutionzigzagLevelOrder {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> myTreeNode;
        queue<int> myLevel;
        TreeNode* currentNode;
        int currentLevel;
        int currentLevelInQueue=0;
        vector<vector<int> > allLevels;
        vector<int> tempVector;
        deque<int> tempQueue;
        
        if(root==NULL)return allLevels;
        myTreeNode.push(root);
        myLevel.push(0);
        
        while(!myTreeNode.empty())
        {
            
            currentNode=myTreeNode.front();
            myTreeNode.pop();
            currentLevel=myLevel.front();
            myLevel.pop();
            
            if(currentLevelInQueue==currentLevel)
            {
                if(currentLevel%2==0)
                    tempQueue.push_back(currentNode->val);
                else
                    tempQueue.push_front(currentNode->val);
            }
            else
            {
                currentLevelInQueue=currentLevel;
                tempVector.assign(tempQueue.begin(),tempQueue.end());
                allLevels.push_back(tempVector);
                tempQueue.clear();
                
                if(currentLevel%2==0)
                    tempQueue.push_back(currentNode->val);
                else
                    tempQueue.push_front(currentNode->val);
            }
            
            if(currentNode->left!=NULL)
            {
                myTreeNode.push(currentNode->left);
                myLevel.push(currentLevel+1);
            }
            
            if(currentNode->right!=NULL)
            {
                myTreeNode.push(currentNode->right);
                myLevel.push(currentLevel+1);
            }
            
        }
        
        tempVector.assign(tempQueue.begin(),tempQueue.end());
        allLevels.push_back(tempVector);
        
        return allLevels;
    }
};


class SolutionmissingNumber {
public:
    int missingNumber(vector<int>& nums) {
        int missing =0;
        for(int i=0; i<nums.size();++i)
            missing ^= ((i+1)^nums[i]);
        return missing;
    }
};

class SolutionreverseBetween {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *temp;
        ListNode *tempNext,*previous,*previousNode,*previousHead;
        int step=1;
        temp=head;
        previous=NULL;
        previousNode=NULL;
        tempNext=NULL;
        
        if(step<m)
            previousNode=temp;
        
        while(step<m)
        {
            previous=temp;
            temp=temp->next;
            step++;
        }
        
        previousHead=temp;
        tempNext=temp->next;
        
        if(tempNext==NULL)
        {
            if(previousNode!=NULL)
                return previousNode;
            else
                return temp;
        }
        
        
        while(step<n)
        {
            temp->next=tempNext->next;
            if(previous!=NULL)
                previous->next=tempNext;
            tempNext->next=previousHead;
            
            previousHead=tempNext;
            
            if(temp->next!=NULL)
                tempNext=temp->next;
            else
                if(previousNode!=NULL)
                    return previousNode;
                else
                    return previousHead;
            
            
            step++;
            
        }
        
        
        if(previousNode!=NULL)
            return previousNode;
        else
            return previousHead;
    }
};

void testSolutionreverseBetween(){
    SolutionreverseBetween solution;
    ListNode* head;
    head=new ListNode(3);
    ListNode b(5);
    ListNode c(6),d(7);
    head->next=&b;
    b.next=&c;
    c.next=&d;
    
    ListNode* current=solution.reverseBetween(head,2,4);
    while(current!=NULL)
    {
        cout<<current->val<<endl;
        current=current->next;
        
    }
}

class SolutionpermuteUnique {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> allVectors;
        vector<int> currentVector;
        permuateUniqueCurrent(nums, currentVector, allVectors);
        
        return allVectors;
    }
    
   void permuateUniqueCurrent(vector<int>& nums, vector<int>& current,vector<vector<int> >& allVectors)
    {
        unordered_map<int,int> mp;
        if(nums.empty())
        {
            allVectors.push_back(current);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!mp[nums[i]])
            {
                vector<int> left;
                
                current.push_back(nums[i]);
                
                left.assign(nums.begin(),nums.end());
                left.erase(nums.begin()+i);
                permuateUniqueCurrent(left, current, allVectors);
                
                current.pop_back();
                mp[nums[i]]=1;
            }
        }
       
        
    }
};


class SolutioncontainsNearbyDuplicate {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> mysets;
        for(int i=0;i<nums.size();i++)
        {
            if(i<k)
            {
                if(mysets.find(nums[i])!=mysets.end())
                    return true;
                else
                    mysets.insert(nums[i]);
            }
            
            else
            {
                mysets.erase(nums[i-k-1]);
                if(mysets.find(nums[i])!=mysets.end())
                    return true;
                else
                    mysets.insert(nums[i]);

            }
        }
        
        return false;
        
        
    }
};


class SolutioncanCompleteCircuit {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumGas=0;
        int tempGas=-1;
        int temp=-1;
        
        for(int i=0;i<gas.size();i++)
        {
            sumGas+=gas[i]-cost[i];
            
            if(tempGas<0)
            {
                temp=i;
                tempGas=gas[i]-cost[i];
            }
            else
                tempGas+=gas[i]-cost[i];
            
        }
        
        if(sumGas>=0)
            return temp;
        else
            return -1;
    
    }
};

/*
 Write a computer program to simulate the machine interference problem as described in section 1.3.1. Each time an event occurs, print out a line of output to show the current values of the clocks and of the other status parameters (as in the hand simulation). Run your simulation until the master clock is equal to 20. Check by hand whether the simulation advances from event to event properly, and whether it updates the clocks and the other status parameters correctly.
*/
class SimulationAssignment{
public:
    int mc;     //master clock
    int cl1;    //clock for machine 1
    int cl2;    //clock for machine 2
    int cl3;    //clock for machine 3
    int cl4;    //clock for departure
    int n;      //number of broken machines
    int r;      //state of repairman
    queue<int> allNumbers;
    int currentStep;
    int nextStep;
    int nextState;//next state broken or recovered;
    
public:
    SimulationAssignment(int mcp=0,int cl1p=1,int cl2p=4,int cl3p=9,int cl4p=0,int np=0,int rp=0)
    {
        mc=mcp;
        cl1=cl1p;
        cl2=cl2p;
        cl3=cl3p;
        cl4=cl4p;
        n=np;
        r=rp;
        currentStep=0;
        
        if(cl1>0)
        {
            nextStep=cl1;
            nextState=0;
        }
        if(cl2>0&&cl2<nextStep)
        {
            nextStep=cl2;
            nextState=0;
            
        }
        if(cl3>0&&cl3<nextStep)
        {
            nextStep=cl3;
            nextState=0;
        }
        
       
        
    }
    
    void generateStep()
    {
        currentStep=nextStep;
        mc=currentStep;
        
    
            
        if(cl1==mc)
        {
            cl1=-1;
            if(allNumbers.empty())
                cl4=mc+5;
            allNumbers.push(1);
            
            
        }
        
        if(cl2==mc)
        {
            cl2=-1;
            if(allNumbers.empty())
                cl4=mc+5;
            allNumbers.push(2);
            
        }
        
        if(cl3==mc)
        {
            cl3=-1;
            if(allNumbers.empty())
                cl4=mc+5;
            allNumbers.push(3);
            
        }
        
        
        if(nextState==1)
        {
            int serial=allNumbers.front();
            if(serial==1)
            {
                cl1=mc+10;
            }
            else
                if(serial==2)
                {
                    cl2=mc+10;
                }
                else
                    cl3=mc+10;
            allNumbers.pop();
            n=(int)allNumbers.size();
            if(n>0)
                cl4=mc+5;

           
        }
        
        
        nextStep=cl4;
        
        if(cl1>0&&cl1<cl4)
        {
            nextStep=cl1;
            nextState=0;
        }
        if(cl2>0&&cl2<cl4)
        {
            nextStep=cl2;
            nextState=0;
            
        }
        if(cl3>0&&cl3<cl4)
        {
            nextStep=cl3;
            nextState=0;
        }
        
        if(nextStep==cl4)
        {
            nextState=1;
        }
        
        
        n=(int)allNumbers.size();
       
        
        if(n>0)
            r=0;
        else
            r=1;
        
        
        
        
       
        
    }
    
    
    
};

void testSimulationAssignment(){
    SimulationAssignment solution;
    while(solution.mc<=30)
    {
        cout<<"mc: "<<solution.mc<<" ("<<solution.cl1<<','<<solution.cl2<<','<<solution.cl3<<','<<solution.cl4<<") "<<solution.n<<"  "<<solution.r<<endl;
        solution.generateStep();
    }
}


class SolutionrangeBitwiseAnd {
public:
    int rangeBitwiseAnd(int m, int n) {
        int diffBit=0;
        while(m!=n)
        {
            m>>=1;
            n>>=1;
            diffBit++;
        }
        
        return n<<diffBit;
    }
};


class SolutionletterCombinations {
public:
    vector<string> letterCombinations(string digits) {
        string mystr[10];
        mystr[0]="";
        mystr[1]="";
        mystr[2]="abc";
        mystr[3]="def";
        mystr[4]="ghi";
        mystr[5]="jkl";
        mystr[6]="mno";
        mystr[7]="pqrs";
        mystr[8]="tuv";
        mystr[9]="wxyz";
        
        string temp;
        vector<string> all;
        int n=(int)digits.size()-1;
        
        search(digits,all,temp,mystr,0,n);
        
        return all;
        
    }
    
    void search(string& digits,vector<string>& allstrs,string& temp, string* mystr,int i,int n)
    {
        
        if(i>n&&!temp.empty())
        {
            allstrs.push_back(temp);
            return;
        }
        if(i>n)
            return;
        int current=digits[i]-'0';
        if(mystr[current].empty())
            search(digits,allstrs,temp,mystr,i+1,n);
        else
            
            for(int j=0;j<mystr[current].size();j++)
            {
                temp.push_back(mystr[current][j]);
                search(digits,allstrs,temp,mystr,i+1,n);
                temp.pop_back();
            }
    }

    
    
};


class SolutionhIndex {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int nsize=(int)citations.size();
        for(int i=0;i<citations.size();i++)
        {
            if(citations[i]>=nsize-i)
                return nsize-i;
        }
        
        return 0;
    }
};


struct RandomListNode {
       int label;
        RandomListNode *next, *random;
         RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class SolutionRandomListNode {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* node=head,* nextNode;
        while(node){
            nextNode=node->next;
            node->next=new RandomListNode(node->label);
            node->next->next=nextNode;
            node=nextNode;
        }
        
        node=head;
        
        while(node){
            node->next->random=node->random?node->random->next:nullptr;
            node=node->next->next;
        }
        
        RandomListNode* fakehead=new RandomListNode(0),* copyNode=fakehead;
        
        node=head;
        while (node) {
            copyNode->next=node->next;
            copyNode=node->next;
            node->next=node->next->next;
            node=node->next;
        }
        
        return fakehead->next;
        
    }
};


class SolutionRandomListNodeHashMap {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*,RandomListNode*> tempList;
        RandomListNode* copy;
        RandomListNode* tempcopy,*tempcopyPrevious;
        RandomListNode* tempRandom;
        
        tempcopyPrevious=NULL;
        copy=NULL;
        tempRandom=head;
        
        while(tempRandom!=NULL)
        {
            if(copy==NULL)
            {
                tempcopy=new RandomListNode(tempRandom->label);
                tempList[tempRandom]=tempcopy;
                tempcopyPrevious=tempcopy;
                copy=tempcopy;
                tempcopy=NULL;
            }
            else
            {
                tempcopy=new RandomListNode(tempRandom->label);
                tempList[tempRandom]=tempcopy;
                
                if(tempcopyPrevious!=NULL)
                {
                    tempcopyPrevious->next=tempcopy;
                    tempcopyPrevious=tempcopy;
                }
                tempcopy=NULL;
            }
            
            tempRandom=tempRandom->next;
            
        }
        
        tempRandom=head;
        
        while(tempRandom!=NULL)
        {
            if(tempRandom->random==NULL)
                tempList[tempRandom]->random=NULL;
            else
                tempList[tempRandom]->random=tempList[tempRandom->random];
            tempRandom=tempRandom->next;
        }
        
        return copy;
        
    }
};

class SolutioncountAndSay {
public:
    string countAndSay(int n) {
        string temp;
        string next;
        int currentdigit=0;
        int numberofdigit=0;
        
        temp="1";
        if(n==1)
            return temp;
        
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<temp.size();j++)
            {
                if(j==0)
                {
                    currentdigit=temp[j];
                    numberofdigit=1;
                }
                else
                {
                    if(temp[j]==currentdigit)
                        numberofdigit++;
                    else
                    {
                        next.push_back(char('0'+numberofdigit));
                        next.push_back(currentdigit);
                        
                        currentdigit=temp[j];
                        numberofdigit=1;
                    }
                }
            }
            
            next.push_back(char('0'+numberofdigit));
            next.push_back(currentdigit);
            
            temp=next;
            next.clear();
        }
        
        return temp;
    }
};

class SolutioncombinationSum2 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > allCombinations;
        
        sort(candidates.begin(),candidates.end());
        vector<int> digits;
        vector<int> numbers;
        vector<int> tempVector;
        int temp=0;
        int tempnumber=0;
        for(int i=0;i<candidates.size();i++)
        {
            if(i==0)
            {
                temp=candidates[i];
                tempnumber=1;
            }
            else
            {
                if(candidates[i]==temp)
                {
                    tempnumber++;
                }
                else
                {
                    digits.push_back(temp);
                    numbers.push_back(tempnumber);
                    temp=candidates[i];
                    tempnumber=1;
                }
            }
        }
        
        if(tempnumber!=0)
        {
            digits.push_back(temp);
            numbers.push_back(tempnumber);
        }
        searchCombinations(allCombinations,tempVector,digits,numbers,target,0);
        return allCombinations;
        
    }
    
    void searchCombinations(vector<vector<int> >& combinations, vector<int>& temp,vector<int>& digits,vector<int>& numbers,int target,int currentposition)
    {
        if(target<0)
            return;
        if(target==0)
        {
            if(!temp.empty())
                combinations.push_back(temp);
            return;
            
        }
        
        if(currentposition>=digits.size())
        {
            return;
        }
        
        for(int i=1;i<=numbers[currentposition];i++)
        {
            temp.push_back(digits[currentposition]);
            searchCombinations(combinations, temp, digits, numbers, target-i*digits[currentposition], currentposition+1);
        }
        
        for(int i=1;i<=numbers[currentposition];i++)
        {
            temp.pop_back();
        }
        
        searchCombinations(combinations, temp, digits, numbers, target, currentposition+1);
        
    }
};


class SolutionreverseKGroup {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> tempVector;
        tempVector.assign(k,NULL);
        int tempsize;
        int i=0;
        ListNode* temp=head;
        ListNode* tempNext=NULL;
        if(k<2) return temp;
        
        while(temp!=NULL)
        {
            tempVector[i%k]=temp;
            temp=temp->next;
            i++;
            
            if(i==k)
            {
                tempVector[0]->next=tempVector[k-1]->next;
                head=tempVector[k-1];
                
                for(int j=k-1;j>=1;j--)
                {
                    tempVector[j]->next=tempVector[j-1];
                }
                
                tempNext=tempVector[0];
                
            }
            else
                if(i%k==0)
                {
                    tempNext->next=tempVector[k-1];
                    tempVector[0]->next=tempVector[k-1]->next;
                    
                    for(int j=k-1;j>=1;j--)
                    {
                        tempVector[j]->next=tempVector[j-1];
                    }
                    
                    tempNext=tempVector[0];
                }
        }
        
        
        return head;
    }
};


class SolutiondeleteDuplicates {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp;
        ListNode* currentHead=NULL;
        ListNode* previousEnd=NULL;
        
        ListNode* newHead=new ListNode(0);
        newHead->next=head;
        temp=head;
        previousEnd=newHead;
        
        while(temp!=NULL)
        {
            currentHead=temp;
           
            temp=temp->next;
            
            
            if(temp==NULL)
                break;
            else
            {
                if(currentHead->val==temp->val)
                {
                    while(temp!=NULL&&currentHead->val==temp->val)
                        temp=temp->next;
                    previousEnd->next=temp;
                }
                else
                {
                    previousEnd=currentHead;
                   // cout<<"currentHead "<<currentHead->val<<endl;
                }
            }
            
            
            
        }
        
        head=newHead->next;
        
        return head;
        
    }
};


class SolutionisIsomorphic {
public:
    bool isIsomorphic(string s, string t) {
        char sm[128];
        char tm[128];
        
        unordered_map<char,char>::iterator got;
        int m=(int)s.size();
        int n=(int)t.size();
        if(m!=n)
            return false;
        
        for(int i=0;i<128;i++)
        {
            sm[i]=-1;
            tm[i]=-1;
        }
        
        for(int i=0;i<m;i++)
        {
            if(sm[s[i]]==t[i]&&tm[t[i]]==s[i])
                continue;
            if(sm[s[i]]==-1&&tm[t[i]]==-1)
            {
                sm[s[i]]=t[i];
                tm[t[i]]=s[i];
                continue;
            }
            return false;
            
        }
        return true;
    }
};

class SolutionnumSquares {
public:
    int numSquares(int n) {
        int* dp=new int[n+1];
        dp[0]=0;
        for(int i=1;i<=n;i++)
            dp[i]=100000;
        for(int i=0;i<=n;i++)
            for(int j=1;i+j*j<=n;j++)
                dp[i+j*j]=min(dp[i+j*j],dp[i]+1);
        
        return dp[n];
    }
};


class SolutionmoveZeroes {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int j=0;
        while(i<nums.size())
        {
            if(nums[i]!=0)
                nums[j++]=nums[i];
            i++;
        }
        while(j<nums.size())
            nums[j++]=0;
    }
};

class TrieNode{
public:
    TrieNode():isWord(false){
        memset(Next,0,sizeof(TreeNode*)*26);
    }
    
    TrieNode(char _c):c(_c),isWord(false){
        memset(Next,0,sizeof(TreeNode*)*26);
    }
    
    TrieNode* Next[26];
    char c;
    bool isWord;
};

class Trie{
public:
    Trie(){
        root=new TrieNode();
    }
    
    void insert(string word){
        TrieNode* p=root;
        int index;
        for(char c:word)
        {
            index=c-'a';
            if(p->Next[index]==NULL)
                p->Next[index]=new TrieNode(c);
            p->isWord=true;
        }
    }
    /*
    void insert(string word){
        TrieNode* p=root;
        int index;
        for(char c:word)
        {
            index=c-'a';
            if(p->Next[index]==NULL)
                p->Next[index]=new TrieNode(c);
            p->isWord=true;
        }
     }
    */
    bool search(string word){
        TrieNode *p=root;
        int index;
        for(char c:word)
        {
            index=c-'a';
            if(p->Next[index]==NULL)
                return false;
            p=p->Next[index];
        }
        return p->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode*p = root;
        int index;
        
        for(char c:prefix)
        {
            index = c - 'a';
            if(p->Next[index] == NULL)
                return false;
            p = p->Next[index];
        }
        return true;
    }

    
private:
    TrieNode* root;
};

//input:  integer array A = [-1, 3, -2, 4, 5, -7, 2]
//output: [-7, -2, -1, 2, 3, 4, 5]
//#include<iostream>
//using namespace std;
class MyQuickSort
{
public:
    
    void quickSort(int* A, int l, int r)
    {
        int p;
        if(l<r)
            p=partition(A,l,r);
        else
            return;
        quickSort(A,l,p-1);
        quickSort(A,p+1,r);
    }

    int partition(int* A, int l, int r)
    {
        int pivotindex=l;
        int pivot=A[l];
        int curl=l;
        int curr=r;
    
        while(curl<curr)
        {
            while(A[curr]>=pivot&&curl<curr)curr--;
            if(curl<curr)
            {
                A[curl]=A[curr];
                curl++;
            }
            while(A[curl]<pivot&&curl<curr)curl++;
            if(curl<curr)
            {
                A[curr]=A[curl];
                curr--;
            }
        }
        
        A[curl]=pivot;
        return curl;
    }
};

void testMyQuickSort()
{
    int A[7]={-1, 3, -2, 4, 5, -7, 2};
    MyQuickSort myquickSort;
    myquickSort.quickSort(A,0,6);
    cout<<'[';
    for(int i=0;i<6;i++)
        cout<<A[i]<<',';
    cout<<A[6]<<']'<<endl;
}
/*
 
 +4
 votes
 364 views
 class TrieNode {
 public:
 // Initialize your data structure here.
 TrieNode():isWord(false){
 memset(Next,0,sizeof(TrieNode*)*26);
 
 }
 TrieNode(char _c):c(_c),isWord(false) {
 memset(Next,0,sizeof(TrieNode*)*26);
 }
 TrieNode* Next[26];
 char c;
 bool isWord;
 };
 
 
 class Trie {
 public:
 Trie() {
 root = new TrieNode();
 }
 
 // Inserts a word into the trie.
 void insert(string word) {
 TrieNode*p = root;
 int index;
 
 for(char c:word)
 {
 index = c - 'a';
 if(p->Next[index] == NULL)
 p->Next[index] = new TrieNode(c);
 p = p->Next[index];
 }
 p->isWord = true;
 }
 
 // Returns if the word is in the trie.
 bool search(string word) {
 TrieNode*p = root;
 int index;
 
 for(char c:word)
 {
 index = c - 'a';
 if(p->Next[index] == NULL)
 return false;
 p = p->Next[index];
 }
 return p-->isWord;
 }
 
 // Returns if there is any word in the trie
 // that starts with the given prefix.
 bool startsWith(string prefix) {
 TrieNode*p = root;
 int index;
 
 for(char c:prefix)
 {
 index = c - 'a';
 if(p->Next[index] == NULL)
 return false;
 p = p->Next[index];
 }
 return true;
 }
 
 private:
 TrieNode* root;
 };
 
 // Your Trie object will be instantiated and called as such:
 // Trie trie;
 // trie.insert("somestring");
 // trie.search("key");
 
 */

class SolutioncanWinNim {
public:
    bool canWinNim(int n) {
        if(n%4==0)
            return false;
        else
            return true;
    }
};

class SolutiongameOfLife {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        if(board.size()==0)
            return;
        
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++)
            {
                int alive=0;
                for(int x=-1;x<=1;x++)
                    for(int y=-1;y<=1;y++)
                        if(!(x==0&&y==0)&&(i+x)>=0&&(i+x)<board.size()&&(j+y)>=0&&(j+y)<board[i].size()&&(board[i+x][j+y]&1)==1)
                            alive++;
                if((board[i][j]&1)==1&&alive>=2&&alive<=3)
                    board[i][j]|=1<<1;
                if((board[i][j]&1)==0&&alive==3)
                    board[i][j]|=1<<1;
            }
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                board[i][j]>>=1;
        
    }
};

class SolutionaddBinary {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
    
        
        string sum;
        
        string::iterator tempa,tempb;
        tempa=a.begin();
        tempb=b.begin();
        int current=0;
        while(tempa!=a.end()||tempb!=b.end())
        {
            if(tempa==a.end())
            {
                current+=int(*tempb-'0');
                if(current==0)
                    sum.push_back('0');
                else
                    if(current==1)
                    {
                        sum.push_back('1');
                        current=0;
                    }
                    else
                    {
                        sum.push_back('0');
                        current=1;
                    }
                tempb+=1;
            }
            else
            {
                if(tempb==b.end())
                {
                    current+=int(*tempa-'0');
                    if(current==0)
                    sum.push_back('0');
                    else
                    if(current==1)
                    {
                        sum.push_back('1');
                        current=0;
                    }
                    else
                    {
                        sum.push_back('0');
                        current=1;
                    }
                    tempa+=1;
                }
                else
                {
                    
                    current+=int(*tempa-'0')+int(*tempb-'0');
                    if(current==0)
                        sum.push_back('0');
                    else
                    if(current==1)
                    {
                        sum.push_back('1');
                        current=0;
                    }
                    else
                    {
                        if(current==2)
                        {
                            sum.push_back('0');
                            current=1;
                        }
                        else
                        {
                            sum.push_back('1');
                            current=1;
                        }
                    }
                    tempa+=1;
                    tempb+=1;
                }
            }
        }
        if(current==1)
        sum.push_back('1');
        reverse(sum.begin(),sum.end());
        cout<<sum<<endl;
        return sum;
    }
};


class SolutionmaximumGap {
public:
    int maximumGap(vector<int>& nums) {
        int n = (int)nums.size();
        if (n < 2) return 0;
        auto lu = minmax_element(nums.begin(), nums.end());
        int l = *lu.first, u = *lu.second;
        int gap = max((u - l) / (n - 1), 1);
        int m = (u - l) / gap + 1;
        vector<int> bucketsMin(m, INT_MAX);
        vector<int> bucketsMax(m, INT_MIN);
        for (int num : nums) {
            int k = (num - l) / gap;
            if (num < bucketsMin[k]) bucketsMin[k] = num;
            if (num > bucketsMax[k]) bucketsMax[k] = num;
        }
        int i = 0, j;
        gap = bucketsMax[0] - bucketsMin[0];
        while (i < m) {
            j = i + 1;
            while (j < m && bucketsMin[j] == INT_MAX && bucketsMax[j] == INT_MIN)
                j++;
            if (j == m) break;
            gap = max(gap, bucketsMin[j] - bucketsMax[i]);
            i = j;
        }
        return gap;
    }
};


class SolutionmaximumGap2 {
    int maximumGap(vector<int>&  nums) {
        int nsize=(int)nums.size();
        if (nsize < 2) {
            return 0;
        }
        
        // m is the maximal number in nums
        int m = nums[0];
        for (int i = 1; i < nsize; i++) {
            m = max(m, nums[i]);
        }
        
        int exp = 1; // 1, 10, 100, 1000 ...
        int R = 10; // 10 digits
        
        int* aux = new int[nsize];
        
        while (m / exp > 0) { // Go through all digits from LSB to MSB
            int* count = new int[R];
            
            for (int i = 0; i < nsize; i++) {
                count[(nums[i] / exp) % 10]++;
            }
            
            for (int i = 1; i < R; i++) {
                count[i] += count[i - 1];
            }
            
            for (int i = nsize - 1; i >= 0; i--) {
                aux[--count[(nums[i] / exp) % 10]] = nums[i];
            }
            
            for (int i = 0; i < nsize; i++) {
                nums[i] = aux[i];
            }
            exp *= 10;
        }
        
        int cmax = 0;
        for (int i = 1; i < nsize; i++) {
            cmax = max(cmax, aux[i] - aux[i - 1]);
        }
        
        return cmax;
    }
};

class SolutionbinaryTreePaths {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int> > allstrs;
        vector<int> temp;
        string tempstr;
        
        citerate(allstrs,root,temp);
        
        vector<string> allstr;
        for(int i=0;i<allstrs.size();i++)
        {
            tempstr.clear();
            int j=0;
            for(j=0;j<allstrs[i].size()-1;j++)
            {
                tempstr=tempstr+to_string(allstrs[i][j]);
                tempstr=tempstr+"->";
            }
            tempstr+=to_string(allstrs[i][j]);
            allstr.push_back(tempstr);
        }
        
        return allstr;
        
    }
    
    void citerate(vector<vector<int> >& allstrs, TreeNode* root,vector<int> temp)
    {
        if(root==NULL)
        {
            if(!temp.empty())
                allstrs.push_back(temp);
        }
        else
        {
            temp.push_back(root->val);
            if(root->left!=NULL)
            {
                citerate(allstrs, root->left, temp);
            }
            if(root->right!=NULL)
            {
                citerate(allstrs, root->right, temp);
            }
            if((root->left==NULL)&&(root->right==NULL))
                citerate(allstrs, NULL, temp);
        }
    }
};

void testSolutionbinaryTreePaths(){
    SolutionbinaryTreePaths solution;
    TreeNode root(1);
    TreeNode a(3);
    TreeNode* myroot;
    myroot=&root;
    myroot->right=&a;
    vector<string> allstrs=solution.binaryTreePaths(myroot);
    for(int i=0;i<allstrs.size();i++)
        cout<<allstrs[i]<<endl;
    
}




#define HASHSIZE 50
struct Lockhash
{
    int lockid;
    int id;
} ;
void initHash();
int hashfuction(int key);
int hashInsert(int key);
int deletekey(int key);
Lockhash hashtable[HASHSIZE];

void initHash()
{
    int i=0;
    for(i=0;i<HASHSIZE;i++)
    {
        hashtable[i].lockid=-1;
        hashtable[i].id=i;
        
    }
}

int hashfuction(int key)
{
    return key%HASHSIZE;
};

int hashInsert(int key)
{
    int position=hashfuction(key);
    if(hashtable[position].lockid==-1)
    {
        hashtable[position].lockid=key;
        return position;
    }
    else
    {
        int j;
        int k;
        for(j=position+1;j<position+HASHSIZE;j++)
        {
            k=j%HASHSIZE;
            if(hashtable[k].lockid==-1)
            {
                hashtable[k].lockid=key;
                return k;
            }
        }
    }
    return -1;
}

int deletekey(int key)
{
    int position=hashfuction(key);
    if(hashtable[position].lockid==key)
    {
        hashtable[position].lockid=-1;
        return position;
    }
    else
    {
        int j;
        int k;

        for(j=position+1;j<position+HASHSIZE;j++)
        {
            k=j%HASHSIZE;
            if(hashtable[k].lockid==key)
            {
                hashtable[k].lockid=-1;
                return k;
            }
        }
    }
    return -1;

}



class solutionanagrams{
public:
    vector<string> anagrams(vector<string>& strs)
    {
        vector<string> vec, anavec;
        unordered_map<string, vector<string> > mp;
        for(string s: strs)
        {
            string tmp=s;
            sort(tmp.begin(),tmp.end());
            mp[tmp].push_back(s);
            
        }
        
        for(auto map:mp)
        {
            if(map.second.size()>1)
                vec.insert(vec.end(), map.second.begin(),map.second.end());
                
        }
        return vec;
        
    }
};

class SolutionTwoSum{
public:
    vector<int> twoSum(vector<int>& numbers, int target){
        vector<int> result;
        unordered_map<int, int> mymap;
        int index1,index2;
        
        index1=0;
        index2=0;
        
        for(int i=0;i<numbers.size();i++)
        {
            if(mymap.find(numbers[i])==mymap.end())
            {
                mymap[target-numbers[i]] = i;
            }
            else
            {
                index1=((mymap[numbers[i]]<i)?mymap[numbers[i]]:i)+1;
                index2=((mymap[numbers[i]]>i)?mymap[numbers[i]]:i)+1;
                result.push_back(index1);
                result.push_back(index2);
                break;
            }
        }
        
        return result;
    }
};


class SolutionFindMedian{
public:
    double findMedianSortedArrays(int A[],int m, int B[],int n)
    {
        int total=m+n;
        if(total & 0x1)
            return findKth(A,m,B,n, total/2+1);
        else
            return findKth(A,m,B,n,total/2)+findKth(A,m,B,n,total/2+1)/2;
    }
    
    double findKth(int a[],int m, int b[], int n,int k)
    {
        if(m>n)
            return findKth(b,n,a,m,k);
        if(m==0)
            return b[k-1];
        if(k==1)
            return min(a[0],b[0]);
        int pa=min(k/2,m), pb=k-pa;
        
        if(a[pa-1]<b[pb-1])
            return findKth(a+pa,m-pa,b,n,k-pa);
        else
            if(a[pa-1]>b[pb-1])
                return findKth(a,m,b+pb,n-pb,k-pb);
            else
                return a[pa-1];
    }
    
};

class SolutiongetHint {
public:
    string getHint(string secret, string guess) {
        string resultStr;
        
        int m=(int)secret.size();
        int n=(int)guess.size();
        
        int anum=0;
        int bnum=0;
        
        int digitsecret[10];
        int digitguess[10];
        
        for(int i=0;i<10;i++)
        {
            digitsecret[i]=0;
            digitguess[i]=0;
        }
        
        for(int i=0;(i<m)&&(i<n);i++)
        {
            if(secret[i]==guess[i])
                anum++;
            else
            {
                digitsecret[int(secret[i]-'0')]++;
                digitguess[int(guess[i]-'0')]++;
            }
            
        }
        
        for(int i=0;i<10;i++)
        {
            bnum+=min(digitsecret[i],digitguess[i]);
        }
        
        
        
        char temp1[64];
        sprintf(temp1, "%d", anum);
        string s1(temp1);
        
    
        char temp2[64];
        sprintf(temp2, "%d", bnum);
        string s2(temp2);
        
        resultStr=s1+'A'+s2+'B';
        
        return resultStr;
    }
};

void testSolutiongetHint()
{
    SolutiongetHint mysolution;
    string secretmy="1807";
    string guessmy="7810";
    string result=mysolution.getHint(secretmy, guessmy);
    cout<<result<<endl;
}


class SolutionreorderList {
public:
    /*
     if (head == null || head.next == null)
     return;
     
     // step 1. cut the list to two halves
     // prev will be the tail of 1st half
     // slow will be the head of 2nd half
     ListNode prev = null, slow = head, fast = head, l1 = head;
     
     while (fast != null && fast.next != null) {
     prev = slow;
     slow = slow.next;
     fast = fast.next.next;
     }
     
     prev.next = null;
     
     // step 2. reverse the 2nd half
     ListNode l2 = reverse(slow);
     
     // step 3. merge the two halves
     merge(l1, l2);
     }
     
     ListNode reverse(ListNode head) {
     ListNode prev = null, curr = head, next = null;
     
     while (curr != null) {
     next = curr.next;
     curr.next = prev;
     prev = curr;
     curr = next;
     }
     
     return prev;
     }
     
     void merge(ListNode l1, ListNode l2) {
     while (l1 != null) {
     ListNode n1 = l1.next, n2 = l2.next;
     l1.next = l2;
     
     if (n1 == null)
     break;
     
     l2.next = n1;
     l1 = n1;
     l2 = n2;
     }
     }
     */
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return;
        
        ListNode* prev=NULL;
        ListNode *head1,* head2;
        head1=head;
        ListNode* slow=head,*fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        prev->next=NULL;
        
        head2=reverselist(slow);
        merge(head1,head2);
    }
    
    ListNode* reverselist(ListNode* lhead)
    {
        if(lhead==NULL||lhead->next==NULL)
            return lhead;
        
        ListNode* nhead;
        ListNode* templ,* tempe;
        templ=lhead;
        nhead=lhead;
        tempe=lhead->next;
        
        while(tempe!=NULL)
        {
            templ->next=tempe->next;
            tempe->next=nhead;
            nhead=tempe;
            tempe=templ->next;
        }
        return nhead;
    }
    
    ListNode* merge(ListNode* list1,ListNode* list2)
    {
        
        ListNode* temp1, *temp2, *temp1Next,*temp2Next;
        ListNode* currentHead, *currentEnd;
        
        
        if(list1==NULL||list2==NULL)
            return list1;
        
        currentHead=list1;
        currentEnd=list2;
        temp1=list1->next;
        temp2=list2->next;
        currentHead->next=currentEnd;
        currentEnd->next=NULL;
        
        while(temp1!=NULL)
        {
            if(temp2!=NULL)
            {
                temp1Next=temp1->next;
                temp2Next=temp2->next;
            
                currentEnd->next=temp1;
                temp1->next=temp2;
                temp2->next=NULL;
                currentEnd=temp2;
                
                temp1=temp1Next;
                temp2=temp2Next;
            }
            else
            {
                
                currentEnd->next=temp1;
                temp1->next=NULL;
                break;

            }
            
            
        }
        
        if(temp2!=NULL)
        {
            currentEnd->next=temp2;
        }
        
        return currentHead;
    }
    
    
};

/*
 class Solution {
 public:
 ListNode* mergeKLists(vector<ListNode*>& lists) {
 return partition(lists, 0, lists.size()-1);
 }
 
 ListNode* partition(vector<ListNode*>& lists, int start, int end){
 if(start == end){
 return lists[start];
 }
 
 if(start < end){
 int mid = (end+start)/2;
 
 ListNode* l1 = partition(lists, start, mid);
 ListNode* l2 = partition(lists, mid+1, end);
 return merge(l1, l2);
 }
 
 return NULL;
 }
 
 ListNode* merge(ListNode* l1, ListNode* l2){
 if(!l1) return l2;
 if(!l2) return l1;
 
 if(l1->val < l2->val){
 l1->next = merge(l1->next, l2);
 return l1;
 }else{
 l2->next = merge(l1, l2->next);
 return l2;
 }
 }
 };
 */


void testSolutionreorderList(){
    SolutionreorderList solution;
    ListNode a(1),b(2),c(3);
    ListNode* head;
    head=&a;
    a.next=&b;
    b.next=&c;
    solution.reorderList(head);
    while(head!=NULL)
    {
        cout<<head->val<<endl;
        head=head->next;
    }
}

class SolutionbulbSwitch {
public:
    int bulbSwitch(int n) {
        int i,j,k;
        bool* state;
        int onnumber;
        
        onnumber=0;
        state=new bool[n];
        
        for(i=0;i<n;i++)
        {
            state[i]=false;
        }
        
        for(j=1;j<=n;j++)
        {
            for(k=-1+j;k<n;k+=j)
            {
                state[k]=!state[k];
            }
            
            /*
            for(i=0;i<n;i++)
                cout<<state[i]<<',';
            cout<<endl;
             */
        }
        
        for(i=0;i<n;i++)
        {
            if(state[i])onnumber++;
        }
        
        return onnumber;
    }
};

class SolutionbulbSwitch2 {
public:
    int bulbSwitch(int n) {
        int i;
        for(i=1;i*i<=n;i++);
        return i-1;
    }
};


void testSolutionbulbSwitch()
{
    SolutionbulbSwitch solution;
    cout<<solution.bulbSwitch(3)<<endl;
}

class SolutionnthUglyNumber {
public:
    int nthUglyNumber(int n) {
        
        vector<int> results(1,1);
        
        int i=0,j=0,k=0;
        
        while(results.size()<n)
        {
            int currentnum=min(results[i]*2,min(results[j]*3,results[k]*5));
           
            if(currentnum==results[i]*2)++i;
            
            if(currentnum==results[j]*3)++j;
            
            if(currentnum==results[k]*5)++k;
            
            results.push_back(currentnum);
            
        }
        
        return results.back();
        
    }
};

void testSolutionnthUglyNumber()
{
    SolutionnthUglyNumber solution;
    cout<<solution.nthUglyNumber(5)<<endl;
}

class SolutionnthSuperUglyNumber {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> superUglyNumbers;
        superUglyNumbers.push_back(1);
        
        int numPrimes=(int)primes.size();
        
        vector<int> idxs(numPrimes,0);
        
        while(superUglyNumbers.size()<n)
        {
            int currentnum= superUglyNumbers[idxs[0]]*primes[0]; //next super ugly number
            
            for(int i=0;i<numPrimes;i++)
            {
                currentnum = min(currentnum, superUglyNumbers[idxs[i]]*primes[i]);
            }
            
            for(int i=0;i<numPrimes;i++)
            {
                if(currentnum == superUglyNumbers[idxs[i]]*primes[i])
                {
                    idxs[i]++;
                }
            }
            
             superUglyNumbers.push_back(currentnum);
            
        }
        
        
        return superUglyNumbers[n-1];
    }
};


int SolutionmaxCoins(vector<int>& nums) {
    int N = (int)nums.size();
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);
    
    // rangeValues[i][j] is the maximum # of coins that can be obtained
    // by popping balloons only in the range [i,j]
    vector<vector<int>> rangeValues(nums.size(), vector<int>(nums.size(), 0));
    
    // build up from shorter ranges to longer ranges
    for (int len = 1; len <= N; ++len) {
        for (int start = 1; start <= N - len + 1; ++start) {
            int end = start + len - 1;
            // calculate the max # of coins that can be obtained by
            // popping balloons only in the range [start,end].
            // consider all possible choices of final balloon to pop
            int bestCoins = 0;
            for (int final = start; final <= end; ++final) {
                int coins = rangeValues[start][final-1] + rangeValues[final+1][end]; // coins from popping subranges
                coins += nums[start-1] * nums[final] * nums[end+1]; // coins from final pop
                if (coins > bestCoins) bestCoins = coins;
            }
            rangeValues[start][end] = bestCoins;
        }
    }
    return rangeValues[1][N];
}


class SolutionmaxProduct {
public:
    int maxProduct(vector<string>& words) {
        int nsize=(int)words.size();
        
        vector<int> keys(nsize,0);
        
        for(int i=0;i<nsize;i++)
        {
            for(auto c:words[i])
            {
                keys[i]|=1<<(c-'a');
            }
        }
        
        int res=0;
        int m,n;
        
        for(int i=0;i<nsize;i++)
            for(int j=i+1;j<nsize;j++)
            {
                
                
                if((keys[i]&keys[j])==0)
                {
                    m=(int)words[i].size();
                    n=(int)words[j].size();
                    if(m*n>res)
                        res=m*n;
                }
            }
        
        return res;
    }
};


void testmaxProduct(){
    vector<string> words;
    SolutionmaxProduct myproduct;
    string mystr[]={"abcw","baz","foo","bar","xtfn","abcdef"};
    words.assign(mystr,mystr+6);
    cout<<myproduct.maxProduct(words)<<endl;
    
}

class SolutionlengthOfLIS {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> tails;
        tails.reserve(nums.size());
        tails.push_back(nums.front());
        
        for (size_t i = 1; i < nums.size(); ++i) {
            const int& n = nums[i];
            auto iter = lower_bound(tails.begin(), tails.end(), n);
            if (iter == tails.end())
                tails.push_back(n);
            else if (n < *iter)
                *iter = n;
        }
        return (int)tails.size();
    }
};

class SolutionisPowerOfThree {
public:
    bool isPowerOfThree(int n) {
         return n > 0 && 3486784401 % n == 0;
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
class SolutionisPalindrome {//O(n) time and O(1) space solution
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head -> next) return true;
        ListNode* pointer_slow = head,*pointer_fast = head;
        while(pointer_fast && pointer_fast -> next) {
            pointer_slow = pointer_slow -> next;
            pointer_fast = pointer_fast -> next -> next;
        }
        if(pointer_fast) pointer_slow = reverseList(pointer_slow -> next);//reverse the last half of the list
        else pointer_slow = reverseList(pointer_slow);
        while(pointer_slow) {
            if(head -> val != pointer_slow -> val) return false;
            head = head -> next;
            pointer_slow = pointer_slow -> next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        if(!head -> next) return head;
        ListNode* pre = head -> next;
        head -> next = NULL;
        ListNode* temp;
        while(pre) {
            temp = pre -> next;
            pre -> next = head;
            head = pre;
            pre = temp;
        }
        return head;
    }
};

class solution_wordPattern{
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> c_to_str;
        unordered_set<string> used_strs;
        stringstream ss(str);
        string s;
    
        for(auto c : pattern)
        {
        // if test string used up, return false
            if(!(ss >> s))
                return false;
        // if we meet a new char in pattern, record the char-word pair
            if (c_to_str.count(c) == 0)
            {
            // if the word is used for other char before, return false
                if (!used_strs.insert(s).second)
                    return false;
                c_to_str.emplace(c, s);
            }
            // otherwise, we check if the char matches to the same word as before
            else if (c_to_str[c] != s)
                return false;
        }
        // if the test string is not used up, the match fails
        return !(ss >> s);
        
        
        /*
         
         map<char, int> p2i;
         map<string, int> w2i;
         istringstream in(str);
         int i = 0, n = pattern.size();
         for (string word; in >> word; ++i) {
         if (i == n || p2i[pattern[i]] != w2i[word])
         return false;
         p2i[pattern[i]] = w2i[word] = i + 1;
         }
         return i == n;
         
         */
    }
};


class SolutionwordPattern2 {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> p2i;
        unordered_map<string, int> w2i;
        istringstream in(str);
        int i = 0;
        int n = (int)pattern.size();
        for (string word; in >> word; ++i) {
            if (i == n || p2i[pattern[i]] != w2i[word])
                return false;
            p2i[pattern[i]] = w2i[word] = i;
        }
        return i == n;
    }
};

class SolutionfindSubstring {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> map;
        int i, wSize = (int)words.size(), wL=(int)words[0].size(), start, cur, sL=(int)s.size(), wCnt;
        vector<int> res;
        if(sL<wL*wSize) return res;
        
        //build the map
        for(i=0; i<wSize; ++i)
            map[words[i]] = map.count(words[i])>0? ++map[words[i]]:1;
        
        for(i=0; i<wL; ++i)
        {// go through each possible starting point sequences
            start = cur = i; // start is the starting point of the current search window, cur is the end of the current search window
            wCnt = wSize; // reset the words to be searched
            while(start<=sL-wL*wSize)
            { // if it is a valid start
                if(map.count(s.substr(cur,wL))==0){// if the current word is not one in the map, then move the starting window to the next word positon, reset wCnt and recover map counts.
                    for(wCnt = wSize; start!=cur; start+=wL) ++map[s.substr(start,wL)];
                    start +=wL; //skip the current invalid word;
                }
                else if(map[s.substr(cur,wL)]==0){
                    // if the current word is a valid word in the map, but it is already found in the current search window, then we have to move start to skip the previously found one, and update wCnt and map counts accordingly.
                    for(;s.substr(cur,wL)!=s.substr(start,wL); start+=wL)
                    {
                        ++map[s.substr(start,wL)];
                        ++wCnt;
                    }
                    start += wL;//skip the previously found one
                }
                else{
                    // if the current word is a valid one and it is not found before in the current search window
                    --map[s.substr(cur,wL)]; // then reduce its counter
                    if(--wCnt == 0) { // update wCnt, if we find all the words
                        res.push_back(start); // save start
                        ++map[s.substr(start,wL)]; //moving start to skip the first word in the current search window
                        start +=wL;
                        ++wCnt;
                    }
                }
                cur+=wL; // update cur
            }
            for(;start<cur;start+=wL)  ++map[s.substr(start,wL)];//reset the map count
        }
        return res;
    }
};

class SolutionfindSubstring2 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counts;
        for (string word : words)
            counts[word]++;
        int n = (int)s.length(), num = (int)words.size(), len = (int)words[0].length();
        vector<int> indexes;
        for (int i = 0; i < n - num * len + 1; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < num; j++) {
                string word = s.substr(i + j * len, len);
                if (counts.find(word) != counts.end()) {
                    seen[word]++;
                    if (seen[word] > counts[word])
                        break;
                }
                else break;
            }
            if (j == num) indexes.push_back(i);
        }
        return indexes;
    }
};

class SolutionfindSubstring3{
public:
    vector<int> findSubstring(string s, vector<string>& words){
        unordered_map<string,int> counts;
        vector<int> indexes;
        unordered_map<string, int> seen;
        
        int len=(int)words[0].length();
        for(string word: words)
        {
            if(len!=word.size())
                return indexes;
            counts[word]++;
        }
        
        int n=(int)s.length();
        int num=(int)words.size();
        
        for(int i=0;i<n-num*len+1;i++){
            seen.clear();
            int j=0;
            for(;j<num;j++){
                string word=s.substr(i+j*len,len);
                if(counts.find(word)!=counts.end()){
                    seen[word]++;
                    if(seen[word] > counts[word])
                        break;
                }
                else
                    break;
            }
            if(j == num) indexes.push_back(i);
        }
        
        return indexes;
    }
    
};

class SolutiongroupAnagrams {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string> > allstrs;
        vector<vector<string> > result;
        int i=0;
        for(string s: strs)
        {
            sort(s.begin(),s.end());
            allstrs[s].push_back(strs[i++]);
        }
        
        
        for(auto n: allstrs){
            sort(n.second.begin(),n.second.end());
            result.push_back(n.second);
        }
        
        return result;
    }
};

class SolutioncountPrimes1 {
public:
    int countPrimes(int n) {
        int count=0;
        for(int i=0;i<n;i++)
        {
            double sqrtn=sqrt(n*1.0);
            for(int j=2;j<=sqrtn;j++)
            {
                if(i%j==0)
                {
                    count++;
                    break;
                }
            }
        }
        
        return count;
    }
};

class SolutioncountPrimes2 {
public:
    int countPrimes(int n){
        int max=n;
        vector<bool> flags;
        flags.assign(max+1,true);
        
        int count=0;
        int prime=2;
        while(prime<=sqrt(max))
        {
            crossOff(flags,prime);
            prime=getNextPrime(flags,prime);
            if(prime>=flags.size()){
                break;
            }
        }
        
        int countNum=0;
        for(int i=1;i<max;i++)
            if(flags[i])
                countNum++;
        
        return countNum;
    }
    
    void crossOff(vector<bool> flags, int prime)
    {
        for(int i=prime*prime;i<flags.size();i+=prime){
            flags[i]=false;
        }
    }
    
    int getNextPrime(vector<bool> flags,int prime){
        int next=prime+1;
        while(next<flags.size()&&!flags[next]){
            next++;
        }
        return next;
    }
    
   
};

class SolutioncountPrimes3 {
public:
    int countPrimes(int n) {
        if(--n < 2) return 0;
        int m = (n + 1)/2, count = m, k, u = (sqrt(n) - 1)/2;
        vector<bool> notPrime;
        notPrime.assign(m,0);
        
        for(int i = 1; i <= u;i++)
            if(!notPrime[i])
                for(k = (i+ 1)*2*i; k < m;k += i*2 + 1)
                    if (!notPrime[k])
                    {
                        notPrime[k] = true;
                        count--;
                    }
        return count;
    }
};

class SolutioncountPrimes4{
public:
    int countPrimes(int n){
        if(--n < 2)return 0;
        int m = (n+1)/2;
        int count = m;
        int k;
        int u=(sqrt(n)-1)/2;
        vector<bool> notPrime;
        notPrime.assign(m,0);
        
        for(int i=1;i<=u;i++)
        {
            if(!notPrime[i])
                for(k=(i+1)*2*i;k<m;k+=i*2+1)
                {
                    if(!notPrime[k])
                    {
                        notPrime[k]=true;
                        count--;
                    }
                }
        }
        
        return count;
    }
};


class SolutioncountPrimes5{
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        int res=n>>1, m=sqrt(n-1); // intilize res to n/2, removes all even number(not 2) and 1
        bool *table=new bool[n];
        for(int i=3,j,step;i<=m;i+=2)
            if(!table[i]) { // i is an odd prime
                for(step=i<<1, j=i*i;j<n;j+=step) // step=i*2, ignore even numbers
                    if(!table[j]) { table[j]=1; --res; }
            }
        delete []table;
        return res;
    }

};

class SolutioncountPrimes6{
    
    /*
     1. trick1 is to use square root of n.
     2. trick2 is not to use non-prime numbers as the step
     3. trick3 is to use i*i as the start.
     4. trick4 is to use count-- in every loop, avoiding another traversal.
    */
    
    int countPrimes(int n) {
        if(n <= 2) return 0;
        if(n == 3) return 1;
        vector<bool> prime;
        prime.assign(n,false);
       
        int i=0,j=0;
        int count = n-2;
        int rt = sqrt(n);
        for(j = 0; j < n; j++)
        {
            prime[j] = true;
        }
        for(i = 2; i <= rt; i++)
        {
            if (prime[i])
            {
                for(j=i*i; j<n; j+=i)
                {
                    if (prime[j])
                    {
                        prime[j]=false;
                        count--;
                    }
                }
            }
        }
        
        return count;
    }
};


/*
 
 class Solution:
 # @param {integer} n
 # @return {integer}
 def countPrimes(self, n):
 if n < 3:
 return 0
 primes = [True] * n
 primes[0] = primes[1] = False
 for i in range(2, int(n ** 0.5) + 1):
 if primes[i]:
 primes[i * i: n: i] = [False] * len(primes[i * i: n: i])
 return sum(primes)
 
*/

class SolutionfindRepeatedDnaSequences {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<bool> allstr;
        vector<bool> currentstr;
        int maxsize=1<<20;
        
        allstr.assign(maxsize,false);
        currentstr.assign(maxsize,false);
        
        vector<string> returnVector;
        for(int i=0;i+9<s.length();i++)
        {
            string temp=s.substr(i,10);
            int currentint=hashnumber(temp);
            if(allstr[currentint]==true)
            {
                if(currentstr[currentint]==false)
                {
                    returnVector.push_back(temp);
                    currentstr[currentint]=true;
                }
            }
            else
            {
                allstr[currentint]=true;
            }
        }
        
        //copy(returnStr.begin(),returnStr.end(),returnVector.begin());
       
        return returnVector;
    }
    
    string backtemp(int nums)
    {
        string tempstr;
        int step=0;
        while(step<10)
        {
            int temp=nums&3;
            switch(temp)
            {
                case 0:
                    tempstr='A'+tempstr;
                    break;
                case 1:
                    tempstr='C'+tempstr;
                    break;
                case 2:
                    tempstr='G'+tempstr;
                    break;
                case 3:
                    tempstr='T'+tempstr;
                    break;
            }
            nums>>=2;
            step++;
        }
        
        return tempstr;
        
    }
    
    int hashnumber(string temp)
    {
        int nums=0;
        int current=0;
        for(auto k:temp)
        {
            switch(k){
                case 'A':
                    current=0;
                    break;
                case 'C':
                    current=1;
                    break;
                case 'G':
                    current=2;
                    break;
                case 'T':
                    current=3;
                    break;
            }
            nums<<=2;
            nums+=current;
           
        }
        return nums;
    }
};


class SolutionfindRepeatedDnaSequences2 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10)
            return vector<string>();
        
        vector<string> R;;
        bitset<(1<<20)-1> S1;
        bitset<(1<<20)-1> S2;
        
        int val = 0;
        for (int i=0; i < 10; i++)   // Calc. the has value for the first string.
            val = (val << 2) | char2val(s[i]);
        S1.set(val);
        
        cout << val << " | ";
        
        int mask = (1 << 20) - 1;
        for (int i=10; i < s.size(); i++)
        {
            // Calc the hash value for the string ending at position i.
            val = ((val << 2) & mask) | char2val(s[i]);
            if (S2[val])
                continue;
            if (S1[val])
            {
                R.push_back(s.substr(i-10+1, 10));
                S2.set(val);
            }
            else
                S1.set(val);
        }
        return R;
    }
    
    int char2val(char c) {
        switch (c) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }
        return 0;
    }
};


/*
 vector<string> findRepeatedDnaSequences(string s) {
 char flag[262144] ={0};
 vector<string> result;
 int len,DNA=0,i;
 if((len=s.length())< 11) return result;
 for(i = 0 ; i < 9; i++)
 DNA = DNA << 2| (s[i] - 'A' + 1) % 5;
 for(i = 9;i<len;i++)
 {
 DNA = (DNA<<2 & 0xFFFFF)|(s[i] - 'A' + 1)%5;
 if(!(flag[DNA>>2]&(1<<((DNA&3) << 1))))
 flag[DNA>>2] |= (1<<((DNA&3) << 1));
 else if(!(flag[DNA>>2]&(2<<((DNA&3) << 1))))
 {
 result.push_back(s.substr(i-9,10));
 flag[DNA>>2] |= (2<<((DNA&3) << 1));
 }
 }
 return result;
 }
 */

/*
 int maximalRectangle(vector<vector<char>>& matrix) {
 if(matrix.size()==0) return 0;
 
 int ans = 0, m = matrix.size(), n = matrix[0].size();
 vector<int> height(n,0); // height
 
 for(int i=0;i<m;i++){
 for(int j=0;j<n;j++){
 if(matrix[i][j]=='0') {
 height[j] = 0;
 continue;
 }
 height[j]++;
 for(int cur = j-1, pre = height[j]; cur>=0; cur--){
 if ( height[cur] == 0 ) break;
 pre = min(pre,height[cur]);
 ans = max(ans, (j-cur+1)*pre);
 }
 ans = max(ans, height[j]);
 }
 }
 return ans;
 }
 */

class SolutionmaximalRectangle2 {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if(matrix.size()==0) return 0;
        
        int ans = 0;
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        vector<int> height(n,0); // height
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0') {
                    height[j] = 0;
                    continue;
                }
                height[j]++;
                for(int cur = j-1, pre = height[j]; cur>=0; cur--){
                    if ( height[cur] == 0 ) break;
                    pre = min(pre,height[cur]);
                    ans = max(ans, (j-cur+1)*pre);
                }
                ans = max(ans, height[j]);
            }
        }
        return ans;
        
    }
    
};

struct Point{
    int x;
    int y;
    Point():x(0),y(0){}
    Point(int a,int b):x(a),y(b){}
};

class SolutionmaxPoints{
public:
    int maxPoints(vector<Point>& points)
    {
        if(points.size()<=0)
            return 0;
        if(points.size()<=2)
            return (int)points.size();
        
        int result=0;
        for(int i=0;i<points.size();i++)
        {
            unordered_map<double,int> hm;
            int samex=1;
            int samep=0;
            for(int j=0;j<points.size();j++)
            {
                if(j!=i){
                    if((points[j].x==points[i].x)&&(points[j].y==points[i].y))
                    {
                        samep++;
                    }
                    if(points[j].x==points[i].x)
                    {
                        samex++;
                        continue;
                    }
                    
                    double k = (double)(points[j].y - points[i].y) / (double)(points[j].x - points[i].x);
                    if(hm.find(k)!=hm.end()){
                        hm[k]=hm[k] + 1;
                    }else{
                        hm[k]=2;
                    }
                    result = max(result, hm[k] + samep);
                }
            }
            
            result=max(result,samex);
        }
        
        return result;
    }
};

class SolutioncountDigitOne {
public:
    int countDigitOne(int n) {
        
         if (n <= 0) return 0;
         int q = n, x = 1, ans = 0;
         do {
         int digit = q % 10;
         q /= 10;
         ans += q * x;
         if (digit == 1) ans += n % x + 1;
         if (digit >  1) ans += x;
         x *= 10;
         } while (q > 0);
         return ans;
        
    }
};

class SolutioncountDigitOne2 {
public:
    int countDigitOne(int n) {
        
        if(n<1)
            return 0;
        
        if(n>=1&&n<10)
            return 1;
        
        int y=1,x=n;
        while(!(x<10))
        {
            x/=10;
            y*=10;
        }
        
        if(x==1)
            return n-y+1+countDigitOne(y-1)+countDigitOne(n%y);
        else
            return y+x*countDigitOne(y-1)+countDigitOne(n%y);
    }
};

class SolutioncountDigitOne3{
    int countDigitOne(int n, int x){
        if(n == 0) return 0;
        if(n<10 || x==1) return 1;
        if(n/x == 1) return n-n/x*x+1+countDigitOne(n-n/x*x)+countDigitOne(x-1);
        return x+n/x*countDigitOne(x-1)+countDigitOne(n-n/x*x);
    }
    
    int countDigitOne(int n) {
        if(n <= 0) return 0;
        int x = 1, y=n;
        for(;y>=10;x*=10,y/=10);
        return countDigitOne(n, x);
    }
};

void findAllKs(){
    SolutionmaxPoints solution;
    vector<Point> allPoints;
    allPoints.push_back(Point(4,0));
    allPoints.push_back(Point(4,-1));
    allPoints.push_back(Point(4,5));
    int numofPoints=solution.maxPoints(allPoints);
    cout<<numofPoints<<endl;
}
/*
public class Solution {
    public int maxPoints(Point[] points) {
        if(points.length <= 0) return 0;
        if(points.length <= 2) return points.length;
        int result = 0;
        for(int i = 0; i < points.length; i++){
            HashMap<Double, Integer> hm = new HashMap<Double, Integer>();
            int samex = 1;
            int samep = 0;
            for(int j = 0; j < points.length; j++){
                if(j != i){
                    if((points[j].x == points[i].x) && (points[j].y == points[i].y)){
                        samep++;
                    }
                    if(points[j].x == points[i].x){
                        samex++;
                        continue;
                    }
                    double k = (double)(points[j].y - points[i].y) / (double)(points[j].x - points[i].x);
                    if(hm.containsKey(k)){
                        hm.put(k,hm.get(k) + 1);
                    }else{
                        hm.put(k, 2);
                    }
                    result = Math.max(result, hm.get(k) + samep);
                }
            }
            result = Math.max(result, samex);
        }
        return result;
    }
}
*/

class SolutionoddEvenList {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* head_odd,* head_even;
        ListNode* head_odd_first,* head_even_first;
        ListNode* head_odd_end,* head_even_end;
        ListNode* temp_head_odd,* temp_head_even;
        
        head_odd=head;
        if(head_odd==NULL)
            return NULL;
        
        head_even=head->next;
        if(head_even==NULL)
            return head_odd;
        
        head_odd_first=head_odd_end=head_odd;
        head_odd_end->next=NULL;
        
        head_even_first=head_even_end=head_even;
        
        while(1)
        {
            temp_head_odd=head_even_end->next;
            if(temp_head_odd==NULL)
            {
                head_odd_end->next=head_even_first;
                return head_odd_first;
            }
            
            temp_head_even=temp_head_odd->next;
            if(temp_head_even==NULL)
            {
                head_odd_end->next=temp_head_odd;
                head_odd_end=temp_head_odd;
                
                head_odd_end->next=head_even_first;
                head_even_end->next=NULL;
                return head_odd_first;
            }
            
            
            head_even_end->next=temp_head_even;
            head_even_end=head_even_end->next;
            head_even_end->next=temp_head_even->next;
            
            
            head_odd_end->next=temp_head_odd;
            head_odd_end=head_odd_end->next;
            head_odd_end->next=NULL;
            
        }
        
        return NULL;
    }
};

void testSolutionoddEvenList(){
    SolutionoddEvenList solution;
    ListNode a(1),b(2),c(3),d(4),e(5);
    ListNode* head=&a;
    a.next=&b;
    b.next=&c;
    c.next=&d;
    d.next=&e;
    
    ListNode* temp=solution.oddEvenList(head);
    while(temp!=NULL)
    {
        cout<<temp->val<<endl;
        temp=temp->next;
    }
    
    
}
void testSolutionfindRepeatedDnaSequences()
{
    SolutionfindRepeatedDnaSequences mySolution;
    string s="GAGAGAGAGAGAG";
    vector<string> mystr=mySolution.findRepeatedDnaSequences(s);
    for(auto currentstr:mystr)
    {
        cout<<currentstr<<endl;
    }
}

class SolutionfourSum {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > total;
        int n=(int)nums.size();
        if(n<4) return total;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1])
                continue;
            
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target)
                break;
            
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target)
                continue;
            
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                
                int left=j+1, right=n-1;
                while(left<right)
                {
                    int sum=nums[left]+nums[right]+nums[i]+nums[j];
                    if(sum<target)
                        left++;
                    else
                        if(sum>target)
                            right--;
                        else
                        {
                            total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                            do
                            {
                            left++;
                            }
                            while(nums[left]==nums[left-1]&&left<right);
                        
                            do
                            {
                                right--;
                            }
                            while(nums[right]==nums[right+1]&&left<right);
                        
                    }
                }
            }
        }
        
        return total;
    }
};



/*
 public class Solution {
 public ListNode mergeKLists(ListNode[] lists) {
 
 Queue<ListNode> q = new PriorityQueue<ListNode>(new ListComparator());
 for(ListNode n: lists){
 if( n!= null) {
 q.add(n);
 }
 }
 ListNode head = new ListNode(0), p = head, cur = null;
 while( !q.isEmpty()) {
 cur = q.poll();
 if(cur.next!=null)
 q.offer(cur.next);
 p.next = cur;
 p = p.next;
 }
 return head.next;
 }
 }
 
 class ListComparator implements Comparator<ListNode>{
 
 @Override
 public int compare(ListNode n1, ListNode n2) {
 return n1.val - n2.val;
 }
 */
class SolutionPlusOne{
vector<int> plusOne(vector<int>& digits) {
    
    int n = (int)digits.size();
    for(int i=n-1; i>=0; i--) {
        if(digits[i] < 9) {
            digits[i]++;
            return digits;
        }
        
        digits[i] = 0;
    }
    
    vector<int> newNumber;
    newNumber.assign(n+1,0);
    newNumber[0] = 1;
    
    return newNumber;
}
};




//delete the first line
//use the keyboard and mouse to delete the first line

/*
 
 (p justify-xaxis1
 =goal>
 isa best-point
 state read-xaxis
 timestamp =currenttime
 =imaginal>
 timestamp =currenttime
 ==>
 =goal>
 state read-line
 !output!(=currenttime)
 -visual-location>
 -visual>
 )
 
 (p justify-xaxis2
 =goal>
 isa best-point
 state read-xaxis
 timestamp =currenttime
 =imaginal>
 < timestamp =currenttime
 ==>
 =goal>
 state search-down-xaxis
 !output!(=currenttime)
 -visual-location>
 -visual>
 )
 
 (p justify-xaxis3
 =goal>
 isa best-point
 state read-xaxis
 timestamp =currenttime
 =imaginal>
 > timestamp =currenttime
 ==>
 =goal>
 state search-up-xaxis
 !output!(=currenttime)
 -visual-location>
 -visual>
 )
 
 */

/*
 public static ListNode mergeKLists(ListNode[] lists){
 return partion(lists,0,lists.length-1);
 }
 
 public static ListNode partion(ListNode[] lists,int s,int e){
 if(s==e)  return lists[s];
 if(s<e){
 int q=(s+e)/2;
 ListNode l1=partion(lists,s,q);
 ListNode l2=partion(lists,q+1,e);
 return merge(l1,l2);
 }else
 return null;
 }
 
 //This function is from Merge Two Sorted Lists.
 public static ListNode merge(ListNode l1,ListNode l2){
 if(l1==null) return l2;
 if(l2==null) return l1;
 if(l1.val<l2.val){
 l1.next=merge(l1.next,l2);
 return l1;
 }else{
 l2.next=merge(l1,l2.next);
 return l2;
 }
 }
 */
class SolutionmergeKLists {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        return partion(lists,0,(int)lists.size()-1);
    }
    ListNode* partion(vector<ListNode*>& lists, int s,int e)
    {
        if(s==e) return lists[s];
        if(s<e)
        {
            int middle=(s+e)/2;
            ListNode* l1=partion(lists,s,middle);
            ListNode* l2=partion(lists,middle+1,e);
            return mergeLists(l1,l2);
            
        }
        else
            return NULL;
    }
    ListNode* mergeLists(ListNode* l1,ListNode* l2)
    {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        if(l1->val<l2->val)
        {
            l1->next=mergeLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next=mergeLists(l1, l2->next);
            return l2;
        }
        
    }
    
};

class SolutionCalculate{
    int calculate(string s)
    {
    stack<int> myStack;
    char sign = '+';
    int res = 0, tmp = 0;
    for (unsigned int i = 0; i < s.size(); i++) {
        if (isdigit(s[i]))
            tmp = 10*tmp + s[i]-'0';
        if ((!isdigit(s[i]) && !isspace(s[i]) )|| i == (int)s.size()-1) {
            if (sign == '-')
                myStack.push(-tmp);
                else if (sign == '+')
                    myStack.push(tmp);
                    else {
                        int num;
                        if (sign == '*' )
                            num = myStack.top()*tmp;
                        else
                            num = myStack.top()/tmp;
                        myStack.pop();
                        myStack.push(num);
                    }
            sign = s[i];
            tmp = 0;
        }
    }
    while (!myStack.empty()) {
        res += myStack.top();
        myStack.pop();
    }
    return res;
    }
};

class SolutionCalculate2 {
public:
    int calculate(string s) {
        if(s.empty())
            return 0;
        int length=(int)s.size();
        int res=0;
        long preVal=0;
        char sign='+';
        
        int i=0;
        while(i<length)
        {
            long curVal=0;
           
            while(i<length&&isspace(s[i]))
            {
                i++;
            }
            
            while(i<length&&isdigit(s[i]))
            {
                curVal=curVal*10+(s[i]-'0');
                i++;
                //cout<<curVal<<endl;
            }
            if(sign=='+')
            {
                
                res+=preVal;
                preVal=curVal;
                //cout<<"res: "<<res<<",preVal:"<<preVal<<endl;
            }
            else
                if(sign=='-')
                {
                    res+=preVal;
                    preVal=-curVal;
                }
                else
                    if(sign=='*')
                    {
                        preVal=preVal*curVal;
                    }
                    else
                        if(sign=='/'){
                            //cout<<"pre: "<<preVal<<','<<curVal<<','<<preVal/curVal<<endl;
                            preVal=preVal/curVal;
                            
                        }
            
            while(i<length&&isspace(s[i]))
            {
                i++;
            }
            
            if(i<length&&!isspace(s[i]))
            {
                sign=s[i];
                i++;
            }
            
            while(i<length&&isspace(s[i]))
            {
                i++;
            }
           
           
        }
        
        res+=preVal;
        return res;
    }
};

void testCalculate()
{
    string s=" 3+5 / 2 ";
    SolutionCalculate2 solution;
    int res=solution.calculate(s);
    cout<<res<<endl;
    
}


class NumArray {
public:
    vector<vector<int> > allnums;
    int nsize;
    NumArray(vector<int> &nums) {
        int i,j;
        nsize=(int)nums.size();
        allnums.assign(nsize,vector<int>(nsize));
        for(i=0;i<nsize;i++)
        {
            allnums[i][i]=nums[i];
        }
        for(i=0;i<nsize;i++)
            for(j=i+1;j<nsize;j++)
            {
                allnums[i][j]=allnums[j][j]+allnums[i][j-1];
            }
        
    }
    
    int sumRange(int i, int j) {
        return allnums[i][j];
    }
};

class solutionmaxProfit{
public:
    int maxProfit(vector<int>& prices){
        int minPrice, maxProfit;
        int nsize=(int)prices.size();
        if(nsize<2)
            return 0;
        minPrice=prices[0];
        maxProfit=0;
        for(int i=1;i<nsize;i++)
        {
            if(maxProfit<(prices[i]-minPrice))
                maxProfit=prices[i]-minPrice;
            if(prices[i]<minPrice)
                minPrice=prices[i];
        }
        return maxProfit;
    }
};

class solutionmaxProfit2{
public:
    int maxProfit(vector<int>& prices) {
        int minV = INT32_MAX, maxV = 0;
        for (int i = 0; i < prices.size(); i++)
            maxV = max(maxV, prices[i] - (minV = min(minV, prices[i])));
        return maxV;
    }
};

class SolutionmaxProfitBestTime {
public:
    int maxProfit(vector<int>& prices) {
       
        if(prices.size()<2)
            return 0;
        
        int i,nsize=(int)prices.size();
        int ret=0;
        vector<int> buy(nsize,0);
        vector<int> sell(nsize,0);
        buy[0]=-prices[0];
        
        for(i=1;i<nsize;i++)
        {
            sell[i]=max(buy[i-1]+prices[i],sell[i-1]-prices[i-1]+prices[i]);
            if(ret<sell[i])
                ret=sell[i];
            if(i==1)
                buy[i]=buy[0]+prices[0]-prices[1];
            else
                buy[i]=max(sell[i-2]-prices[i],buy[i-1]+prices[i-1]-prices[i]);
            
        }
        
        return ret;
        
    }
};

/*
 1. profit1[i+1] means I must sell on day i+1, and there are 2 cases:
 
 a. If I just sold on day i, then I have to buy again on day i and sell on day i+1
 
 b. If I did nothing on day i, then I have to buy today and sell today
 
 Taking both cases into account, profit1[i+1] = max(profit1[i]+prices[i+1]-prices[i], profit2[i])
 
 2. profit2[i+1] means I do nothing on day i+1, so it will be max(profit1[i], profit2[i])
 */
class solutionMaxProfit{
public:
    int maxProfit(vector<int>& prices)
    {
        int profit1=0, profit2=0;
        for(int i=1; i<prices.size(); i++){
            int copy=profit1;
            profit1=max(profit1+prices[i]-prices[i-1], profit2);
            profit2=max(copy, profit2);
        }
        return max(profit1, profit2);
    }
};

class solutionmaxProfits{
public:
    int maxProfit(vector<int>& prices)
    {
        int nsize=(int)prices.size();
        if(nsize<2)
            return 0;
        vector<int> state0(nsize,0), state1(nsize,0),state2(nsize,0);
        
        state0[0]=0;
        state1[0]=-prices[0];
        state2[0]=INT_MIN;
        
        for(int i=1;i<nsize;i++)
        {
            state0[i]=max(state0[i-1],state2[i-1]);
            state1[i]=max(state1[i-1],state0[i-1]-prices[i]);
            state2[i]=state1[i-1]+prices[i];
        }
        
        return max(state0[nsize-1],state2[nsize-1]);
        
    }
};

class NumArray2{
public:
    vector<int> sums;
    NumArray2(vector<int>& nums)
    {
        sums.insert(sums.begin(),nums.begin(),nums.end());
        int nsize=(int)nums.size();
        for(int i=1;i<nsize;i++)
        {
            sums[i] += sums[i-1];
            
        }
        
    }
    int sumRange(int i,int j){
        return i==0?sums[j]:sums[j]-sums[i-1];
    }
};

void testNumArray(){
    
    vector<int> nums;
    int testnums[]={-2,0,3,-5,2,-1};
    
    nums.assign(testnums,testnums+6);
    NumArray mysolution(nums);
    
    cout<<mysolution.sumRange(0,2)<<endl;
    cout<<mysolution.sumRange(2,5)<<endl;
    cout<<mysolution.sumRange(0,5)<<endl;
    
}


class NumMatrix {
public:
    vector<vector<int> > allnums;
    NumMatrix(vector<vector<int>> &matrix) {
        int rowsize=(int)matrix.size();
        if(rowsize<1)
            return;
        int colsize=(int)matrix[0].size();
        int i,j;
        allnums.assign(rowsize, vector<int>(colsize));
        allnums[0][0]=matrix[0][0];
        
        for(i=1;i<rowsize;i++)
        {
            allnums[i][0]=allnums[i-1][0]+matrix[i][0];
        }
        
        for(i=1;i<colsize;i++)
        {
            allnums[0][i]=allnums[0][i-1]+matrix[0][i];
        }
        
        for(i=1;i<rowsize;i++)
            for(j=1;j<colsize;j++)
            {
                allnums[i][j]=allnums[i-1][j]+allnums[i][j-1]-allnums[i-1][j-1]+matrix[i][j];
            }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if((row1>=1)&&(col1>=1))
            return allnums[row2][col2]-allnums[row1-1][col2]-allnums[row2][col1-1]+allnums[row1-1][col1-1];
        else
            if(row1>=1)
                return  allnums[row2][col2]-allnums[row1-1][col2];
            else
                if(col1>=1)
                    return allnums[row2][col2]-allnums[row2][col1-1];
                else
                    return allnums[row2][col2];
    }
};

class NumMatrix2 {
private:
    int row, col;
    vector<vector<int>> sums;
public:
    NumMatrix2(vector<vector<int>> &matrix) {
        row = (int)matrix.size();
        col = row>0 ?(int) matrix[0].size() : 0;
        sums = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        for(int i=1; i<=row; i++) {
            for(int j=1; j<=col; j++) {
                sums[i][j] = matrix[i-1][j-1] +
                sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] ;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
    }
};


void testSumRegion()
{
    vector<vector<int> > currentMatrixs;
    vector<int> a,b,c,d,e;
    int a1[5]={3,0,1,4,2};
    int b1[5]={5,6,3,2,1};
    int c1[5]={1,2,0,1,5};
    int d1[5]={4,1,0,1,7};
    int e1[5]={1,0,3,0,5};
    a.assign(a1,a1+5);
    b.assign(b1,b1+5);
    c.assign(c1,c1+5);
    d.assign(d1,d1+5);
    e.assign(e1,e1+5);
    currentMatrixs.push_back(a);
    currentMatrixs.push_back(b);
    currentMatrixs.push_back(c);
    currentMatrixs.push_back(d);
    currentMatrixs.push_back(e);
    
    NumMatrix mySolution(currentMatrixs);
    cout<<mySolution.sumRegion(2,1,4,3)<<endl;
    cout<<mySolution.sumRegion(1,1,2,2)<<endl;
    cout<<mySolution.sumRegion(1,2,2,4)<<endl;
    
}

/*

class SolutionmaxProduct2 {
public:
    int maxProduct(vector<int>& nums) {
        vector<vector<int> > allNums;
        int nsize=(int)nums.size();
        allNums.assign(nsize,vector<int>(nsize,0));
        for(int i=0;i<nsize;i++)
            allNums[i][i]=nums[i];
        for(int step=1;step<nsize;step++){
            for(int i=0;i+step<nsize;i++){
                int currentmax=max(allNums[i+1][i+step],allNums[i][i+step-1]);
                currentmax=max(currentmax,allNums[i][i+step-1]*nums[i+step]);
                allNums[i][i+step]=currentmax;
                cout<<i<<','<<i+step<<'='<<allNums[i][i+step]<<endl;
            }
        }
        return allNums[0][nsize-1];
    }
};
 */

class SolutionmaxProduct2{
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        long long curmax = nums[0], curmin = nums[0], res = nums[0];
        long long premax;
        for(int i=1; i<nums.size(); ++i){
            premax = curmax;
            curmax = max(curmax*nums[i], max(curmin*nums[i], (long long)nums[i]));
            curmin = min(premax*nums[i], min(curmin*nums[i], (long long)nums[i]));
            res = max(res, curmax);
        }
        return int(res);
    }
    

    
    int SolutionmaxProduct3(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        int ans = nums[0], cmin = ans, cmax = ans;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                cmax = max(nums[i], cmax * nums[i]);
                cmin = min(nums[i], cmin * nums[i]);
            } else {
                int tmp = cmax;
                cmax = max(nums[i], cmin * nums[i]);
                cmin = min(nums[i], tmp * nums[i]);
            }
            
            ans = max(ans, cmax);
        }
        
        return ans;
    }


};


void testSolutionmaxProduct2()
{
    SolutionmaxProduct2 mysolution;
    vector<int> nums;
    int cnums[]={2,3,-2,4};
    nums.assign(cnums,cnums+4);
    cout<<mysolution.maxProduct(nums)<<endl;
}


class SolutionmaximalSquare2 {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int maxSq=0;
        int nRow=(int)matrix.size();
        int nCol=(int)matrix[0].size();
        vector<vector<int>> dp(nRow+1,vector<int>(nCol+1,0));
        //dp[i][j] represents max square ending at position (i-1, j-1)
        for(int i=1;i<=nRow;++i){
            for(int j=1;j<=nCol;++j){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
                    maxSq=max(maxSq,dp[i][j]);
                }
            }
        }
        return maxSq*maxSq;
    }
};

class SolutioncoinChange
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; ++i)
            for (auto & c : coins)
                if (i - c >= 0 && dp[i - c] != -1)
                    dp[i] = dp[i] > 0 ? min(dp[i], dp[i - c] + 1) : dp[i - c] + 1;
        
        return dp[amount];
    }
};

class SolutioncoinChange2
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount+1,-1);
        dp[0]=0;
        
        for(int i=1; i<=amount;++i)
            for(auto &c: coins)
                if(i-c>=0 && dp[i-c]!=-1)
                {
                    if(dp[i]>0)
                        dp[i]=min(dp[i],dp[i-c]+1);
                    else
                        dp[i]=dp[i-c]+1;
                }
        
        
        return dp[amount];
    }
};


class SolutionisPalindromeNew {
public:
    bool isPalindrome(string s) {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        int nsize=(int)s.size();
        for(int i=0,j=nsize-1;i<j;i++,j--)
        {
           while(i<j&&!isalnum(s[i]))
           {
               i++;
           }
            
            while(i<j&&!isalnum(s[j]))
            {
                j--;
            }
            
            if(s[i]!=s[j])
                return false;

        }
        
        return true;
    }
};

void testSquare()
{
    SolutionmaximalSquare2 mysolution;
    vector<char> a(1,'1');
    vector<vector<char> > allnums;
    allnums.push_back(a);
    cout<<mysolution.maximalSquare(allnums)<<endl;
}



// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    int value_next;
    bool hasnext;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        hasnext = Iterator::hasNext();
        if(hasnext)
            value_next=Iterator::next();
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return value_next;
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int previous=value_next;
        hasnext=Iterator::hasNext();
        if(hasnext)
            value_next=Iterator::next();
        return previous;
    }
    
    bool hasNext() const {
        return hasnext;
    }
};


class PeekingIterator2 : public Iterator {
public:
    PeekingIterator2(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if(hasNext()){
            Iterator it(*this);
            return it.next();
        }
        else
            return 0;
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        return Iterator::next();
    }
    
    bool hasNext() const {
        return Iterator::hasNext();
    }
};

/*
 public class Solution {
 public boolean increasingTriplet(int[] nums) {
 int min = Integer.MAX_VALUE, secondMin = Integer.MAX_VALUE;
 for(int num : nums){
 if(num <= min) min = num;
 else if(num < secondMin) secondMin = num;
 else if(num > secondMin) return true;
 }
 return false;
 }
 }
 */

class SolutionincreasingTriplet {
public:
    bool increasingTriplet(vector<int>& nums) {
        int minv=INT32_MAX;
        int secondminv=INT32_MAX;
        for(auto num:nums){
            if(num <= minv)
                minv=num;
            else
                if(num<secondminv)
                    secondminv=num;
                else
                    if(num>secondminv)
                return true;
        }
        return false;
    }
};

#include<iterator>
#include<list>

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    std::list<int> mylist;
    for (int i=0; i<10; i++) mylist.push_back (i*10);
    
    std::list<int>::iterator it = mylist.begin();
    
    std::advance (it,5);
    
    std::cout << "The sixth element in mylist is: " << *it << '\n';
    
    
    std::list<int>::iterator first = mylist.begin();
    std::list<int>::iterator last = mylist.end();
    
    std::cout << "The distance is: " << std::distance(first,last) << '\n';
    
    
    std::cout << "The last element is " << *std::prev(mylist.end()) << '\n';
    //testSquare();
    //testSolutionmaxProduct2();
    //testSumRegion();
    //testNumArray();
    //testCalculate();
    //testSolutionreorderList();
    //testSolutionoddEvenList();
    //testSolutionfindRepeatedDnaSequences();
    //findAllKs();
    //testSolutiongetHint();
    //testSolutionbulbSwitch();
    //testSolutionnthUglyNumber();
    //testmaxProduct();
}


/*
 public int calculate(String s) {
 if (s == null) return 0;
 s = s.trim().replaceAll(" +", "");
 int length = s.length();
 
 int res = 0;
 long preVal = 0; // initial preVal is 0
 char sign = '+'; // initial sign is +
 int i = 0;
 while (i < length) {
 long curVal = 0;
 while (i < length && (int)s.charAt(i) <= 57 && (int)s.charAt(i) >= 48) { // int
 curVal = curVal*10 + (s.charAt(i) - '0');
 i++;
 }
 if (sign == '+') {
 res += preVal;  // update res
 preVal = curVal;
 } else if (sign == '-') {
 res += preVal;  // update res
 preVal = -curVal;
 } else if (sign == '*') {
 preVal = preVal * curVal; // not update res, combine preVal & curVal and keep loop
 } else if (sign == '/') {
 preVal = preVal / curVal; // not update res, combine preVal & curVal and keep loop
 }
 if (i < length) { // getting new sign
 sign = s.charAt(i);
 i++;
 }
 }
 res += preVal;
 return res;
 }
 */
