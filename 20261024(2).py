def solution(arr):
    answer = []
    
    prev = None
    
    for a in arr:
        if a != prev:
            answer.append(a)
            prev = a

    return answer
