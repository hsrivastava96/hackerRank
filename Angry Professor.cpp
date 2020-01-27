// Complete the angryProfessor function below.
string angryProfessor(int k, vector<int> a) 
{
    int c =0;
    for(int i =  0; i<a.size(); i++)
    {
        if(a[i]<=0)
            c++;
    }
    if(c>=k)
        return "NO";
    else
        return "YES";
}
