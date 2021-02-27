file "dualMoco.hex" do
  sh "curl -O https://github.com/kuwatay/mocolufa/raw/master/HEX/dualMoco.hex"
end

namespace :usb do
  task :default do
    hex = "/Applications/Arduino.app/Contents/Java/hardware/arduino/avr/firmwares/atmegaxxu2/arduino-usbserial/Arduino-usbserial-atmega16u2-Uno-Rev3.hex"
    sh "dfu-programmer atmega16u2 erase"
    sh "dfu-programmer atmega16u2 flash #{hex}"
    sh "dfu-programmer atmega16u2 reset"
  end

  task :dualmoco => "dualMoco.hex" do
    hex = "dualMoco.hex"
    sh "dfu-programmer atmega16u2 erase"
    sh "dfu-programmer atmega16u2 flash #{hex}"
    sh "dfu-programmer atmega16u2 reset"
  end
end
