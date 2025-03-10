#include "GEN_SPI_Service_DATA_CFG.h"

SPI_Service_SpiCfg_t SPI_Service_SpiHwCfg_data[SPI_Service_SPI_Service_SPIs_Count];

inline void SPI_Service_SpiHwCfg_data_INIT_FUNC(void)
{
	SPI_Service_SpiHwCfg_data[0].id = SPI_Service_SPI_0_Id;
	SPI_Service_SpiHwCfg_data[0].spiMode = SPI_Service_SPI_0_SpiMode;
	SPI_Service_SpiHwCfg_data[0].spiRxBuffer = NULL;
	SPI_Service_SpiHwCfg_data[0].spiRxBufferSize = SPI_Service_SPI_0_SpiRxBufferSize;
	SPI_Service_SpiHwCfg_data[0].status = RET_NOT_OK;
}