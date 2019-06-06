#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//In the file you can find the daily log of a shop's traffic sensor. For every hour it logs the number of incoming and outgoing customers
//The first line tells you how much hours it was working. Let's say this number is N.
//Then N lines follows. Each of them contains the time frame and 0s and 1s. 0 means a customer left the store, 1 means a customer entered the store.
//Create a function that reads the data and returns a pointer to it and the size.
//Create functions to answer the following questions:

//How many customers the shop had that day?
//What was the time with the most traffic?(Sum of incoimng and outgoing customers)
//When the shop needs the most cashiers?(When was the time the most customer was in ther store)
//Does it worth to keep the shop open in the last 2 hours? It worths it if at least 5% of the total customers was in the store at the last 2 hours.

typedef struct hour_data {
    int start_hour;
    int customer_entered;
    int customer_exited;
} hour_data_t;

int late_hours(hour_data_t *data);

int most_customers(hour_data_t *data);

int biggest_traffic(hour_data_t *data);

int customer_count(hour_data_t *data);

hour_data_t parse_hour_line(char *line);

hour_data_t *process_file(char *path);

char *read_line(FILE *file);


int main()
{
    hour_data_t *data = process_file("file.txt");

    int customers = customer_count(data);
    int max_traffic = biggest_traffic(data);
    int busiest_hour = most_customers(data);
    int worth_to_open = late_hours(data);

    printf("The shop had %d customers.\n", customers);
    printf("The traffic was the biggest from %d hours to %d hours.\n", max_traffic, max_traffic + 1);
    printf("The most customers were from %d hours to %d hours.\n", busiest_hour, busiest_hour + 1);
    printf("It %s worth to be open the last to hours,\n", worth_to_open ? "is" : "is not");


    free(data);
    return 0;
}

int late_hours(hour_data_t *data)
{
    int sum_customers = customer_count(data);
    int late_hours_sum = data[14].customer_entered + data[14].customer_entered;

    if ((float) late_hours_sum / (float) sum_customers >= 0.05)
        return 1;
    else
        return 0;
}

int most_customers(hour_data_t *data)
{
    int customers = 0;
    int temp_coustomers = 0;
    int hour = 0;

    for (int i = 0; i < 16; ++i) {
        temp_coustomers = data[i].customer_entered - data[i].customer_exited;
        if (temp_coustomers > customers) {
            customers = temp_coustomers;
            hour = data[i].start_hour;
        }
    }
    return hour;
}

int biggest_traffic(hour_data_t *data)
{
    int max_traffic = 0;
    int temp_traffic = 0;
    int hour = 0;

    for (int i = 0; i < 16; ++i) {
        temp_traffic = data[i].customer_entered + data[i].customer_exited;
        if (temp_traffic > max_traffic) {
            max_traffic = temp_traffic;
            hour = data[i].start_hour;
        }
    }
    return hour;
}

int customer_count(hour_data_t *data)
{
    int customer_sum = 0;

    for (int i = 0; i < 16; ++i) {
        customer_sum += data[i].customer_entered;
    }
    return customer_sum;
}

hour_data_t *process_file(char *path)
{
    FILE *file;
    file = fopen(path, "r");
    char *line;

    //Storing hours
    char hours_string[3];
    int hours = 0;

    if (file == NULL) {
        printf("File open error");
        return NULL;
    }

    fgets(hours_string, 3, file);
    hours = atoi(hours_string);

    hour_data_t *file_data = (hour_data_t *) malloc(sizeof(hour_data_t) * hours);

    //Move file pointer by 1 to start of next line
    fgetc(file);

    for (int i = 0; i < hours; ++i) {
        line = read_line(file);
        file_data[i] = parse_hour_line(line);
        free(line);
    }

    fclose(file);
    return file_data;
}

char *read_line(FILE *file)
{
    //Storing line
    int line_size = 0;
    char *line = (char *) malloc(sizeof(char));
    line[line_size] = '\0';

    int buffer = fgetc(file);
    while (buffer != '\n' && buffer != EOF) {
        line = (char *) realloc(line, sizeof(char) * line_size + 2);
        line[line_size] = buffer;
        line[line_size + 1] = '\0';
        line_size++;

        buffer = fgetc(file);
    }
    return line;
}

hour_data_t parse_hour_line(char *line)
{
    int entered = 0;
    int exited = 0;
    char *temp;
    hour_data_t result;

    char *hour_string = strtok(line, ":");
    result.start_hour = atoi(hour_string);

    //Skipping rest of time frame string
    strtok(NULL, " ");

    do {
        temp = strtok(NULL, " ");
        if (temp == NULL)
            break;

        if (*temp == '1')
            entered++;
        if (*temp == '0')
            exited++;
    } while (1);

    result.customer_entered = entered;
    result.customer_exited = exited;

    return result;
}