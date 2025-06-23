#define SDA P1_2
#define SCL P1_3

void I2C_Delay(void)
{
    unsigned char i;
    i = 20;
    while(i--);
}

void I2C_Start(void)
{
    SDA = 1;
    SCL = 1;
    I2C_Delay();
    SDA = 0;
    I2C_Delay();
    SCL = 0;
}

void I2C_Stop(void)
{
    SDA = 0;
    SCL = 1;
    I2C_Delay();
    SDA = 1;
    I2C_Delay();
}

bit I2C_WriteByte(unsigned char dat)
{
    unsigned char i;
    bit ack;
    for(i=0;i<8;i++) {
        SDA = dat & 0x80;
        dat <<= 1;
        SCL = 1;
        I2C_Delay();
        SCL = 0;
        I2C_Delay();
    }
    SDA = 1;        // 释放 SDA 以读取ACK
    SCL = 1;
    I2C_Delay();
    ack = SDA;      // 读ACK
    SCL = 0;
    I2C_Delay();
    return !ack;    // 返回 1 表示收到ACK
}
