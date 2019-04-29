#include <bits/stdc++.h>
#define ll long long
using namespace std;
int arr[204][204];
int row,col;

void display(){

     for(int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }

}

void FillTriangle(int N){

    memset(arr, -1, sizeof(arr));
     col = (N*2) +1;
     row = N + 1;

    //cout<<row<<col<<endl;

    int count = 1,space = (col/2)-1;
    int spl = 0;
     for (int i=row-1 ; i>=0 ; i--){
        for(int j=0+spl; j<=col-1-spl ; j+=2){
            arr[i][j] = 1;
        }
        for(int j=0+spl+1; j<=col-1-spl ; j+=2){
            arr[i][j] = 0;
        }
        spl++;
     }
    //display();

}

int checkCount(int i,int j){
    int rowC=0,colC=0;
    for(int I = i; arr[I][j] != -1 || I<=row ; I++){

        if(arr[I][j] == 1){
            //cout<<I<<j<<endl;
            rowC++;
        }
    }

    for(int J = j; arr[i][J] != -1 || J<=col; J++){
        if(arr[i][J] == 1){
            //cout<<i<<J<<endl;
            colC++;
        }
    }

    rowC--;
    colC--;

    //cout<<"Checked: "<<rowC<<" "<<colC<<endl;

    if (rowC==0 || colC ==0 ){
        return 0;
    }
    else{
        return rowC*colC;
    }


}

int main()
{
    //ifstream cin ("input.txt");

    int N,res = 0;

    cin >> N;

    FillTriangle(N);


     for(int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            if(arr[i][j] == 1){
                res += checkCount(i,j);
            }
        }
    }

    cout<<res<<endl;



    return 0;
}
