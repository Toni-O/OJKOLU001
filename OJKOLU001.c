#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define TITLE "DECIMAL TO RADIX_i converter"         //Created constants to update the basic program print template
#define AUTHOR "Oluwatoni Ojo-Akinkunmi"
#define YEAR 2022

void Dec2RadixI(int decValue, int radValue){
    int n = ceil(log2(decValue+1)/log2(radValue));  //Calculate the number of bits needed
            
            int i =0, ri =0, qi =1;
            int b[n] ;
            float di = decValue;        //Convert integer decimal and radix values to floats for remainder calculation
            float r = radValue;
            
            if (di ==0){        
                
                printf("%c",'0');       //Zero is the same in all number systems
                
            } else {
                
            while(di>0){                //Run until the divided value decimal is zero
            
                qi = (di/r);            //Division of decimal over radix
                ri = di-(qi*r);         //Calculate the Remainder
                
                if (ri==10){            //Assign radix symbols if remainder >9
                    b[i]='A' -48;       //Converts to ASCII value of the character
                    
                }else if(ri==11){
                    b[i]='B'-48;
                    
                }else if(ri==12){
                    b[i]='C'-48;
                    
                }else if(ri==13){
                    b[i]='D'-48;
                    
                }else if(ri==14){
                    b[i]='E'-48;
                    
                }else if(ri==15){
                    b[i]='F' - 48;
                    
                }else{
                b[i]=ri;                 //Store remainder in binary array
                
                }
                
                di = qi;                 //Set next decimal value to division result
                i++;                     //increment counter
            }
        }
           for (int j = n-1; j >= 0; j--){      //Print binary array in reverse
                     printf("%c", 48 + b[j]);   //Converts ASCII value to character
                }
}

int main()
{   
    int dec, rad;       //Initialise variables
    float log;
    int div, rem;

    printf("****************************\n %s\n Written by: %s\n Date: %d\n****************************", TITLE, AUTHOR, YEAR); //Displays basic program template

    while(dec >=0){                                 //Run until a negative decimal number is entered
        
        printf("\nEnter a decimal number: ");       //Prompt user to enter a positive decimal number
        scanf("%d",&dec);                           //Read in and store the decimal number entered
        
        if (dec <0){                                //Quit program and display EXIT if decimal number is negative
            
            printf("EXIT");
            
        } else{
            printf("The decimal number you have entered is %d ",dec);           //Display the decimal number entered
            
            printf("\nEnter a radix for the converter between 2 and 16: ");     //Prompt user to enter a radix number between 2-16 
            scanf("%d",&rad);                                                   //Read in and store the radix number entered
            printf("The radix you have entered is %d ",rad);                    //Display the radix number entered
    
            log = log2(dec);                                               //Calculate the result of log2 of the decimal number
            printf("\nThe log2 of the number is %.2f ",log);               //Display the number of bits required
    
            div = dec/rad;                                                              //Calculate the decimal number divided by the radix number
            printf("\nThe integer result of the number divided by %d is %d",rad,div);   //Display the result of the division
    
            rem = dec%rad;                                                      //Calculate the remainder of decimal number divided by the radix number using modulus function
            printf("\nThe remainder is %d",rem);                                //Display the remainder
            
            printf("\nThe radix-%d value is ",rad);                             //Display the equivalent radix-i value
            Dec2RadixI(dec, rad);                                               //Call the Dec2RadixI function where the equivalent radix-i value is calculated
        }
    }
}