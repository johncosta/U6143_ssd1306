# U6143_ssd1306

##  I2C
Begin by enabling the I2C interface:

```bash
sudo raspi-config
```

Choose `Interface Options` | `I2C`, then answer `Yes` to whether you would like the ARM I2C interface to be enabled.

Install Git and library dependencies

```bash
sudo apt update
sudo apt install git wiringpi
```

##  Clone U6143_ssd1306 library 
```bash
git clone https://github.com/UCTRONICS/U6143_ssd1306.git
```

## Compile 
```bash
cd U6143_ssd1306/C
```
```bash
make clean && make 
```

## Run 
```
sudo ./display
```

## Add automatic start script
Copy the binary file to `/usr/local/bin/`:

```bash
sudo cp ./display /usr/local/bin/
```

Choose one of the following configuration options (`systemd` **or** `rc.local`):
 
```bash
sudo cp ./contrib/U6143_ssd1306.service /etc/systemd/system/
sudo systemctl daemon-reload
sudo systemctl enable U6143_ssd1306.service
sudo systemctl start U6143_ssd1306.service
```

**OR** add the startup command to the `rc.local` script (not recommended)

```bash
sudo nano /etc/rc.local
```

## Custom display temperature type 
- Open the U6143_ssd1306/C/ssd1306_i2c.h file. You can modify the value of the TEMPERATURE_TYPE variable to change the type of temperature displayed. (The default is Fahrenheit)
![EasyBehavior](https://github.com/UCTRONICS/pic/blob/master/OLED/select_temperature.jpg)

```bash
/usr/local/bin/display &
```

## Custom display IPADDRESS_TYPE type 
- Open the U6143_ssd1306/C/ssd1306_i2c.h file. You can modify the value of the IPADDRESS_TYPE variable to change the type of IP displayed. (The default is ETH0)
![EasyBehavior](https://github.com/UCTRONICS/pic/blob/master/OLED/select_ip.jpg)

## Custom display information 
- Open the U6143_ssd1306/C/ssd1306_i2c.h file. You can modify the value of the IP_SWITCH variable to determine whether to display the IP address or custom information. (The custom IP address is displayed by default)
![EasyBehavior](https://github.com/UCTRONICS/pic/blob/master/OLED/custom_display.jpg)

Install the dependent library files:

```bash
sudo apt update
sudo apt install python3-pil python3-pip
sudo pip3 install adafruit-circuitpython-ssd1306
```

Test demo:

```bash 
cd U6143_ssd1306/python 
sudo python3 ssd1306_stats.py
```
