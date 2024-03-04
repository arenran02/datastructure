#include <stdio.h>
#pragma warning(disable:4996)

struct Time{
    int hours;
    int minutes;
    int seconds;
};

struct Time calculateTimeDifference(struct Time time1, struct Time time2);

int main(){
    struct Time startTime, endTime, timeDifference;

    scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);
    scanf("%d %d %d", &endTime.hours, &endTime.minutes, &endTime.seconds);

    timeDifference=calculateTimeDifference(startTime, endTime);
    printf("%d %d %d", timeDifference.hours, timeDifference.minutes, timeDifference.seconds);

}

struct Time calculateTimeDifference(struct Time time1, struct Time time2) {
    struct Time difference;
    int totalSeconds1 = time1.hours * 3600 + time1.minutes * 60 + time1.seconds;
    int totalSeconds2 = time2.hours * 3600 + time2.minutes * 60 + time2.seconds;
    int differenceSeconds = totalSeconds2 - totalSeconds1;

    if (differenceSeconds<0){
        differenceSeconds=(-1)*(differenceSeconds);
    }

    difference.hours = differenceSeconds / 3600;
    difference.minutes = (differenceSeconds % 3600) / 60;
    difference.seconds = differenceSeconds % 60;

    return difference;
}