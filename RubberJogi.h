#ifndef RUBBER_JOGI_H
#define RUBBER_JOGI_H

#include "HIDDescriptor.h"
#include "KeyboardLayout.h"
#include <Arduino.h>
#include <PluggableUSB.h>

class RubberJogi : public PluggableUSBModule {
public:
  RubberJogi();
  void printVersion() const;
  bool readCommand();
  const String &getCommand() const;
  void parseCommand();
  void sendKey(uint8_t key) const;
  void pressKeys(const KeyReport &keys) const;
  void releaseKeys() const;
  void pressButtons(const MouseReport &buttons) const;
  void releaseButtons() const;
  void setKeyboardLayout(const uint8_t *layout);

  static constexpr const char *VERSION = "RubberJogi V1.4";

protected:
  int getInterface(uint8_t *interfaceCount) override;
  int getDescriptor(USBSetup &setup) override;
  bool setup(USBSetup &setup) override;
  uint8_t getShortName(char *name) override;

private:
  void _initSwitches() const;
  void _printComment(const String &cmd) const;
  void _executeKeyboardCommand(String cmd) const;
  void _executeMouseCommand(String cmd) const;
  void _executeDelayCommand(const String &cmd) const;
  void _executeSwitchCommand(String cmd) const;
  bool _addKeyToReport(uint8_t key, KeyReport &report) const;
  int _getPin(const String &name) const;

  uint8_t _keyboardInterface() const;
  uint8_t _keyboardEndpoint() const;
  uint8_t _mouseInterface() const;
  uint8_t _mouseEndpoint() const;

  static constexpr int NUM_INTERFACES = 2;
  static constexpr int NUM_ENDPOINTS = 2;
  static constexpr int KEYBOARD_OFFSET = 0;
  static constexpr int MOUSE_OFFSET = 1;

  uint8_t _epType[NUM_ENDPOINTS];
  String _buffer;
  const uint8_t *_layout = KeyboardLayout_en_US;
};

#endif
