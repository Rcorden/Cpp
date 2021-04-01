#include <bits/stdc++.h>

using namespace std;

// Complete the viralAdvertising function below.
int viralAdvertising(int n) 
{   
    int totalLikes = 2, shares = 2;
    
    for(int i = 1; i < n; i++)
    {
       totalLikes +=  floor((shares*3)/2);
       shares = floor((shares*3)/2);
    }
    
    return totalLikes;
}

//Provided by HackerRank
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}