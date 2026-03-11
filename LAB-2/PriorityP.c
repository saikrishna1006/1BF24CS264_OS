#include<stdio.h>

int main(){
    int AT[10], BT[10], RBT[10], TAT[10], WT[10], CT[10], PRIORITY[10], COMPLETED[10];
    int N, time = 0, count = 0;

    printf("Enter no of process :  \t");
    scanf("%d",&N);

    for(int i=0;i<N;i++){
        printf("Enter AT, BT and PRIORITY of process %d: ",(i+1));
        scanf("%d %d %d",&AT[i],&BT[i],&PRIORITY[i]);
        RBT[i] = BT[i];       // remaining burst time
        COMPLETED[i] = 0;
    }

    while(count < N){
        int x = -1, P = 9999;
        for(int i=0;i<N;i++){
            if(!COMPLETED[i] && AT[i] <= time && PRIORITY[i] < P){
                x = i;
                P = PRIORITY[i];
            }
        }

        if(x == -1){
            time++;
        } else {
            RBT[x]--;
            time++;

            if(RBT[x] == 0){
                CT[x] = time;
                TAT[x] = CT[x] - AT[x];
                WT[x] = TAT[x] - BT[x];
                COMPLETED[x] = 1;
                count++;
            }
        }
    }

    printf("\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for(int i=0;i<N;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               (i+1), AT[i], BT[i], PRIORITY[i], CT[i], TAT[i], WT[i]);
    }

    return 0;
}
