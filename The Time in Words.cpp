#include <bits/stdc++.h>

using namespace std;

string ones(int num)
{
    if(num == 1)
        return "one";
    if(num == 2)
        return "two";
    if(num == 3)
        return "three";
    if(num == 4)
        return "four";
    if(num == 5)
        return "five";
    if(num == 6)
        return "six";
    if(num == 7)
        return "seven";
    if(num == 8)
        return "eight";
    if(num == 9)
        return "nine";
    return "";
}

string teen(int num)
{
    if(num == 11)
        return "eleven";
    if(num == 12)
        return "twelve";
    if(num == 13)
        return "thirteen";
    if(num == 14)
        return "fourteen";
    if(num == 15)
        return "fifteen";
    if(num == 16)
        return "sixteen";
    if(num == 17)
        return "seventeen";
    if(num == 18)
        return "eighteen";
    if(num == 19)
        return "nineteen";
    return "";
}

string ty(int num)
{
    if(num == 10)
        return "ten";
    if(num == 20)
        return "twenty";
    if(num == 30)
        return "thirty";
    if(num == 40)
        return "forty";
    if(num == 50)
        return "fifty";
    // if(num == 60)
    //     return "sixty";
    // if(num == 70)
    //     return "seventy";
    // if(num == 80)
    //     return "eighty";
    // if(num == 90)
    //     return "ninety";
    return "";
}

// Complete the timeInWords function below.
string timeInWords(int h, int m) 
{
    string hr = "", mn = "";
    int h_Copy = h, m_Copy = m;
    if(m > 30)
    {
        m = 60 - m;
        h+=1;
    }

    if(h < 10)
        hr = ones(h);
    else if(h == 10)
        hr == ty(h);
    else
        hr = teen(h);
    if(m < 10)
    {
        // cout<<"Line 89"<<endl;
        mn = ones(m);
    }
    else if(m % 10 == 0)
    {
        // cout<<"Line 91"<<endl;
        mn = ty(m);
    }
    else if(m % 10 != 0 && m > 19)
    {
        // cout<<"Line 93"<<endl;
        int temp_Rem = m % 10, temp_Ty = m - (m % 10);
        mn = ty(temp_Ty) + " " + ones(temp_Rem);
    }
    else 
    {
        // cout<<"Line 93"<<endl;
        mn = teen(m);
    }
    // cout<<hr<<"\t"<<mn<<endl;
    if(mn == "")
        return hr+" o' clock";
    else if(m_Copy == 15)
        return "quarter past "+hr;
    else if(m_Copy == 30)
        return "half past "+hr;
    else if(m_Copy == 45)
        return "quarter to "+hr;
    else if(m_Copy < 30)
    {
        if(m_Copy == 1)
            return mn+" minute past "+hr;
        return mn+" minutes past "+hr;
    }
    else if(m_Copy > 30)
    {
        if(m_Copy == 1)
            return mn+" minute to "+hr;
        return mn+" minutes to "+hr;
    }
    return "";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}
