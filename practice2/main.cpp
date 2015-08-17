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
unsigned int Factorial( unsigned int number ) {
    return number > 1 ? Factorial(number-1)*number:1;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
    SolutionminDistance solution;

    REQUIRE(solution.minDistance("abc","abd")==1);
}
