#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char str[2005];
    cin >> str;
    int cnt[26][n+1], ans = 0;
    for(int i=0; i<26; i++)
    {
        cnt[i][0] = 0;
        for(int j=1; j<=n; j++)
        {
            cnt[i][j] = cnt[i][j-1];
            if(str[j-1] - 'a' == i)
                cnt[i][j]++;
        }
    }
    /*for(int i=0; i<26; i++)
    {
        for(int j=0; j<=n; j++)
            cout << cnt[i][j] << " ";
        cout << endl;
    }*/
    for(int i=1; i<n; i++)
    {
        for(int j=i+2; j<n; j++)
        {
            if(str[i] == str[j])
            {
                for(int k=0; k<26; k++)
                {
                    int x1 = cnt[k][i];
                    int x2 = cnt[k][j] - cnt[k][i+1];
                    ans = ans + (x1*x2);//    
                }
                
            }
        }
    }
    cout << ans << endl;                    
    return 0;
}
