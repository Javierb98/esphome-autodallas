#pragma once

#include "esphome/components/dallas_temp/dallas_temp_sensor.h"

namespace esphome {
namespace autodallas {

class AutoDallasSensor : public dallas_temp::DallasTempSensor, public PollingComponent {
 public:
  AutoDallasSensor(dallas_temp::DallasTemp *dallas) {
    this->dallas_ = dallas;
  }

  void setup() override {
    auto sensors = this->dallas_->get_sensors();
    if (sensors.empty()) {
      ESP_LOGW("autodallas", "No Dallas sensors found.");
      return;
    }

    this->set_address(sensors[0]->get_address64());
    ESP_LOGI("autodallas", "Using Dallas sensor with address: 0x%016llX", sensors[0]->get_address64());
    dallas_temp::DallasTempSensor::setup();
  }

  void update() override {
    dallas_temp::DallasTempSensor::update();
  }

 protected:
  dallas_temp::DallasTemp *dallas_;
};

}  // namespace autodallas
}  // namespace esphome
