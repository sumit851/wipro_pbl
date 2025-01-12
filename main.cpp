#include <iostream>
#include <string>

using namespace std;


struct TIME {
    int hours;
    int minutes;
    int seconds;
};


void PrintTime(TIME t1) {
    printf("%02d:%02d:%02d", t1.hours, t1.minutes, t1.seconds);
}


int CompareTime(TIME t1, TIME t2) {
    if (t1.hours == t2.hours && t1.minutes == t2.minutes && t1.seconds == t2.seconds)
        return 1;
    return 0;
}


TIME GetDifference(TIME *pt1, TIME *pt2) {
    TIME diff;
    int totalSeconds1 = pt1->hours * 3600 + pt1->minutes * 60 + pt1->seconds;
    int totalSeconds2 = pt2->hours * 3600 + pt2->minutes * 60 + pt2->seconds;
    int diffSeconds = abs(totalSeconds1 - totalSeconds2);
    
    diff.hours = diffSeconds / 3600;
    diffSeconds %= 3600;
    diff.minutes = diffSeconds / 60;
    diff.seconds = diffSeconds % 60;
    
    return diff;
}


int main(int argc, char *argv[]) {
    if (argc != 7) {
        printf("Invalid number of arguments\n");
        return 1;
    }
    
    TIME t1 = {atoi(argv[1]), atoi(argv[2]), atoi(argv[3])};
    TIME t2 = {atoi(argv[4]), atoi(argv[5]), atoi(argv[6])};
    
  
    printf("First time: ");
    PrintTime(t1);
    printf("\n");
    
   
    printf("Second time: ");
    PrintTime(t2);
    printf("\n");
    
 
    if (CompareTime(t1, t2))
        printf("Times are identical\n");
    else
        printf("Times are different\n");
    

    TIME diff = GetDifference(&t1, &t2);
    printf("Time difference: ");
    PrintTime(diff);
    printf("\n");
    
    return 0;
}
