#include "STC8G1K08.h"

void ADC_Init(void)
{
    P1ASF = 0x01;       // 使能 P1.0 的模拟功能
    ADC_RES = 0;        // 清除结果寄存器
    ADC_RESL = 0;
    ADC_CONTR = 0x80;   // ADC 电源开启
    Delay(2);           // 延时等稳定（如 Delay_ms(2)）
}

unsigned int ADC_Read(unsigned char ch)
{
    ADC_CONTR = 0x88 | ch;  // 启动转换，选择通道
    _nop_(); _nop_();       // 少量等待
    while (!(ADC_CONTR & 0x10));  // 等待完成标志
    ADC_CONTR &= ~0x10;     // 清除完成标志
    return ((ADC_RES << 2) | (ADC_RESL & 0x03)); // 返回10位ADC结果
}
