#include "mbed.h"
#include "routes.h"

/* sensors */
#include "hts221.h"
#include "LPS25H.h"

I2C i2c(PB_9, PB_8);	// (sda, scl)

HTS221 tempHumi(i2c);
LPS25H tempPres(i2c, LPS25H_G_CHIP_ADDR);

http_code_t sensorRoute(char * token, method_t m, char * content, char * response) {
    /* only get supported for this route */
    if (m != GET) return _404_;

    float temp, humi, press;

    tempHumi.ReadTempHumi(&temp, &humi);
    tempPres.get();
    press = tempPres.pressure();

    token = strtok(NULL, "/");

    if (token != NULL) {

        if (strcmp(token, "temp") == 0) {
            sprintf(response, "{\"temp\":%f}", temp);
            return _200_;
        } else if (strcmp(token, "humi") == 0) {
            sprintf(response, "{\"humi\":%f}", humi);
            return _200_;
        } else if (strcmp(token, "press") == 0) {
            sprintf(response, "{\"press\":%f}", press);
            return _200_;
        }
    } else {    /* return all sensor data */

        sprintf(response, "{\"temp\":%f,\"humi\":%f,\"press\":%f}", temp, humi, press);
        return _200_;
    }

    return _404_;
}

void sensorsInit() {
    tempHumi.init();
}