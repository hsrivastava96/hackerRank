#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the gridSearch function below.
int sCmp(string s1, string s2, int ind, int cG, int cP)
{
    int flg = 0, i = 0, loop = 0;
    // cout<<"Comparison of "<<s1<<" and "<<s2<<"index is "<<ind<<endl;
    for(i = ind, loop = 0; (loop < cP) && (flg == 0); loop++, i++)
    {
        // cout<<"Coming in here"<<endl;
        // cout<<"Comparing --> "<<s1[i]<<", "<<s2[loop]<<endl;
        // cout<<"Output --> "<<(int(s1[i]) - int(s2[loop]))<<endl;
        if((int(s1[i]) - int(s2[loop])) != 0)
        {
            // cout<<"Setting flg to 1"<<endl;
            flg = 1;
        }
    }
    if((flg == 1))
        return 0;
    return 1;    
}

string gridSearch(vector<string> G, vector<string> P) 
{
    int rG = G.size(), cG = G[0].size(), rP = P.size(), cP = P[0].size(); 
    int flag1 = 0;
    
    for(int i = 0; (i < (rG - rP + 1)) && (flag1 == 0); i++)
    {
        for(int j = 0; (j < (cG - cP + 1)) && (flag1 == 0); j++)
        {
            int check = sCmp(G[i], P[0], j, cG, cP);
            // cout<<"1st check --> "<<check<<endl;
            if(check == 1)
            {
                int flag = 0, k = 0;
                // cout<<"1st Same --> "<<G[i]<<"\t, "<<P[0]<<endl;
                for(k = 1; (k < rP) && (flag == 0); k++)
                {
                    int checkS = sCmp(G[i + k], P[k], j, cG, cP);
                    // cout<<"Further Same --> "<<G[i + k]<<"\t, "<<P[k]<<endl;
                    if(checkS == 0)
                        flag = 1;
                }
                if((k == rP) && (flag == 0))
                    flag1 = 1;
            }
        }
    }
    if(flag1 == 1)
        return "YES";
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string RC_temp;
        getline(cin, RC_temp);

        vector<string> RC = split_string(RC_temp);

        int R = stoi(RC[0]);

        int C = stoi(RC[1]);

        vector<string> G(R);

        for (int i = 0; i < R; i++) {
            string G_item;
            getline(cin, G_item);

            G[i] = G_item;
        }

        string rc_temp;
        getline(cin, rc_temp);

        vector<string> rc = split_string(rc_temp);

        int r = stoi(rc[0]);

        int c = stoi(rc[1]);

        vector<string> P(r);

        for (int i = 0; i < r; i++) {
            string P_item;
            getline(cin, P_item);

            P[i] = P_item;
        }

        string result = gridSearch(G, P);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
