#include "RubberJogi.h"

#include "Keys.h"

namespace {
enum MouseButtons : uint8_t {
  LEFT = 1,
  RIGHT = 2,
  MIDDLE = 4,
};

bool isKeyboardCommand(String cmd) {
  cmd.toUpperCase();
  return cmd == "ENTER" || cmd == "DOWNARROW" || cmd == "DOWN" ||
         cmd == "LEFTARROW" || cmd == "LEFT" || cmd == "RIGHTARROW" ||
         cmd == "RIGHT" || cmd == "UPARROW" || cmd == "UP" || cmd == "DELETE" ||
         cmd == "DEL" || cmd == "END" || cmd == "ESC" || cmd == "ESCAPE" ||
         cmd == "HOME" || cmd == "INSERT" || cmd == "PAGEUP" ||
         cmd == "PAGEDOWN" || cmd == "PRINTSCREEN" || cmd == "SPACE" ||
         cmd == "TAB" || cmd == "F1" || cmd == "F2" || cmd == "F3" ||
         cmd == "F4" || cmd == "F5" || cmd == "F6" || cmd == "F7" ||
         cmd == "F8" || cmd == "F9" || cmd == "F10" || cmd == "F11" ||
         cmd == "F12" || cmd == "FUNCTION1" || cmd == "FUNCTION2" ||
         cmd == "FUNCTION3" || cmd == "FUNCTION4" || cmd == "FUNCTION5" ||
         cmd == "FUNCTION6" || cmd == "FUNCTION7" || cmd == "FUNCTION8" ||
         cmd == "FUNCTION9" || cmd == "FUNCTION10" || cmd == "FUNCTION11" ||
         cmd == "FUNCTION12" || cmd == "BACKSPACE" || cmd == "CAPSLOCK" ||
         cmd == "SCROLLLOCK" || cmd == "NUMLOCK" || cmd == "MENU" ||
         cmd == "APP" || cmd == "PAUSE" || cmd == "BREAK" ||
         cmd.startsWith("SHIFT ") || cmd.startsWith("ALT ") ||
         cmd.startsWith("CTRL ") || cmd.startsWith("CONTROL ") ||
         cmd.startsWith("GUI ") || cmd.startsWith("WINDOWS ") ||
         cmd.startsWith("STRING ") || cmd.startsWith("INJECT_MOD ");
}

bool isMouseCommand(const String &cmd) {
  return cmd.substring(0, 5).equalsIgnoreCase("MOUSE");
}

bool isSwitchCommand(String cmd) {
  cmd.toUpperCase();
  return cmd.startsWith("SWITCH") || cmd == "BOOT" || cmd == "REBOOT" ||
         cmd == "ATEN";
}

bool isDelayCommand(const String &cmd) {
  return cmd.substring(0, 5).equalsIgnoreCase("DELAY");
}

bool isComment(const String &cmd) { return cmd.equalsIgnoreCase("REM"); }

uint8_t getKeyCode(const String &key) {
  if (key.length() == 1) {
    return key[0];
  } else if (key.equalsIgnoreCase("ENTER")) {
    return KEY_RETURN;
  } else if (key.equalsIgnoreCase("MENU") || key.equalsIgnoreCase("APP")) {
    return KEY_MENU;
  } else if (key.equalsIgnoreCase("DOWNARROW") ||
             key.equalsIgnoreCase("DOWN")) {
    return KEY_DOWN_ARROW;
  } else if (key.equalsIgnoreCase("LEFTARROW") ||
             key.equalsIgnoreCase("LEFT")) {
    return KEY_LEFT_ARROW;
  } else if (key.equalsIgnoreCase("RIGHTARROW") ||
             key.equalsIgnoreCase("RIGHT")) {
    return KEY_RIGHT_ARROW;
  } else if (key.equalsIgnoreCase("UPARROW") || key.equalsIgnoreCase("UP")) {
    return KEY_UP_ARROW;
  } else if (key.equalsIgnoreCase("PAUSE") || key.equalsIgnoreCase("BREAK")) {
    return KEY_PAUSE;
  } else if (key.equalsIgnoreCase("CAPSLOCK")) {
    return KEY_CAPS_LOCK;
  } else if (key.equalsIgnoreCase("DELETE") || key.equalsIgnoreCase("DEL")) {
    return KEY_DELETE;
  } else if (key.equalsIgnoreCase("END")) {
    return KEY_END;
  } else if (key.equalsIgnoreCase("ESC") || key.equalsIgnoreCase("ESCAPE")) {
    return KEY_ESC;
  } else if (key.equalsIgnoreCase("HOME")) {
    return KEY_HOME;
  } else if (key.equalsIgnoreCase("INSERT")) {
    return KEY_INSERT;
  } else if (key.equalsIgnoreCase("NUMLOCK")) {
    return KEY_NUM_LOCK;
  } else if (key.equalsIgnoreCase("PAGEUP")) {
    return KEY_PAGE_UP;
  } else if (key.equalsIgnoreCase("PAGEDOWN")) {
    return KEY_PAGE_DOWN;
  } else if (key.equalsIgnoreCase("PRINTSCREEN")) {
    return KEY_PRINT_SCREEN;
  } else if (key.equalsIgnoreCase("SCROLLLOCK")) {
    return KEY_SCROLL_LOCK;
  } else if (key.equalsIgnoreCase("SPACE")) {
    return KEY_SPACE;
  } else if (key.equalsIgnoreCase("BACKSPACE")) {
    return KEY_BACKSPACE;
  } else if (key.equalsIgnoreCase("TAB")) {
    return KEY_TAB;
  } else if (key.equalsIgnoreCase("GUI") || key.equalsIgnoreCase("WINDOWS")) {
    return KEY_LEFT_GUI;
  } else if (key.equalsIgnoreCase("SHIFT")) {
    return KEY_RIGHT_SHIFT;
  } else if (key.equalsIgnoreCase("ALT")) {
    return KEY_LEFT_ALT;
  } else if (key.equalsIgnoreCase("CTRL") || key.equalsIgnoreCase("CONTROL")) {
    return KEY_LEFT_CTRL;
  } else if (key.equalsIgnoreCase("F1") || key.equalsIgnoreCase("FUNCTION1")) {
    return KEY_F1;
  } else if (key.equalsIgnoreCase("F2") || key.equalsIgnoreCase("FUNCTION2")) {
    return KEY_F2;
  } else if (key.equalsIgnoreCase("F3") || key.equalsIgnoreCase("FUNCTION3")) {
    return KEY_F3;
  } else if (key.equalsIgnoreCase("F4") || key.equalsIgnoreCase("FUNCTION4")) {
    return KEY_F4;
  } else if (key.equalsIgnoreCase("F5") || key.equalsIgnoreCase("FUNCTION5")) {
    return KEY_F5;
  } else if (key.equalsIgnoreCase("F6") || key.equalsIgnoreCase("FUNCTION6")) {
    return KEY_F6;
  } else if (key.equalsIgnoreCase("F7") || key.equalsIgnoreCase("FUNCTION7")) {
    return KEY_F7;
  } else if (key.equalsIgnoreCase("F8") || key.equalsIgnoreCase("FUNCTION8")) {
    return KEY_F8;
  } else if (key.equalsIgnoreCase("F9") || key.equalsIgnoreCase("FUNCTION9")) {
    return KEY_F9;
  } else if (key.equalsIgnoreCase("F10") ||
             key.equalsIgnoreCase("FUNCTION10")) {
    return KEY_F10;
  } else if (key.equalsIgnoreCase("F11") ||
             key.equalsIgnoreCase("FUNCTION11")) {
    return KEY_F11;
  } else if (key.equalsIgnoreCase("F12") ||
             key.equalsIgnoreCase("FUNCTION12")) {
    return KEY_F12;
  }

  return -1;
}

bool isModifierKey(uint8_t key) {
  switch (key) {
  case KEY_LEFT_SHIFT:
  case KEY_RIGHT_SHIFT:
  case KEY_LEFT_ALT:
  case KEY_RIGHT_ALT:
  case KEY_LEFT_CTRL:
  case KEY_RIGHT_CTRL:
  case KEY_LEFT_GUI:
  case KEY_RIGHT_GUI:
    return true;
  default:
    return false;
  }
}

} // namespace

