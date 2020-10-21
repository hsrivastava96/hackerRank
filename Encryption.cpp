#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) 
{
    int l = s.length();
    string str = "", f_Str = "";
    int max_Size = 0, flag = 0;
    for(int i = 0; i < l; i++)
    {
        if(s[i] != ' ')
        {
            str+=s[i];
            max_Size+=1;
        }
    }    

    int r = floor(sqrt(max_Size)), c = ceil(sqrt(max_Size)), cond_Row = 0;

    if(r == c)
        cond_Row = r-1;
    else
        cond_Row = r;

    for(int i = 0; i <= cond_Row; i++)
    {
        for(int j = i; j < max_Size; j+=c)
            f_Str+=str[j];
        f_Str+=" ";
        cout<<f_Str<<endl;
    }

    cout<<str<<endl;
    cout<<r<<"\t"<<c<<endl;
    cout<<f_Str<<endl;
    return f_Str;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
