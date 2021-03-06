#ifndef ROUTES_H
#define ROUTES_H

#include "http.h"

http_code_t ledRoute(method_t m, char * content, char * response);
http_code_t ipRoute(char * token, method_t m, char * content, char * response);
http_code_t userRoute(char * token, method_t m, char * content, char * response);
http_code_t sensorRoute(char * token, method_t m, char * content, char * response);
http_code_t timeRoute(char * token, method_t m, char * content, char * response);
http_code_t fileRoute(char * token, method_t m, char * content, char * response, FILE ** file);

/* init functions */
void sensorsInit();


#endif /* ROUTES_H */