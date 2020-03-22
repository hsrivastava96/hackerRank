def nonDivisibleSubset(k, s):
    d = {x:[] for x in range(k)}

    for i in range(n): 
        d[s[i]%k].append(s[i])
    #print(d)

    count = 0
    if len(d[0])>0:
        count=1

    st = [(x, k-x) for x in range(1, k//2+1)]

    for i, j in st:
        if i!=j:
            if len(d[i])>len(d[j]):
                count+=len(d[i])
            else:
                count+=len(d[j])
        else:
            count+=1
            
    #print(count)
    # Write your code here
    return count