RubberJogi::RubberJogi()
    : PluggableUSBModule(NUM_INTERFACES, NUM_ENDPOINTS, _epType) {
  Serial1.begin(9600);

  _buffer.reserve(100);

  static_assert(MOUSE_OFFSET < NUM_ENDPOINTS);

  _epType[KEYBOARD_OFFSET] = EP_TYPE_INTERRUPT_IN;
  _epType[MOUSE_OFFSET] = EP_TYPE_INTERRUPT_IN;

  PluggableUSB().plug(this);

  _initSwitches();
}

void RubberJogi::printVersion() const {
  Serial1.println(VERSION);
  Serial1.println("w BOOT/ATEN/SWITCH-Support");
}

void RubberJogi::setKeyboardLayout(const uint8_t *layout) { _layout = layout; }

bool RubberJogi::readCommand() {
  while (Serial1.available()) {
    char c = Serial1.read();

    // CR and LF terminate commands and are not added to the buffer
    // Don't report a new command being available if the buffer is empty
    if (c == '\r' || c == '\n') {
      if (_buffer.length() > 0) {
        Serial1.println(String("Received: ") + _buffer);
        return true;
      } else {
        continue;
      }
    }

    _buffer += c;
  }

  return false;
}

const String &RubberJogi::getCommand() const { return _buffer; }

