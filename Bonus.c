void UART_SendByte(unsigned char dat)
{
    SBUF = dat;
    while (!TI);
    TI = 0;
}

void main(void)
{
    UART_Init();
    while(1) {
        UART_SendByte('A'); // 每次发送字符 A
        Delay_ms(500);
    }
}
