#include <stdio.h>


int collect_points(int points, int set, int sum){
    /*Take the leftovers, and add scores based on set*/
    sum += points * set;
    return sum;
}

int find_max(int points, int point_value){
    /*Find the maximum number amount that can go in*/
    int max = point_value / points;
    return max;
}

int main(){

    /*int is 4 bytes*/

    while(1){

        int point_value;

        /*Prompt the user*/
        while(1){
            printf("=============================================================\n");
            printf("Enter a number between 2 and 1000. Enter 0 or 1 to quit.\n");
            scanf("%d", &point_value);
            if((point_value <= 1000) && (point_value >=2)){
                printf("\n");
                break;
            }
            else if((point_value == 1) || (point_value == 0)){
                printf("User ended program \n \n");
                return 0;
            }
            else {
                printf("Bad input. \n");
            }
        }

        /*Declare Variables*/

        int one_max = find_max(8, point_value);   /*TD + 2* 8*/
        int two_max = find_max(7, point_value);   /*TD + 1* 7*/
        int three_max = find_max(6, point_value); /*TD      6*/
        int four_max = find_max(3, point_value);  /*FG      3*/
        int five_max = find_max(2, point_value);  /*Saf     2*/


        int sum;

        /*Start loop*/

        for(int i = 0; i <= one_max; i++){
            for(int j = 0; j <= two_max; j++){
                for(int k = 0; k <= three_max; k++){
                    for(int m = 0; m <= four_max; m++){
                        for(int n = 0; n <= five_max; n++){
                            sum = collect_points(8, i, sum);
                            sum = collect_points(7, j, sum);
                            sum = collect_points(6, k, sum);
                            sum = collect_points(3, m, sum);
                            sum = collect_points(2, n, sum);

                            

                            if(sum == point_value){

                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety \n", i, j, k, m, n);
                            }
                            sum = 0;
                        }
                    }
                }
            
            }

        }
    }

}



