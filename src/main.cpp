#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *make_request(void *arg) {
    const char *url = "https://www.google.com";
    const char *method = "GET";
    char request_command[256];

    snprintf(request_command, sizeof(request_command), "curl -X %s %s", method, url);

    int result = system(request_command);

    if (result != 0) {
        fprintf(stderr, "Failed to execute the request.\n");
    }

    return NULL;
}

void *make_json_request(void *arg) {
    const char *url = "https://icanhazdadjoke.com/";
    const char *method = "GET";
    char request_command[256];

    snprintf(request_command, sizeof(request_command), "curl -H \"Content-Type: application/json\" -X %s %s", method, url)["joke"];

    int result = system(request_command);

    if (result != 0) {
        fprintf(stderr, "Failed to execute the request.\n");
    }

    return NULL;
}

int main(void) {
    pthread_t request_thread_1, request_thread_2;

    // HTML Request
    // if (pthread_create(&request_thread_1, NULL, make_request, NULL) != 0) {
    //     fprintf(stderr, "Error creating thread for make_request.\n");
    //     return 1;
    // }

    // JSON Request
    if (pthread_create(&request_thread_2, NULL, make_json_request, NULL) != 0) {
        fprintf(stderr, "Error creating thread for make_json_request.\n");
        return 1;
    }

    // pthread_join(request_thread_2, NULL);
    pthread_join(request_thread_2, NULL);

    return 0;
}