void RubberJogi::parseCommand() {
  if (isKeyboardCommand(_buffer)) {
    _executeKeyboardCommand(_buffer);
  } else if (isMouseCommand(_buffer)) {
    _executeMouseCommand(_buffer);
  } else if (isSwitchCommand(_buffer)) {
    _executeSwitchCommand(_buffer);
  } else if (isDelayCommand(_buffer)) {
    _executeDelayCommand(_buffer);
  } else if (isComment(_buffer)) {
    _printComment(_buffer);
  } else {
    Serial1.println(String("Invalid command: ") + _buffer);
  }

  _buffer.remove(0, _buffer.length());
}

void RubberJogi::pressButtons(const MouseReport &buttons) const {
  USB_Send(_mouseEndpoint() | TRANSFER_RELEASE, &buttons, sizeof(buttons));
}

void RubberJogi::releaseButtons() const {
  MouseReport report;
  pressButtons(report);
}

void RubberJogi::pressKeys(const KeyReport &keys) const {
  USB_Send(_keyboardEndpoint() | TRANSFER_RELEASE, &keys, sizeof(keys));
}

void RubberJogi::releaseKeys() const {
  KeyReport report;
  pressKeys(report);
}

void RubberJogi::sendKey(uint8_t key) const {
  KeyReport report;
  _addKeyToReport(key, report);
  pressKeys(report);
  releaseKeys();
}

void pressSwitch(int pin, int duration) {
  digitalWrite(pin, HIGH);
  delay(duration);
  digitalWrite(pin, LOW);
}

void setSwitch(int pin, uint8_t state) { digitalWrite(pin, state); }

