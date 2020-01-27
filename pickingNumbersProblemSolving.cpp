int pickingNumbers(vector<int> a) 
{
    sort(a.begin(), a.end());
    //cout<<a[0]<<a[1]<<a[2]<<a[3]<<a[4]<<a[5]<<endl;

    int c1=0, c2=0, m=-1, c=0, cn=0;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]-a[c1]==0)
            c++;
        else if(a[i]-a[c1]==1)
        {
            c++;
            cn++;
            c2 = i;
        }
        else
        {
            if(c>m)
                m=c;
            if(a[i]-a[c2]==1)
            {
                c1=c2;
                c=cn;
                cn=0;
                i=i-1;
            }
            else
            {
                c1=i;
                c=1;
                cn=0;
            }    
            
        }
    }
    if(c==a.size())
        return c;
    return m;
}
