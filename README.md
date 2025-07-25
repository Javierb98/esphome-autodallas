# ESPHome AutoDallas Sensor

This component automatically selects the first DS18B20 sensor found on the Dallas OneWire bus. No need to specify the sensor address.

## Usage

```yaml
external_components:
  - source: github://Javierb98/esphome-autodallas@main

one_wire:
  - platform: gpio
    pin: GPIO5
    id: one_wire_bus

dallas_temp:
  - pin: GPIO5
    id: dallas

sensor:
  - platform: custom
    lambda: |-
      auto sensor = new esphome::autodallas::AutoDallasSensor(id(dallas));
      App.register_component(sensor);
      return {sensor};
    sensors:
      name: "Water Temperature"
      unit_of_measurement: "°C"
      accuracy_decimals: 1
      update_interval: 1s
