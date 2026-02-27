#include <stdio.h>

float celsius_to_fahrenheit(float celsius){
    float ans = (9*celsius)/5 + 32;
    return ans;
}

float fahrenheit_to_celsius(float fahrenheit){
    float ans = (5*(fahrenheit-32))/9;
    return ans;
}

float celsius_to_kelvin(float celsius){
    float ans = celsius + 273.15;
    return ans;
}

float kelvin_to_celsius(float kelvin){
    float ans = kelvin - 273.15;
    return ans;
}

void categorize_temperature(float celsius){
    if(celsius < 0){
        printf("Freezing: Stay indoors.\n");
    }
    else if(celsius < 10){
        printf("Cold: Wear a jacket.\n");
    }
    else if(celsius <25){
        printf("Comfortable: Go touch grass.\n");
    }
    else if(celsius < 35){
        printf("Hot: Drink water.\n");
    }
    else{
        printf("Extreme heat: Stay indoors.\n");
    }
    return;
}

int main(){

    float c_temp;
    float f_temp;
    float k_temp;

    float user_input;
    char temp_scale;
    char target_scale;

    while(1){

        printf("Enter the temperature value: ");
        scanf("%f", &user_input);
        getchar();

        printf("Choose temperature scale (type 'F', 'K', or 'C'): ");
        scanf("%c", &temp_scale);
        getchar();

        printf("Choose temperature target (type 'F', 'K', or 'C'): ");
        scanf("%c", &target_scale);
        getchar();


        /*Check user_input*/
        if((user_input < 0) && (temp_scale == 'K')){
            printf("Invalid input: Kelvin can't be negative.\n");
        }
        else if((user_input < -273.15) && (temp_scale == 'C')){
            printf("Invalid input: Celsius can't be below 273.15.\n");
        }
        else if((user_input < -459.67) && (temp_scale == 'F')){
            printf("Invalid input: Fahrenheit can't be below -459.67.\n");
        }
        else if(target_scale == temp_scale){
            printf("Invalid input: Temperature already in desired form.\n");
        }
        else if ((target_scale || temp_scale) != ('F' || 'K' || 'C')){
            printf("invalid input: Temperature scale is invalid. \n");
        }
        else{
            break;
        }
    }

    if(temp_scale == 'C'){
        c_temp = user_input;
        if(target_scale == 'K'){
            k_temp = celsius_to_kelvin(c_temp);
            printf("Kelvin temperature = %.3f K\n", k_temp);
        }
        else if(target_scale == 'F'){
            f_temp = celsius_to_fahrenheit(c_temp);
            printf("Fahrenheit temperature = %.3f F\n", f_temp);
        }
    }
    else if(temp_scale == 'F'){
        f_temp = user_input;
        c_temp = fahrenheit_to_celsius(f_temp);
        if(target_scale == 'K'){
            k_temp = celsius_to_kelvin(c_temp);
            printf("Kelvin temperature = %.3f K\n", k_temp);
        }
        else if(target_scale == 'C'){
            printf("Celsius temperature = %.3f C\n", c_temp);
        }
    }
    else if (temp_scale == 'K'){
        k_temp = user_input;
        c_temp = kelvin_to_celsius(k_temp);
        if(target_scale == 'C'){
            printf("Celsius temperature: %.3f C\n", c_temp);
        }
        else if(target_scale == 'F'){
            f_temp = celsius_to_fahrenheit(c_temp);
            printf("Fahrenheit temperature: %.3f F\n", f_temp);
        }
        }

    categorize_temperature(c_temp);

    printf("End of program.\n====================================================");

    return 0;

}