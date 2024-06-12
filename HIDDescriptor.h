#ifndef HID_DESCRIPTOR_H
#define HID_DESCRIPTOR_H

#include <Arduino.h>
#include <PluggableUSB.h>

extern const uint8_t keyboardReportDescriptor[] PROGMEM;
extern const uint32_t keyboardReportDescriptorSize;
extern const uint8_t mouseReportDescriptor[] PROGMEM;
extern const uint32_t mouseReportDescriptorSize;

// HID 'Driver'
// ------------
// clang-format off
#define HID_GET_REPORT   0x01
#define HID_GET_IDLE     0x02
#define HID_GET_PROTOCOL 0x03
#define HID_SET_REPORT   0x09
#define HID_SET_IDLE     0x0A
#define HID_SET_PROTOCOL 0x0B

#define HID_HID_DESCRIPTOR_TYPE      0x21
#define HID_REPORT_DESCRIPTOR_TYPE   0x22
#define HID_PHYSICAL_DESCRIPTOR_TYPE 0x23

// HID subclass HID1.11 Page 8 4.2 Subclass
#define HID_SUBCLASS_NONE 0
#define HID_SUBCLASS_BOOT_INTERFACE 1

// HID Keyboard/Mouse bios compatible protocols HID1.11 Page 9 4.3 Protocols
#define HID_PROTOCOL_NONE 0
#define HID_PROTOCOL_KEYBOARD 1
#define HID_PROTOCOL_MOUSE 2

// Normal or bios protocol (Keyboard/Mouse) HID1.11 Page 54 7.2.5 Get_Protocol Request
// "protocol" variable is used for this purpose.
#define HID_BOOT_PROTOCOL	0
#define HID_REPORT_PROTOCOL	1

// HID Request Type HID1.11 Page 51 7.2.1 Get_Report Request
#define HID_REPORT_TYPE_INPUT   1
#define HID_REPORT_TYPE_OUTPUT  2
#define HID_REPORT_TYPE_FEATURE 3

#define D_HIDREPORT(length) { 9, 0x21, 0x01, 0x01, 0, 1, 0x22, lowByte(length), highByte(length) }
// clang-format on

typedef struct {
  uint8_t len;
  uint8_t dtype;
  uint8_t addr;
  uint8_t versionL;
  uint8_t versionH;
  uint8_t country;
  uint8_t desctype;
  uint8_t descLenL;
  uint8_t descLenH;
} HIDDescDescriptor;

typedef struct {
  InterfaceDescriptor hid;
  HIDDescDescriptor desc;
  EndpointDescriptor in;
} HIDDescriptor;

struct KeyReport {
  uint8_t modifiers{0};
  uint8_t reserved{0};
  uint8_t keys[6] = {0};
};

struct MouseReport {
  uint8_t buttons{0};
  int8_t x{0};
  int8_t y{0};
};

#endif
