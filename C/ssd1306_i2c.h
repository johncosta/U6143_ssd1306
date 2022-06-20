/*********************************************************************
*This is UCTRONICS ssd1306 library header file;
This library just support 128X32 lcd with i2c interface;
*********************************************************************/
#ifndef SSD1306_I2C_H_
#define SSD1306_I2C_H_

extern int i2cd;

/**********Select display temperature type**************/
#define CELSIUS       0
#define FAHRENHEIT    1
#define TEMPERATURE_TYPE  FAHRENHEIT
/**********Select display temperature type**************/

/**********Select display network IP type**************/
#define ETH0_ADDRESS    0
#define WLAN0_ADDRESS   1
#define IPADDRESS_TYPE  ETH0_ADDRESS
/**********Select display network IP type**************/


/************************Turn off the IP display. Can customize the display****************/
#define IP_DISPLAY_OPEN     0
#define IP_DISPLAY_CLOSE    1
#define IP_SWITCH       IP_DISPLAY_OPEN
#define CUSTOM_DISPLAY   "UCTRONICS"
/************************Turn off the IP display. Can customize the display****************/

#define BLACK 0
#define WHITE 1
#define INVERSE 2

#define OLED_CMD  0	                 //command
#define OLED_DATA 1	                //data
#define SSD1306_I2C_ADDRESS   0x3C	// 011110+SA0+RW - 0x0C    
//#define SSD1306_SWITCHCAPVCC 0x2

#define SSD1306_LCDWIDTH                  128
#define SSD1306_LCDHEIGHT                 32
int setup(unsigned char [20], unsigned int);
int ssd1306_begin(char [20], unsigned int switchvcc, unsigned int i2caddr); //switchvcc should be SSD1306_SWITCHCAPVCC
void OLED_ShowString(unsigned char x,unsigned char y, unsigned char *p,unsigned char Char_Size);
void OLED_ShowChar(unsigned char x,unsigned char y,unsigned char chr,unsigned char Char_Size);
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_WR_Byte(unsigned dat,unsigned cmd);  
void Write_IIC_Data(unsigned char IIC_Data);
void Write_IIC_Command(unsigned char IIC_Command);
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[][512],unsigned char);
void OLED_DrawPartBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[][512],unsigned char);
void OLED_Clear(void);
void OLED_ClearLint(unsigned char,unsigned char);
void OLED_ShowNum(unsigned char,unsigned char,unsigned int,unsigned char,unsigned char);
unsigned int oled_pow(unsigned char,unsigned char);
void LCD_Display(unsigned char symbol);
void LCD_DisPlayCpuMemory(void);
void LCD_DisplaySdMemory(void);
char* FirstGetIpAddress(void);
char* GetIpAddress(void);
unsigned char Obaintemperature(void);

///**
// * @brief Inits 128x32 OLED display over i2c (based on SSD1306 controller).
// *
// * Inits 128x32 OLED display over i2c (based on SSD1306 controller)
// * This function uses hardcoded pins for i2c communication, depending on your hardware.
// * If you use non-standard pins in your project, please perform call ssd1306_i2cInitEx() and
// * ssd1306_128x32_init().
// */
//void         ssd1306_128x32_i2c_init(void);
//
///**
// * @brief Inits 128x32 OLED display (based on ssd1306 controller).
// *
// * Inits 128x32 OLED display (based on ssd1306 controller)
// * spi or i2c bus must be initialized prior to calling this function.
// * @see ssd1306_i2cInit()
// * @see ssd1306_spiInit()
// */
//void         ssd1306_128x32_init(void);
//
///**
// * Turns off display
// */
//void         ssd1306_displayOff(void);
//
///**
// * Turns on display
// */
//void         ssd1306_displayOn(void);
//
///**
// * Set display contrast, ie light intensity
// * @param contrast - contrast value to see, refer to ssd1306 datasheet
// */
//void         ssd1306_setContrast(uint8_t contrast);
//
///**
// * Switches display to inverse mode.
// * LCD will display 0-pixels as white, and 1-pixels as black.
// * @note Not supported for SSD1331
// */
//void         ssd1306_invertMode(void);
//
///**
// * Switches display to normal mode.
// * @note Not supported for SSD1331
// */
//void         ssd1306_normalMode(void);
//
///**
// * @brief performs horizontal flip
// *
// * Performs horizontal flip. If you need to turn display by 180 degree,
// * please use both ssd1306_flipHorizontal() and ssd1306_flipVertical().
// *
// * @param mode - 0 to disable horizontal flip
// *               1 to enable horizontal flip
// */
//void         ssd1306_flipHorizontal(uint8_t mode);
//
///**
// * @brief performs vertical flip
// *
// * Performs vertical flip. If you need to turn display by 180 degree,
// * please use both ssd1306_flipHorizontal() and ssd1306_flipVertical().
// *
// * @param mode - 0 to disable vertical flip
// *               1 to enable vertical flip
// */
//void         ssd1306_flipVertical(uint8_t mode);
//
///**
// * Sets start line in gdram to start display content with
// *
// * @param line start line in range 0 - 63
// */
//void ssd1306_setStartLine(uint8_t line);
//
///**
// * returns start line in gdram.
// */
//uint8_t ssd1306_getStartLine(void);
//
///**
// * @}
// */
//
//#ifdef __cplusplus
//}
//#endif
#endif				/* SSD1306_I2C_H_ */
