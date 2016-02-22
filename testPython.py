def coinChange(self, coins, amount):
    coins.sort(reverse = True)
    lenc, self.res = len(coins), 2**31-1

    def dfs(pt, rem, count):
        if not rem:
            self.res = min(self.res, count)
        for i in range(pt, lenc):
            if coins[i] <= rem < coins[i] * (self.res-count): # if hope still exists
                dfs(i, rem-coins[i], count+1)

    for i in range(lenc):
        dfs(i, amount, 0)
    return self.res if self.res < 2**31-1 else -1

class Solution(object):
    def coinChange(self, coins, amount):
        conis.sort(reverse = True)
        lenc, self.res = len(coins), 2**31-1

        def dfs(pt, rem, count):
            if not rem:
                self.res = min(self.res, count)

            for i in range(pt, lenc):
                if coints[i]<= rem < coins[i]*(self.res-count):
                    dfs(i,rem-coins[i],count+1)

        for i in range(lenc):
            dfs(i,amount,0)

        return self.res if self.res< 2**31-1 else -1
    
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
class Solution2(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        if amount == 0:
            return 0
        value1 = [0]
        value2 = []
        nc =  0
        visited = [False]*(amount+1)
        visited[0] = True
        while value1:
            nc += 1
            for v in value1:
                for coin in coins:
                    newval = v + coin
                    if newval == amount:
                        return nc
                    elif newval > amount:
                        continue
                    elif not visited[newval]:
                        visited[newval] = True
                        value2.append(newval)
            value1, value2 = value2, []
        return -1
    
import math
a=0.9
r=150
ob=500
for i in range(1,100):
    r=a*r+(1-a)*ob
    print i,r
    if (r>250):
        break
       
