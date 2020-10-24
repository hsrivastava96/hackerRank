#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string word(string w, int ind)
{
    string temp = "";
    for(int i = ind; i < w.length() && w[i]!='\0'; i++)
        temp+=w[i];
    sort(temp.begin(), temp.end());
    // cout<<temp<<endl;
    return temp;
}

string biggerIsGreater(string w) 
{
    int flag = 0, index = NULL;
    string temporary = "", final_Str = "";
    for(int i = w.length() - 2; i>=0; i--)
    {
        // cout<<w[i]<<endl;
        string temp_Str =  word(w, i+1);
        for(int j = 0; temp_Str[j]!='\0'; j++)
        {
            if(temp_Str[j]>w[i])
            {
                flag = 1;
                index = i;
                char temp = w[i];
                w[i] = temp_Str[j];
                temp_Str[j] = temp;
                temporary = word(temp_Str, 0);
                break;
            }
        }
        if(flag == 1)
            break;
    }        
    // cout<<w<<endl;
    // cout<<temporary;
    if(flag == 0)
        return "no answer";
    
    for(int i = 0, k = 0; w[i]!='\0'; i++)
    {
        // cout<<"final_Str";
        if(i<=index)
        {
            final_Str+=w[i];
        }
        else
        {
            final_Str+=temporary[k];
            k++;
        }
    }
    // cout<<final_Str<<endl;
    return final_Str;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
