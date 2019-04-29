#include <bits/stdc++.h>
#define ll long long
using namespace std;

char grid[1000][1000];
bool vis[1000][1000];
int R,C;
int countRes = 0;
string res;


int x[] = {1,-1,0,1};
int y[] = { 1,1,1,0};


bool search2D(int row, int col, string word)
{
    
    countRes = 0;

    if (grid[row][col] != word[0])
      return false;

    int len = word.length();

    // Search word in all 4 directions starting from (row,col)
    for (int dir = 0; dir < 4; dir++)
    {
        int k, rd = row + x[dir], cd = col + y[dir];


        for (k = 1; k < len; k++)
        {

            if (rd >= R || rd < 0 || cd >= C || cd < 0)
                break;


            if (grid[rd][cd] != word[k])
                break;


            rd += x[dir], cd += y[dir];
        }


        if (k == len)
        {
           // cout<<"ACcept"<<endl;
            //return true;
            countRes ++;
        }    
    }
    
    if(countRes > 0){
        return true;
    }
    else
        return false;
}

//  Searches given word in a given matrix in all 4 directions
void patternSearch(string word)
{
    int count = 0;
    for (int row = 0; row < R; row++)
       for (int col = 0; col < C; col++)
          if (search2D(row, col, word))
            //  cout<<countRes<<endl;
            count += countRes;

    cout<<count<<endl;
}

int main()
{
    //ifstream cin ("test1.txt");
    //int m,n;
    char temp;
    cin>>R>>C;


    for (int i=0;i<R;i++){
         for (int j=0;j<C;j++ ){
            cin >> temp;
            grid[i][j] = temp;
            vis[i][j] = false;
         }
    }

    string word = "saba";
    patternSearch(word);

//     for (int i=0;i<R;i++){
//         for (int j=0;j<C;j++ ){
//            cout<<grid[i][j];
//         }
//         cout<<endl;
//    }


    return 0;
}
