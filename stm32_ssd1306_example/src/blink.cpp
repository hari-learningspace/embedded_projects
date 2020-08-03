#include "mbed.h"
#include "Adafruit_SSD1306.h"

DigitalOut myled(LED1);

// an I2C sub-class that provides a constructed default
class I2CPreInit : public I2C
{
public:
    I2CPreInit(PinName sda, PinName scl) : I2C(sda, scl)
    {
        frequency(400000);
        start();
    };
};

I2CPreInit gI2C(I2C_SDA,I2C_SCL);
Adafruit_SSD1306_I2c gOled2(gI2C,NC);
 
int main()
{   uint16_t x=0;
 
    gOled2.printf("%ux%u OLED Display\r\n", gOled2.width(), gOled2.height());
    
    while(1)
    {
        myled = !myled;
        gOled2.printf("%u\r",x);
        gOled2.display();
        x++;
        wait(1.0);
    }
}