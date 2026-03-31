#ifndef RORYCON_H
#define RORYCON_H

#include "driver/pcnt.h"

class rorycon {
   private:
    unsigned long time_ms_old; // 前回時間（速度算出用）
    unsigned long time_ms_new; // 現在時間（速度算出用）

    int pinA_num; // A相のピン番号
    int pinB_num; // B相のピン番号
    int count_max; // 最高カウント数
    float radian; // 現在角度（rad）
    float radian_old; // 前回角度(rad)

    pcnt_config_t pcnt_config1 = {};
    pcnt_config_t pcnt_config2 = {};

   public:
    /// ロータリーエンコーダ（パルスカウンタ）のセットアップ
	/// @param pinA A相のピン番号
    /// @param pinB B相のピン番号
    /// @param reso 分解能（白と黒が一列に合計何個並んでるか）
    /// @param unit パルスカウンタのユニット(デフォルト:0)
    void setup(int pinA, int pinB, int reso, int unit = 0);

    void count_start();
    void count_stop();

    /// 角度（ラジアン）の読み取り
	/// @returns 角度(rad)
    double rad();

    /// 角度（度）の読み取り
	/// @returns 角度(deg)
    double deg();

    /// 角速度（ラジアン毎秒）の読み取り
	/// @returns 角速度(rad/s)
    double rps_rad();

    /// 角速度（deg/s）の読み取り
	/// @returns 角速度(deg/s)
    double rps_deg();
};

#endif