void RubberJogi::_initSwitches() const {
  for (int i = 2; i < 12; i += 2) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void RubberJogi::_printComment(const String &cmd) const {
  Serial1.println(String("Skipping comment: ") + cmd.substring(4));
}

void RubberJogi::_executeSwitchCommand(String cmd) const {
  cmd.toUpperCase();

  if (cmd == "ATEN") {
    Serial1.println("Pressing ATEN switch");
    pressSwitch(_getPin("ATEN"), 1500);
  } else if (cmd == "BOOT") {
    Serial1.println("Pressing RESET switch");
    pressSwitch(_getPin("RESET"), 1500);
  } else if (cmd == "REBOOT") {
    Serial1.println("Toggling RESET switch");
    pressSwitch(_getPin("RESET"), 10000);
    delay(2000);
    pressSwitch(_getPin("RESET"), 1500);
  } else if (cmd.startsWith("SWITCH")) {
    int idx = cmd.indexOf('_');

    Serial1.println(String("Setting switch ") + cmd.substring(6, idx) +
                    String(" to ") + cmd.substring(idx + 1));

    int pin = _getPin(cmd.substring(6, idx));
    uint8_t state = cmd.substring(idx + 1) == "ON" ? HIGH : LOW;
    setSwitch(pin, state);
  }
}

void RubberJogi::_executeDelayCommand(const String &cmd) const {
  int idx = cmd.indexOf(' ');
  Serial1.println(String("Waiting: ") + cmd.substring(idx) + String("ms"));
  delay(cmd.substring(idx).toInt());
}

void RubberJogi::_executeKeyboardCommand(String cmd) const {
  if (cmd.substring(0, 6).equalsIgnoreCase("STRING")) {
    Serial1.println(String("Typing: ") + cmd.substring(7));

    for (unsigned int i = 7; i < cmd.length(); ++i) {
      sendKey(cmd[i]);
    }
  } else if (cmd.substring(0, 10).equalsIgnoreCase("INJECT_MOD")) {
    uint8_t keyCode = getKeyCode(cmd.substring(11));

    if (isModifierKey(keyCode)) {
      Serial1.println(String("Pressing modifier: ") + cmd.substring(11));
      sendKey(keyCode);
    } else {
      Serial1.println(String("Invalid modifier key: ") + cmd.substring(11));
    }
  } else {
    Serial1.println(String("Sending key combination: ") + cmd);

    KeyReport report;
    int prevIdx = 0;
    int idx = cmd.indexOf(' ', prevIdx);

    auto addKey = [this, &report](const String &key) {
      uint8_t keyCode = getKeyCode(key);

      if (keyCode != static_cast<uint8_t>(-1)) {
        _addKeyToReport(keyCode, report);
      } else {
        Serial1.println(String("Skipping unknown key: ") + key);
      }
    };

    while (idx != -1) {
      addKey(cmd.substring(prevIdx, idx));

      prevIdx = idx + 1;
      idx = cmd.indexOf(' ', prevIdx);
    }

    addKey(cmd.substring(prevIdx, cmd.length()));

    pressKeys(report);
    releaseKeys();
  }
}

void RubberJogi::_executeMouseCommand(String cmd) const {
  cmd = cmd.substring(6);
  cmd.toUpperCase();

  if (cmd.startsWith("MOVE")) {
    int idx = cmd.indexOf(' ', 5);
    int x = cmd.substring(5, idx).toInt();
    int y = cmd.substring(idx + 1).toInt();

    Serial1.println(String("Move mouse by x=") + String(x) + String(" and y=") +
                    String(y));

    MouseReport report;

    while (x != 0 || y != 0) {
      report.x = constrain(x, -127, 127);
      report.y = constrain(y, -127, 127);
      USB_Send(_mouseEndpoint() | TRANSFER_RELEASE, &report, sizeof(report));
      x -= report.x;
      y -= report.y;
    }
  } else {
    MouseReport report;

    if (cmd.startsWith("LEFT")) {
      Serial1.println("Click left mouse button");
      report.buttons |= MouseButtons::LEFT;
    } else if (cmd.startsWith("RIGHT")) {
      Serial1.println("Click right mouse button");
      report.buttons |= MouseButtons::RIGHT;
    } else if (cmd.startsWith("MIDDLE")) {
      Serial1.println("Click middle mouse button");
      report.buttons |= MouseButtons::MIDDLE;
    }

    pressButtons(report);
    releaseButtons();
  }
}

int RubberJogi::_getPin(const String &name) const {
  if (name.equalsIgnoreCase("ATEN")) {
    return 4;
  } else if (name.equalsIgnoreCase("RESET")) {
    return 2;
  } else {
    return name.toInt() * 2;
  }
}

bool RubberJogi::_addKeyToReport(uint8_t key, KeyReport &report) const {
  if (key >= 136) {
    // It's a non-printing key (not a modifier)
    key -= 136;
  } else if (key >= 128) {
    // It's a modifier key
    report.modifiers |= (1 << (key - 128));
    key = 0;
  } else {
    // It's a printing key
    key = pgm_read_byte(_layout + key);

    if ((key & ALT_GR) == ALT_GR) {
      // AltGr = right Alt
      report.modifiers |= 0x40;
      key &= 0x3F;
    } else if ((key & SHIFT) == SHIFT) {
      // the left shift modifier
      report.modifiers |= 0x02;
      key &= 0x7F;
    }

    if (key == ISO_REPLACEMENT) {
      key = ISO_KEY;
    }
  }

  if (report.keys[0] != key && report.keys[1] != key && report.keys[2] != key &&
      report.keys[3] != key && report.keys[4] != key && report.keys[5] != key) {

    int i = 0;
    for (; i < 6; ++i) {
      if (report.keys[i] == 0x00) {
        report.keys[i] = key;
        break;
      }
    }

    if (i == 6) {
      return false;
    }
  }

  return true;
}

int RubberJogi::getInterface(uint8_t *interfaceCount) {
  *interfaceCount += NUM_INTERFACES;
  HIDDescriptor interfaces[NUM_INTERFACES] = {
      {D_INTERFACE(_keyboardInterface(), 1, USB_DEVICE_CLASS_HUMAN_INTERFACE,
                   HID_SUBCLASS_BOOT_INTERFACE, HID_PROTOCOL_KEYBOARD),
       D_HIDREPORT(keyboardReportDescriptorSize),
       D_ENDPOINT(USB_ENDPOINT_IN(_keyboardEndpoint()),
                  USB_ENDPOINT_TYPE_INTERRUPT, USB_EP_SIZE, 0x01)},
      {D_INTERFACE(_mouseInterface(), 1, USB_DEVICE_CLASS_HUMAN_INTERFACE,
                   HID_SUBCLASS_BOOT_INTERFACE, HID_PROTOCOL_MOUSE),
       D_HIDREPORT(mouseReportDescriptorSize),
       D_ENDPOINT(USB_ENDPOINT_IN(_mouseEndpoint()),
                  USB_ENDPOINT_TYPE_INTERRUPT, USB_EP_SIZE, 0x01)}};

  return USB_SendControl(0, interfaces, sizeof(interfaces));
}

int RubberJogi::getDescriptor(USBSetup &setup) {
  if (setup.bmRequestType != REQUEST_DEVICETOHOST_STANDARD_INTERFACE) {
    return 0;
  }

  if (setup.wValueH != HID_REPORT_DESCRIPTOR_TYPE) {
    return 0;
  }

  // In a HID Class Descriptor wIndex contains the interface number
  if (setup.wIndex == _keyboardInterface()) {
    return USB_SendControl(TRANSFER_PGM, keyboardReportDescriptor,
                           keyboardReportDescriptorSize);
  } else if (setup.wIndex == _mouseInterface()) {
    return USB_SendControl(TRANSFER_PGM, mouseReportDescriptor,
                           mouseReportDescriptorSize);
  } else {
    return 0;
  }

  // Reset the protocol on reenumeration. Normally the host should not assume
  // the state of the protocol due to the USB specs, but Windows and Linux just
  // assumes its in report mode.
  // protocol = HID_REPORT_PROTOCOL;
}

uint8_t RubberJogi::getShortName(char *name) {
  memcpy(name, VERSION, strlen(VERSION));
  return strlen(VERSION);
}

bool RubberJogi::setup(USBSetup &setup) {
  if (setup.wIndex != _keyboardInterface() &&
      setup.wIndex != _mouseInterface()) {
    return false;
  }

  uint8_t request = setup.bRequest;
  uint8_t requestType = setup.bmRequestType;

  if (requestType == REQUEST_DEVICETOHOST_CLASS_INTERFACE) {
    if (request == HID_GET_REPORT) {
      // TODO: HID_GetReport();
      return true;
    }
    if (request == HID_GET_PROTOCOL) {
      // TODO: Send8(protocol);
      return true;
    }
    if (request == HID_GET_IDLE) {
      // TODO: Send8(idle);
      return true;
    }
  }

  if (requestType == REQUEST_HOSTTODEVICE_CLASS_INTERFACE) {
    if (request == HID_SET_PROTOCOL) {
      // The USB Host tells us if we are in boot or report mode.
      // This only works with a real boot compatible device.
      // protocol = setup.wValueL;
      return true;
    }

    if (request == HID_SET_IDLE) {
      // idle = setup.wValueL;
      return true;
    }

    if (request == HID_SET_REPORT) {
      // uint16_t length = setup.wLength;
      // uint8_t data[length];
      //// Make sure to not read more data than USB_EP_SIZE.
      //// You can read multiple times through a loop.
      //// The first byte (may!) contain the reportID on a multreport.
      // USB_RecvControl(data, length);

      // NOTE: Don't return true here or the USB stack get's stuck!
    }
  }

  return false;
}

uint8_t RubberJogi::_keyboardInterface() const {
  return pluggedInterface + KEYBOARD_OFFSET;
}

uint8_t RubberJogi::_keyboardEndpoint() const {
  return pluggedEndpoint + KEYBOARD_OFFSET;
}

uint8_t RubberJogi::_mouseInterface() const {
  return pluggedInterface + MOUSE_OFFSET;
}

uint8_t RubberJogi::_mouseEndpoint() const {
  return pluggedEndpoint + MOUSE_OFFSET;
}
