int utopianTree(int n) 
{
    int s = 1;
    if(n==0)
        return 1;
    for(int i = 1; i<=n; i++)
    {
        if(i%2==0)
            s+=1;
        else
            s*=2;
    }
    return s;
}
