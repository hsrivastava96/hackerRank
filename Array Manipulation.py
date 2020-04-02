# Complete the arrayManipulation function below.
def arrayManipulation(n, queries):
    li = []
    for i in range(n+1):
        li.append(0)
    for i, j, val in queries:
        li[i]+=val
        if j<n:
            li[j+1]-=val
    mx = -999
    sm = 0
    for i in range(n+1):
        sm+=li[i]
        if sm>mx:
            mx = sm
    
    return mx
