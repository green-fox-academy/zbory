#include <iostream>
#include <vector>

int sum(std::vector<int> vector);
int average(std::vector<int> vector);
int max(std::vector<int> vector);
int min(std::vector<int> vector);

int main() {
//Create a list with the following items.
//500, 1000, 1250, 175, 800 and 120

    std::vector<int> finances = {500, 1000, 1250, 175, 800, 120};

//    Create an application which solves the following problems.
//    How much did we spend?
//    Which was our greatest expense?
//    Which was our cheapest spending?
//    What was the average amount of our spendings?

    std::cout << "Sum: " << sum(finances) << std::endl;
    std::cout << "Max: " << max(finances) << std::endl;
    std::cout << "Min: " << min(finances) << std::endl;
    std::cout << "Average: " << average(finances) << std::endl;


    return 0;
}

int sum(std::vector<int> vector) {
    int sum = 0;

    for (unsigned int i = 0; i < vector.size(); i++) {
        sum += vector[i];
    }
    return sum;
}
int average(std::vector<int> vector){
    int sum = 0;

    for(unsigned int i = 0; i < vector.size(); i++){
        sum += vector[i];
    }
    return (double)sum / vector.size();
}
int max(std::vector<int> vector){
    int max_value = vector[0];
    for (unsigned int i = 0; i < vector.size(); i++) {
        if(max_value < vector[i])
            max_value = vector[i];
    }
    return max_value;
}
int min(std::vector<int> vector){
    int min_value = vector[0];
    for (unsigned int i = 0; i < vector.size(); i++) {
        if(min_value > vector[i])
            min_value = vector[i];
    }
    return min_value;
}