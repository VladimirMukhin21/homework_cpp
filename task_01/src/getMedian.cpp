#include "getMedian.hpp"

int GetMedian(int first_num, int second_num, int third_num) {
    if ((first_num <= second_num) && (second_num <= third_num)){
        return second_num;
    }
    else if ((first_num <= third_num) && (third_num <= second_num)){
        return third_num;
    }
    else if ((second_num <= first_num) && (first_num <= third_num)){
        return first_num;
    }
    else if ((second_num <= third_num) && (third_num <= first_num)){
        return third_num;
    }
    else if ((third_num <= first_num) && (first_num <= second_num)){
        return first_num;
    }
    else if ((third_num <= second_num) && (second_num <= first_num)){
        return second_num;
    }
    else {
        return 0;
    }
};