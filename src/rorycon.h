#ifndef RORYCON_H
#define RORYCON_H

class rorycon {
   private:
    unsigned long time_ms_old; // 前回時間（速度算出用）
    unsigned long time_ms_new; // 現在時間（速度算出用）

    int pinA_num;
    int pinB_num;
    int count_max;
    float radian;

   public:
    /// ロータリーエンコーダ（パルスカウンタ）のセットアップ
	/// @param pinA A相のピン番号
    /// @param pinB B相のピン番号
    /// @param reso 分解能（白と黒が一列に合計何個並んでるか）
    void setup(int pinA, int pinB, int reso);

    void count_start();
    void count_stop();

    /// 角度（ラジアン）の読み取り
	/// @returns 角度(rad)
    float rad();

    /// 角度（度）の読み取り
	/// @returns 角度(deg)
    float deg();

    /// 角速度（ラジアン毎秒）の読み取り
	/// @returns 角速度(rad/s)
    float rps_rad();

    /// 角速度（deg/s）の読み取り
	/// @returns 角速度(deg/s)
    float rps_deg();
};

#endif