#include<iostream>
Vishal karmakar
using namespace std;

char arr[10]={'0','1','2','3','4','5','6','7','8','9'};
char matrix[3][3];
int flag = 0;

int chechwin(){
    if(matrix[0][0]==matrix[0][1]&&matrix[0][1]==matrix[0][2])//1
    return 1;
    else if(matrix[0][0]==matrix[1][0]&&matrix[1][0]==matrix[2][0])//4
    return 1;
    else if(matrix[2][0]==matrix[2][1]&&matrix[2][1]==matrix[2][2])//3
    return 1;
    else if(matrix[1][0]==matrix[1][1]&&matrix[1][1]==matrix[1][2])//2
    return 1;
    else if(matrix[0][1]==matrix[1][1]&&matrix[1][1]==matrix[2][1])//5
    return 1;
    else if(matrix[0][2]==matrix[1][2]&&matrix[1][2]==matrix[2][2])//6
    return 1;
    else if(matrix[0][0]==matrix[1][1]&&matrix[1][1]==matrix[2][2])//7
    return 1;
    else if(matrix[0][2]==matrix[1][1]&&matrix[1][1]==matrix[2][0])//8
    return 1;
    else
    return 0;
}

void board(){
    cout<<"Player 1-"<<"(X)"<<"     ";
    cout<<"Player 2-"<<"(O)"<<endl;
    cout<<endl;
    cout<<endl;
    
int c=1;
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
           matrix[i][j]=arr[c];
           if(j==1){
           cout<<"|  "<<matrix[i][j]<<"  |";
           c++;
           }
           else{
           cout<<"   "<<matrix[i][j]<<"   ";
           c++;
           }
        }
        if(i!=2){
        cout<<endl;
        cout<<"  _____|_____|______";
        cout<<endl;
        }
        else
        cout<<endl;
        
    }
}






int main(){
    board();
    int count=1;
    int win;
while(flag==0){

int box1=0,box2=0;

if(count%2==0){
cout<<"player 2:"<<endl;
cin>>box2;
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(matrix[i][j]==arr[box2]){
            matrix[i][j]='O';
        }
    }
}
count++;
}
else{
cout<<"player 1:"<<endl;
cin>>box1;
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(matrix[i][j]==arr[box1]){
            matrix[i][j]='X';
        }
    }
}
count++;
}



int c=1; 
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(matrix[i][j]=='X'||matrix[i][j]=='O'){
           if(j==1){
           cout<<"|  "<<matrix[i][j]<<"  |";
           c++;
           }
           else{
           cout<<"   "<<matrix[i][j]<<"   ";
           c++;
           }
        }
        else{
           matrix[i][j]=arr[c];
           if(j==1){
           cout<<"|  "<<matrix[i][j]<<"  |";
           c++;
           }
           else{
           cout<<"   "<<matrix[i][j]<<"   ";
           c++;
           }
        }
    }
        if(i!=2){
        cout<<endl;
        cout<<"  _____|_____|______";
        cout<<endl;
        }
        else
        cout<<endl;
        
    

}
   win=chechwin();
   if(win==1)
   break;
}
if(count%2==0)
    cout<<"Player 1 is the winner "<<endl;
    else
    cout<<"Player 2 is the winner "<<endl;

}
