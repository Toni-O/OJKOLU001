#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define TITLE "DECIMAL TO RADIX_i converter"
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
    int dec, rad;
    float log;
    int div, rem;

    printf("****************************\n %s\n Written by: %s\n Date: %d\n****************************", TITLE, AUTHOR, YEAR);

    while(dec >=0){
        
        printf("\nEnter a decimal number: ");
        scanf("%d",&dec);
        
        if (dec <0){
            
            printf("EXIT");
            
        } else{
            printf("The decimal number you have entered is %d ",dec);
            
            printf("\nEnter a radix for the converter between 2 and 16: ");
            scanf("%d",&rad);
            printf("The radix you have entered is %d ",rad);
    
            log = log2(dec)/log2(rad);; 
            printf("\nThe log%d of the number is %.2f ",rad,log);
    
            div = dec/rad;
            printf("\nThe integer result of the number divided by %d is %d",rad,div);
    
            rem = dec%rad;
            printf("\nThe remainder is %d",rem);
            
            printf("\nThe radix-%d value is ",rad);
            Dec2RadixI(dec, rad);
        }
    }
}