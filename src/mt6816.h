#ifndef MT6816_H
#define MT6816_H

#include <SPI.h>

static SPISettings MT6816SPISettings(1000000, MSBFIRST, SPI_MODE3);

class MT6816{
   private:
    int nCS = -1;
    bool errorFlag = false;
    bool no_magnetic_reading = false;
    uint16_t position;
    uint16_t position_old;
    unsigned long time;
    unsigned long time_old;

    SPIClass* spi;
    SPISettings settings;

	/// SPI通信で読み取り
	/// @param registerAddress 16bitレジスタアドレス 
	/// @returns 16bitレジスタ値
	uint16_t read(uint16_t registerAddress);

    /// SPI通信で書き込み
	/// @param registerAddress 16bitレジスタアドレス 
    /// @param data 16bit書き込みデータ
	/// @returns 16bitレジスタ値
	uint16_t write(uint16_t registerAddress, uint16_t data);

	/// パリティチェック
	bool parityCheck(uint16_t data);

   public:
	MT6816(SPISettings settings = MT6816SPISettings, int nCS = -1);
    virtual ~MT6816();

    virtual void init(SPIClass* _spi = &SPI);

	/// AngleDataRegisterのRAWデータ
	uint16_t readRawAngle();

	/// 角度データ（Deg）
	/// @return 0~360°
	double getRotation_Deg();

	/// 角度データ（Rad）
	/// @return 0~2π
	double getRotation_Rad();

    /// 角速度データ（Deg/s）
    /// 角度の新規取得は行わないので注意
	/// @return deg/s
	double RPS_Deg();

	/// 角速度データ（Rad/s）
    /// 角度の新規取得は行わないので注意
	/// @return rad/s
	double RPS_Rad();

	bool isNoMagneticReading() {
        return no_magnetic_reading;
    }
};

#endif