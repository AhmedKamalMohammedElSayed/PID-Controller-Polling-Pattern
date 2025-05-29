#ifndef SPI_H
#define SPI_H

void SPI_MasterInit(void);
void SPI_MasterTransmit(char data);
char SPI_MasterReceive(void);

#endif
