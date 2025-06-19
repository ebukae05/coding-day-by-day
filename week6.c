#include <stdio.h>
//President secret service Code that collects arrival Date as input, then encodes, scrambles, decodes and displays arrival

//made a void function to define arrays
void Put(int date[]) {
    int digits;
    for (int i = 0; i < 6; i++) {
        digits = date[i];
    }
}
//Get input and assign to arrays, collect total
int enterDate(int date[]) {
    int i, divisor = 10, total = 0;
    printf("Enter date of arrival in format, m m d d y y: ");

    for (i = 0; i < 6; i++) {
        scanf("%d", &date[i]);
    }

    for (i = 0; i < 6; i++) {
        total = (total * divisor) + date[i];
    }

    return total;
}
//call date, then encode the array
void encode(int date[], int encDigit[]){
    int i;
    Put(date);
    for(i = 0; i < 6; i++) {
        encDigit[i] = (date[i] + 7) % 10;
    }
    
}
//call local encode,accumulate total
int encodeDate(int date[], int total, int encDigit[]) {
    int i, divisor = 10, encTotal= 0;
    encode(date, encDigit);
    for (i = 0; i < 6; i++) {
        encTotal = (encTotal * divisor) + encDigit[i];
    }
    return encTotal;
}
//scramble digits and assign to an array
int scrambleDate(int date[],int encDigit[], int encTotal,int scramble[]) {
    int  i, divisor = 100000, datescr = 0;
    for (i = 4; i < 6; i++) {
        scramble[i] = encDigit[i] * divisor;
        datescr = datescr + scramble[i];
        divisor /= 10;
    }
    divisor = 1000;
    for (i = 0; i < 2; i++){
        scramble[i] = encDigit[i] * divisor;
        datescr = datescr + scramble[i];
        divisor /= 10;
    }
    divisor = 10;
    for (i = 2; i < 4;i++ ) {
        scramble[i] = encDigit[i] * divisor;
        datescr = datescr + scramble[i];
        divisor /= 10;
    }
    return datescr;
}
//unscramble digits and assign to array, then collect total
void firstUnscramb(int scramble[], int descramble[]) {
    int arrival, i, divisor = 10000, unscrambled = 0;
    for (i = 4; i < 6; i++) {
        descramble[i] = scramble[i] / divisor;
        unscrambled += descramble[i];
    }
    divisor = 100;
    for (i = 2; i < 4; i++) {
        descramble[i] = scramble[i] * divisor;
        unscrambled += descramble[i];
    }
    divisor = 100;
    for (i = 0; i < 2; i++) {
        descramble[i] = scramble[i] * divisor;
        unscrambled += descramble[i];
    }
}
//call unscramble void, separate given digits into array
void separateDigit(int scramble[],int descramble[], int encDigits2[]) {
    int i = 0, divisor = 100000;
    firstUnscramb(scramble, descramble);
    for (i = 0; i < 6; i++) {
        encDigits2[i] = descramble[i] / divisor;
        divisor /= 10;

    }
}
//call separated digit void, then decode the digit
void decodeDigits(int scramble[], int encDigits2[], int descramble[], int unscrambled, int decode[]) {
    int arrival, divisor = 0, i = 1;
    separateDigit(scramble,descramble,encDigits2);
    for (i = 0; i < 6; i++) {
        if (encDigits2[i] - 7 >= 0 ) {
            decode[i] = encDigits2[i] - 7;
        }
        else {
            decode[i] = encDigits2[i] - 7 + 10;
        }
    }

}
//isolate months
void months(int scramble[], int encDigits2[], int descramble[], int unscrambled, int decode[], int *month) {
    int i = 0, divisor = 10;
    *month = 0;
    decodeDigits(scramble, encDigits2, descramble, unscrambled, decode);
    for(i = 0; i < 2; i++) {
        *month = (*month * divisor) + decode[i];
    }
}
//isolate days
void displayDays(int scramble[], int encDigits2[], int descramble[], int unscrambled, int decode[],int *day) {
    int i, divisor = 10;
    *day = 0;
    decodeDigits(scramble, encDigits2, descramble, unscrambled, decode);
    for (i = 2; i < 4; i++) {
        *day = (*day * divisor) + decode[i];
    }
}
//isolate years
void displayYears(int scramble[], int encDigits2[], int descramble[], int unscrambled, int decode[], int *years) {
    int i, divisor = 10;
    decodeDigits(scramble, encDigits2, descramble, unscrambled, decode);
    *years = 0;
    for (i = 4; i < 6; i++){
        *years = (*years * divisor) + decode[i];
    }
    if (*years > 25) {
        *years = *years + 1900;
    }
    else {
        *years = *years + 2000;
    }
}

//call isolated void functions, use switch to find month name, display arrival
int displayArrival(int scramble[], int encDigits2[], int descramble[], int unscrambled, int decode[], int *month, int *day, int *years) {
    months(scramble,encDigits2,descramble,unscrambled,decode,month);
    displayDays(scramble,encDigits2,descramble,unscrambled,decode,day);
    displayYears(scramble, encDigits2, descramble, unscrambled, decode, years);
    printf("The President will arrive on: ");
    switch(*month) {
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
    printf(" %d, %d", *day, *years);
    return 0;
}

//call the functions
int main() {
    int years,days,decode[6],month, date[6],descramble[6], total, encodeResult, encDigit[6],scramb,unscrambled, encTotal, scramble[6], display, datescr, encDigits2[6];

    total = enterDate(date);
    encTotal = encodeDate(date, total, encDigit);
    scramb = scrambleDate(date,encDigit,encTotal, scramble);
    display = displayArrival(scramble,encDigits2, descramble, unscrambled, decode, &month, &days, &years);
    return 0;
}