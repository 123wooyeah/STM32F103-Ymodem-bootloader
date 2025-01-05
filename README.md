# STM32F103-Ymodem-bootloader
基于Ymodem协议串口实现IAP
待完善，目前只实现两个分区，bootloader和一个APP区，在
APP区运行时接收串口指令，写入flash更新标志，软复位重启
到bootloader，读取更新标志，更新完后擦掉标志