#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
    int n,bt[20],wt[20],tat[20],a_t[20],ct[20],p[20],pos,total_wt = 0,total_ct = 0,total_tat = 0;
    float awt = 0,atat = 0,act;

    printf("Enter the number process : ");
    cin>>n;
    printf("Enter the burst time : \n");
    for(int i = 0;i<n;i++){
        printf("p[%d] = ",i+1);
        cin>>bt[i];
        p[i] = i + 1;
    }

    for(int i = 0; i<n; i++){
        int temp;
        pos = i;
        for(int j = i + 1; j< n ; j++){
            if(bt[j] < bt[pos]){
                pos = j;
            }
            temp = bt[i];
            bt[i] = bt[pos];
            bt[pos] = temp;

            temp = p[i];
            p[i] = p[pos];
            p[pos] = temp;
            }

        }


    wt[0] = 0;
    for(int i = 1; i<n; i++){
        wt[i] = 0;
        for(int j = 0 ; j<i;j++){
            wt[i] = wt[i] + bt[j];
        }

        total_wt = total_wt + wt[i];
    }
    ct[0] = bt[0];
    for(int i = 1;i<n;i++){
        for(int j = 0;j<i;j++){
            ct[i] = ct[j] + bt[i];
            total_ct = total_ct + ct[i];
        }
    }

    for(int i = 0; i<n;i++){
        tat[i] = wt[i] + bt[i];
        total_tat = total_tat + tat[i];

    }



    awt = (float)total_wt/n;
    act = (float)total_ct/n;
    atat = (float)total_tat/n;
    printf("\n\nProcess\t Burst time\t Waiting time\t Completion Time\t Trunaround time");
    for(int i = 0 ; i<n;i++){
        printf("\nP%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t",p[i],bt[i],wt[i],ct[i],tat[i]);
    }
    printf("\n\nAverage waiting time is : %.3f",awt);
    printf("\n\nAverage Completion time is : %.3f",act);
    printf("\n\nAverage waiting time is : %.3f",atat);

    return 0;
}
