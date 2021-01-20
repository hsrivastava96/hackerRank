#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the surfaceArea function below.
int surfaceArea(vector<vector<int>> A) 
{
    int row = A.size(), col = A[0].size(), sum = 0;
    if(col == 1)
    {
        for(int i = 0; i < row; i++)
        {
            if(i == 0 || i == row - 1)
            {
                sum+=(3*A[i][0]) + 2;
                if(i == 0)
                {
                    // South side
                    if(row > 1)
                    {
                        if(A[i][0] > A[i + 1][0])
                            sum+=A[i][0] - A[i+1][0];
                    }
                    else
                        sum+=A[i][0];
                }
                else if(i == row - 1)
                {
                    // North side
                    if(row > 1)
                    {
                        if(A[i][0] > A[i - 1][0])
                            sum+=A[i][0] - A[i-1][0];
                    }
                    else
                        sum+=A[i][0];
                }
            }
            else
            {
                // North side
                if(A[i][0] > A[i-1][0])
                    sum+= A[i][0] - A[i-1][0];
                
                // South side
                if(A[i][0] > A[i+1][0])
                    sum+= A[i][0] - A[i+1][0];
                
                sum+=(2*A[i][0]) + 2;
            }
        }
        return sum;
    }
    if(row == 1)
    {
        for(int j = 0; j < col; j++)
        {
            if(j == 0 || j == col - 1)
            {
                sum+=(3*A[0][j]) + 2;
                if(j == 0)
                {
                    // East side
                    if(col > 1)
                    {
                        if(A[0][j] > A[0][j + 1])
                            sum+=A[0][j] - A[0][j+1];
                    }
                    else
                        sum+=A[0][j];
                }
                else if(j == col - 1)
                {
                    // West side
                    if(col > 1)
                    {
                        if(A[0][j] > A[0][j - 1])
                            sum+=A[0][j] - A[0][j-1];
                    }
                    else
                        sum+=A[0][j];
                }
            }
            else
            {
                // West side
                if(A[0][j] > A[0][j-1])
                    sum+= A[0][j] - A[0][j-1];
                
                // East side
                if(A[0][j] > A[0][j+1])
                    sum+= A[0][j] - A[0][j+1];
                
                sum+=(2*A[0][j]) + 2;
            }
        }
        return sum;
    }
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(i == 0)
            {
                if(j == 0)
                {
                    // North Side
                    sum+=A[i][j];

                    // West Side
                    sum+=A[i][j];

                    // South Side
                    if(row > 0)
                    {
                        if(A[i + 1][j] < A[i][j])
                            sum+=A[i][j] - A[i+1][j];
                    }
                    else
                        sum+=A[i][j];
                        
                    // East Side
                    if(col > 0)
                    {
                        if(A[i][j + 1] < A[i][j])
                            sum+=A[i][j] - A[i][j+1];
                    }
                    else
                        sum+=A[i][j];
                        
                    // Top and Bottom
                    sum+=2;
                }
                else if(j == col - 1)
                {
                    // North Side
                    sum+=A[i][j];

                    // West Side
                    if(A[i][j - 1] < A[i][j])
                        sum+=A[i][j] - A[i][j-1];

                    // South Side
                    if(row > 0)
                    {
                        if(A[i + 1][j] < A[i][j])
                            sum+=A[i][j] - A[i+1][j];
                    }
                    else
                        sum+=A[i][j];
                        
                    // East Side
                    sum+=A[i][j];
                        
                    // Top and Bottom
                    sum+=2;
                }
                else
                {
                    // North Side
                    sum+=A[i][j];

                    // West Side
                    if(A[i][j - 1] < A[i][j])
                        sum+=A[i][j] - A[i][j-1];

                    // South Side
                    if(row > 0)
                    {
                        if(A[i + 1][j] < A[i][j])
                            sum+=A[i][j] - A[i+1][j];
                    }
                    else
                        sum+=A[i][j];
                        
                    // East Side
                    if(A[i][j+1] < A[i][j])
                        sum+=A[i][j] - A[i][j+1];
                        
                    // Top and Bottom
                    sum+=2;
                }
            }
            else if((i > 0) && (i < row -1))
            {
                if(j == 0)
                {
                    // North side
                    if(A[i-1][j] < A[i][j])
                        sum+=A[i][j] - A[i-1][j];
                    
                    // West side
                    sum+=A[i][j];
                    
                    // South side
                    if(A[i+1][j] < A[i][j])
                        sum+=A[i][j] - A[i+1][j];
                    
                    // East side
                    if(col > 0)
                    {
                        if(A[i][j+1] < A[i][j])
                            sum+=A[i][j] - A[i][j+1];
                    }
                    else
                        sum+=A[i][j];

                    // Top and Bottom
                    sum+=2;
                }
                else if(j == col - 1)
                {
                    // North side
                    if(A[i-1][j] < A[i][j])
                        sum+=A[i][j] - A[i-1][j];
                    
                    // West side
                    if(A[i][j-1] < A[i][j])
                        sum+=A[i][j] - A[i][j-1];
                    
                    // South side
                    if(A[i+1][j] < A[i][j])
                        sum+=A[i][j] - A[i+1][j];
                    
                    // East side
                    sum+=A[i][j];

                    // Top and Bottom
                    sum+=2;
                }
                else
                {
                    // North side
                    if(A[i-1][j] < A[i][j])
                        sum+=A[i][j] - A[i-1][j];

                    // West side
                    if(A[i][j-1] < A[i][j])
                        sum+=A[i][j] - A[i][j-1];
                        
                    // South side
                    if(A[i+1][j] < A[i][j])
                        sum+=A[i][j] - A[i+1][j];
                        
                    // East side
                    if(A[i][j+1] < A[i][j])
                        sum+=A[i][j] - A[i][j+1];
                        
                    // Top and Bottom
                    sum+=2;
                }
            }
            else
            {
                if(j == 0)
                {
                    // North side
                    if(A[i-1][j] < A[i][j])
                        sum+=A[i][j] - A[i-1][j];
                    
                    // West side
                    sum+=A[i][j];
                    
                    // South side
                    sum+=A[i][j];
                    
                    // East side
                    if(A[i][j+1] < A[i][j])
                        sum+=A[i][j] - A[i][j+1];
                        
                    // Top and Bottom
                    sum+=2;
                }
                else if(j == col-1)
                {
                    // North side
                    if(A[i-1][j] < A[i][j])
                        sum+=A[i][j] - A[i-1][j];
                        
                    // West side
                    if(A[i][j-1] < A[i][j])
                        sum+=A[i][j] - A[i][j-1];
                    
                    // South side
                    sum+=A[i][j];
                    
                    // East side
                    sum+=A[i][j];                                        

                    // Top and Bottom
                    sum+=2;
                }
                else
                {
                    // North side
                    if(A[i-1][j] < A[i][j])
                        sum+=A[i][j] - A[i-1][j];
                        
                    // West side
                    if(A[i][j-1] < A[i][j])
                        sum+=A[i][j] - A[i][j-1];

                    // South side
                    sum+=A[i][j];
                    
                    // East side
                    if(A[i][j+1] < A[i][j])
                        sum+=A[i][j] - A[i][j+1];                                        

                    // Top and Bottom
                    sum+=2;
                }
            }
        }
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string HW_temp;
    getline(cin, HW_temp);

    vector<string> HW = split_string(HW_temp);

    int H = stoi(HW[0]);

    int W = stoi(HW[1]);

    vector<vector<int>> A(H);
    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = surfaceArea(A);

    fout << result << "\n";

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
