class Solution(object):
    def maxProfit(self, prices):
        min_price = [] #empty list
        max_profit = 0 #let max profit be 0
        for price in prices: #loop through the list
            if price < min_price:
                min_price = price #finding a lower price to buy
            else:
                profit = price - min_price# finding the profit
                max_profit = max(max_profit, profit)#max it compares current max_profit with the new profit
        return max_profit #print the profit
        """
        :type prices: List[int]
        :rtype: int
        """
        