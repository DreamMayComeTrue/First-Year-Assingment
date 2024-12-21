#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

string displayLine();
void findIndWinner(int marks[12][7], int Calmark[12],int &highestIndMark);
void findTeamWinner(int marks[12][7], int calmark[12], int colTeamMark[3],int &highestGrpMark);

string displayLine() {
    string line;
    for (int i = 0; i < 52; ++i) {
        line += "-";
    }
    return line;
}

void findIndWinner(int marks[12][7], int Calmark[12],int &highestIndMark,int &IndWinner, int &IndWinnerTeam) {
    for (int i = 0; i < 12; ++i) {
        for (int j = 2; j < 7; ++j) {
            Calmark[i]=Calmark[i]+marks[i][j];
        }
    }
    for (int i = 0; i < 12; ++i) {
        if (Calmark[i]>highestIndMark){
            highestIndMark = Calmark[i];
            IndWinner = marks[i][1];
            }
        if (marks[i][0]==1){
            IndWinnerTeam = 1;
        }
        if (marks[i][0]==2){
            IndWinnerTeam = 2;
        }
        if (marks[i][0]==3){
            IndWinnerTeam = 3;
        }
        
        }
    
}

void findTeamWinner(int marks[12][7], int calmark[12], int colTeamMark[3],int &highestGrpMark, int &winnerGrp) {
    for (int i = 0; i < 12; ++i) {
        if (marks[i][0]==1){
            colTeamMark[0] = colTeamMark[0] + calmark[i];
        }
        if (marks[i][0]==2){
            colTeamMark[1] = colTeamMark[1] + calmark[i];
        }
        if (marks[i][0]==3){
            colTeamMark[2] = colTeamMark[2] + calmark[i];
        }
    }
    if (colTeamMark[0]>colTeamMark[1] && colTeamMark[0]>colTeamMark[2]){
        highestGrpMark = colTeamMark[0];
        winnerGrp = 1;
    }
    if (colTeamMark[1]>colTeamMark[0] && colTeamMark[1]>colTeamMark[2]){
        highestGrpMark = colTeamMark[1];
        winnerGrp = 2;
    }
    if (colTeamMark[2]>colTeamMark[0] && colTeamMark[2]>colTeamMark[1]){
        highestGrpMark = colTeamMark[2];
        winnerGrp = 3;
    }
}

int main() {
    int marks[12][7];
    int Calmark[12]={0*12};
    int colTeamMark[3]={0*3};
    int highestIndMark=0,highestGrpMark=0;
    int winnerGrp=0;
    int IndWinner=0;
    int IndWinnerTeam=0;
    string Line;
    try {
        ifstream file("input.txt");
        if (!file) {
            throw runtime_error("Sorry, input file does not exist! \nPress any key to continue . . .");
        }
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 7; ++j) {
                file >> marks[i][j];
            }
        }
        file.close();
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return 1;
    }
    findIndWinner(marks,Calmark,highestIndMark,IndWinner,IndWinnerTeam);
    Line = displayLine();
    findTeamWinner(marks,Calmark,colTeamMark,highestGrpMark,winnerGrp);
    cout<<Line<<endl;
    cout<<"Id"<<setw(8)<<"E1"<<setw(8)<<"E2"<<setw(8)<<"E3"<<setw(8)<<"E4"<<setw(8)<<"E5"<<setw(10)<<"Total"<<endl;
    cout<<Line<<endl;
    int loop=6;
    int k = 0;
    int o = 4;
    int a = 0;
    int b = 0;
    for (int z = 0;z<3;z++){
        cout<<"Team "<<z+1<<endl;
        for (int i = k; i < o; i++) {          
                for (int j = 1; j < 7; j++) {
                    cout<<marks[i][j]<<setw(loop);
                    loop += 2;
                    if (j==2){
                        loop = 8;
                    }
                    if (j==3){
                        loop = 8;
                    }
                    if (j==4){
                        loop = 8;
                    }
                }
            cout<<Calmark[b];
            b++;
            loop = 6;
            cout<<"\n";
        }
        cout<<"Total"<<setw(47)<<colTeamMark[a]<<endl;
        a++;
        cout<<Line<<endl;
        k += 4;
        o += 4;
    }
    cout<<"Winner for Individual Category : "<<IndWinner<<" (Team "<<IndWinnerTeam<<')'<<endl;
    cout<<"Winner for Group Category : Team "<<winnerGrp<<" (Score = "<<highestGrpMark<<')'<<endl;    
    cout<<"\n";
    cout<<"Press any key to continue . . .";
    return 0;
}

