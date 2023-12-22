/*
   homekit.c
   Define the accessory in C language using the Macro in characteristics.h
   based on Arduino-HomeKit-ESP8266 example code by Mixiaoxiao (Wang Bin)
*/

#include <homekit/homekit.h>
#include <homekit/characteristics.h>

// Called to identify this accessory. See HAP section 6.7.6 Identify Routine
// Generally this is called when paired successfully or click the "Identify Accessory" button in Home APP.
void my_accessory_identify(homekit_value_t _value) {
}


// format: uint8; 0 ("unknown"), 1 ("excellent"), 2 ("good"), 3 ("fair"), 4 ("inferior"), 5 ("poor")
homekit_characteristic_t cha_airquality = HOMEKIT_CHARACTERISTIC_(AIR_QUALITY, 0);

// format: float; min 0, max 1000, unit micrograms per cubic meter
homekit_characteristic_t cha_pm25 = HOMEKIT_CHARACTERISTIC_(PM25_DENSITY, 0);

// format: float; min 0, max 100000, unit PPM
homekit_characteristic_t cha_co2 = HOMEKIT_CHARACTERISTIC_(CARBON_DIOXIDE_LEVEL, 0);

// format: float; min 0, max 1000, unit micrograms per cubic meter
homekit_characteristic_t cha_voc = HOMEKIT_CHARACTERISTIC_(VOC_DENSITY, 0);

// format: float; min 0, max 1000, unit micrograms per cubic meter
homekit_characteristic_t cha_no2 = HOMEKIT_CHARACTERISTIC_(NITROGEN_DIOXIDE_DENSITY, 0);

// format: float; min 0, max 100, step 0.1, unit celsius
homekit_characteristic_t cha_temperature = HOMEKIT_CHARACTERISTIC_(CURRENT_TEMPERATURE, 0);

// format: float; min 0, max 100, step 1
homekit_characteristic_t cha_humidity = HOMEKIT_CHARACTERISTIC_(CURRENT_RELATIVE_HUMIDITY, 0);


// (optional) format: bool; HAP section 9.96
// homekit_characteristic_t cha_status_active = HOMEKIT_CHARACTERISTIC_(STATUS_ACTIVE, true);

// (optional) format: uint8; HAP section 9.97; 0 "No Fault", 1 "General Fault"
// homekit_characteristic_t cha_status_fault = HOMEKIT_CHARACTERISTIC_(STATUS_FAULT, 0);


homekit_accessory_t *accessories[] = {
  HOMEKIT_ACCESSORY(.id = 1, .category = homekit_accessory_category_sensor, .services = (homekit_service_t*[]) {
    HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics = (homekit_characteristic_t*[]) {
      HOMEKIT_CHARACTERISTIC(NAME, "AirGradient DIY PRO"),
      HOMEKIT_CHARACTERISTIC(MANUFACTURER, "Arduino HomeKit"),
      HOMEKIT_CHARACTERISTIC(SERIAL_NUMBER, "0123456"),
      HOMEKIT_CHARACTERISTIC(MODEL, "ESP8266"),
      HOMEKIT_CHARACTERISTIC(FIRMWARE_REVISION, "1.0"),
      HOMEKIT_CHARACTERISTIC(IDENTIFY, my_accessory_identify),
      NULL
    }),
    HOMEKIT_SERVICE(AIR_QUALITY_SENSOR, .primary = true, .characteristics = (homekit_characteristic_t*[]) {
      HOMEKIT_CHARACTERISTIC(NAME, "Air Quality Sensor"),
                             &cha_airquality,
                             &cha_pm25,
                             &cha_co2,
                             &cha_voc,
                             &cha_no2,
                             NULL
    }),
    HOMEKIT_SERVICE(TEMPERATURE_SENSOR, .characteristics = (homekit_characteristic_t*[]) {
      HOMEKIT_CHARACTERISTIC(NAME, "Temperature Sensor"),
                             &cha_temperature,
                             NULL
    }),
    HOMEKIT_SERVICE(HUMIDITY_SENSOR, .characteristics = (homekit_characteristic_t*[]) {
      HOMEKIT_CHARACTERISTIC(NAME, "Humidity Sensor"),
                             &cha_humidity,
                             NULL
    }),
    NULL
  }),
  NULL
};


homekit_server_config_t config = {
  .accessories = accessories,
  .password = "111-11-111",
};
