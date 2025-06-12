#include <stdio.h>
/*get presidents arrival Date, return input*/
int enterDate() {  
    int digit;  
    printf("What is the President's arrival date(mmddyy): "); 
    scanf("%d", &digit);  
    return digit;  
}  
/*encode president arrival*/  
int encodeDate(int digit) {  
    int encode = 0,divisor = 100000, i,total = 0,totalE = 0, currDigit;  
    if (digit <=999999 && digit >= 100000) {  
        for (i = 0; i < 6; i++) {  
            currDigit = (digit / divisor) % 10;  
            encode = (currDigit + 7) % 10;  
            total = total + currDigit * divisor;  
            totalE = totalE + encode * divisor;  
            divisor = divisor / 10;  
        }  
    }
    else {  
        printf("Invalid Input.");  
    }  
    return totalE;  
}  
/*scramble for extra security*/
int scrambleDate(int totalE) {  
    int scramble = 0, i, currDigit, years,totalY = 0, totalM = 0, totalD = 0, months,days;  
    /*broke into 3 variables goin with 2 digits*/
    int divisor = 10;  
    for (i = 0; i < 2; i++){  
        years = (totalE / divisor) % 10;   
        totalY = totalY + years * divisor;  
        divisor = divisor / 10;  
    }  
    /*separating days*/
    divisor = 1000;  
    for (i = 0; i < 2; i++) {  
        days = (totalE / divisor) % 10;  
        divisor = divisor / 10;  
        totalD = totalD + days * divisor;  
    }  
    totalD = totalD / 10;  
    /*separating months*/
    divisor = 100000;  
    for (i = 0; i < 2; i++) {  
        months = (totalE / divisor) % 10;  
        divisor = divisor / 10;  
        totalM = totalM + months * divisor;  
    }  
    /*collect encode total to scramble*/
    totalM  = totalM / 1000;  
    divisor = 10000;  
    scramble = totalY * divisor;  
    divisor = divisor / 100;  
    scramble = scramble + totalM * divisor;    
    scramble = scramble + totalD;  
    return scramble;  
}  
/*unscramble and decode to display arrival*/
int displayArrival(int scramble) { 
    int decode = 0, i, divisor, digit, years = 0, months = 0, days = 0, unscD = 0, unscM = 0, unscY = 0, tempdiv = 10,unscrambled;
    /*unscrambling years*/   
    divisor = 100000;  
    for (i = 0; i < 2; i++) {  
        years = (scramble / divisor) % 10; 
        unscY = unscY + years * divisor;
        divisor = divisor / 10;  
    } 
    unscY /= 10000;
    /*unscrambling months*/
    divisor = 1000;  
    for (i = 0; i < 2; i++) {  
        months = (scramble / divisor) % 10; 
        unscM= unscM + months * divisor;
        divisor = divisor / 10; 
    }
    unscM *= 100; 
    /*unscrambling days*/
    divisor = 10;  
    for (i = 0; i < 2; i++) {  
        days = (scramble / divisor) % 10; 
        unscD = unscD + days * divisor;
        divisor = divisor / 10;  
    } 
    unscD *= 100;
    unscrambled = unscD + unscM + unscY;
    /*reset divisor and decode the digits*/
    divisor = 100000;
    for (i = 0; i < 6; i++) {
        digit = (unscrambled / divisor) % 10;
        if (digit - 7 >= 0) {
            decode = decode + (digit - 7) * divisor;
        }
        else {   
            decode = decode + (digit - 7 + 10) * divisor;        
        }
        divisor /= 10;
    }
    /*separate into format: mm dd yy*/
    months = decode / 10000;
    days = (decode / 100) %100;
    /*Display correct year*/
    years = (decode % 100);
    if (years > 25) {
        years = years + 1900;
    }
    else {
        years = years + 2000;
    }
    /*Display Arrival*/
    printf("\nThe President will arrive on ");
    /*search for month*/
    switch(months){
        case 1: printf("January");
        break;
        case 2: printf("Febuary");
        break;
        case 3: printf("March");
        break;
        case 4: printf("April");
        break;
        case 5: printf("May");
        break;
        case 6: printf("June");
        break;
        case 7: printf("July");
        break;
        case 8: printf("August");
        break;
        case 9: printf("September");
        break;
        case 10: printf("October");
        break;
        case 11: printf("November");
        break;
        case 12: printf("December");
        break; 
    }
    /*display other outputs*/
    printf(" %d, %d", days, years);
    return 0; 
} 
/*calling the functions*/
int main() {  
    int date, encode, digit, datescr, displayA;  
    date = enterDate();  
    encode = encodeDate(date);  
    datescr = scrambleDate(encode); 
    displayA = displayArrival(datescr); 
    return 0;  
} 