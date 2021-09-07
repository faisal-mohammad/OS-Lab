#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,bt[20],wt[20],ct[20],tat[20],awt = 0,atat = 0,act = 0;
    cout<<"Enter the number of process :";
    cin>>n;
    cout<<"Enter Bust time : "<<endl;
    for(int i = 0;i<n;i++){
        cout<<"P["<<i+1<<"]=";
        cin>>bt[i];
    }

    wt[0] = 0;
    for(int i=1;i<n;i++){
        wt[i]=0;
        for(int j =0;j<i;j++){
            wt[i] = wt[i] + bt[j];
        }
    }
    cout<<endl;
    for(int i = 0;i<n;i++){
        cout<<"P["<<i+1<<"]="<<"  "<<"Bust Time : "<<bt[i]<<"  "<<"Wating time : "<<wt[i]<<endl;
        awt = awt + wt[i];
    }

    //Turnaround time

    for(int i=0;i<n;i++){
        tat[i] = wt[i] + bt[i];
    }
    cout<<endl;
    for(int i = 0;i<n;i++){
        cout<<"P["<<i+1<<"]="<<"  "<<"Bust Time : "<<bt[i]<<"  "<<"Turnaround time : "<<tat[i]<<endl;
        atat = atat + tat[i];
    }

    //completion time
    ct[0] = bt[0];
    for(int i = 1;i<n;i++){
        ct[i] = ct[i-1] + bt[i];
    }
    cout<<endl;
    for(int i = 0;i<n;i++){
        cout<<"P["<<i+1<<"]="<<"  "<<"Bust Time : "<<bt[i]<<"  "<<"Completion time : "<<ct[i]<<endl;
        act = act + ct[i];
    }
    //Average waiting, turnaround and completion time finding
    float result_of_awt = awt/n;
    float result_of_atat = atat/n;
    float result_of_act = act/n;

    cout<<endl<<endl<<"Average waiting time : "<<result_of_awt<<endl;
    cout<<endl<<endl<<"Average turnaround time : "<<result_of_atat<<endl;
    cout<<endl<<endl<<"Average completion time : "<<result_of_act<<endl;

    return 0;

}
