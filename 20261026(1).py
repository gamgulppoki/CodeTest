def solution(nums):
    answer = 0
    
    d = {}
    
    for n in nums:
        if n not in d:
            d[n] = 1;
        else : 
            d[n]+=1;
    
    return min(len(d), len(nums) // 2)
